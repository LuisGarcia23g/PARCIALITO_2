#include <iostream>

const int MAX_TAMANO_NOMBRE = 50;
const int MAX_MIEMBROS = 100;
const int MAX_CLUBS = 10;

struct Miembros {
    char first_name [MAX_TAMANO_NOMBRE];
    char last_name [MAX_TAMANO_NOMBRE];
    int age;
};

struct Club {
    char name [MAX_TAMANO_NOMBRE];
    char creation_date [MAX_TAMANO_NOMBRE];
    int max_capacity;
    Miembros miembros [MAX_MIEMBROS];
    int num_miembros = 0;
};

//Funciones
void Menu();
void CreateClub(Club& club);
void ListClubs(const Club clubs[],int num_clubs);
void RegisterMember(Club& club);
void ListMembers(const Club& club);
void TotalMembers(const Club& club);

int main(){
    
    Menu();
   
    return 0;
}

void Menu(){
    Club clubs[MAX_CLUBS];
    int num_clubs = 0;
    int opcion = 0;
    do
    {
        std::cout << "\n--- Menu de Gestion de Clubes ---" << std::endl;
        std::cout << "1. Crear Club" << std::endl;
        std::cout << "2. Listar Clubes" << std::endl;
        std::cout << "3. Registrar Miembro" << std::endl;
        std::cout << "4. Listar Miembros" << std::endl;
        std::cout << "5. Total de Miembros" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); 

        switch (opcion)
        {
        case 1:
            if (num_clubs < MAX_CLUBS)
            {
                CreateClub(clubs[num_clubs++]);
            }else {
                std:: cout << "No se pueden crear mas clubs.";
            };
        break;

        case 2:
        ListClubs(clubs, num_clubs);
        break;

        case 3:
        int club_index;
                std::cout << "Ingrese el numero del club para registrar un miembro: ";
                std::cin >> club_index;
                std::cin.ignore(); // Limpiar el buffer
                if (club_index > 0 && club_index <= num_clubs) {
                    RegisterMember(clubs[club_index - 1]);
                } else {
                    std::cout << "Club invalido." << std::endl;
                }
        break;

        case 4: {
        int club_index;
                std::cout << "Ingrese el numero del club para listar sus miembros: ";
                std::cin >> club_index;
                std::cin.ignore(); // Limpiar el buffer
                if (club_index > 0 && club_index <= num_clubs) {
                    ListMembers(clubs[club_index - 1]);
                } else {
                    std::cout << "Indice de club invalido." << std::endl;
                }
        break;
        }

        case 5: {
        int club_index;
                std::cout << "Ingrese el numero del club para obtener el total de miembros: ";
                std::cin >> club_index;
                std::cin.ignore(); // Limpiar el buffer
                if (club_index > 0 && club_index <= num_clubs) {
                    TotalMembers(clubs[club_index - 1]);
                } else {
                    std::cout << "Indice de club invalido." << std::endl;
                }
        break;
        }
        case 6:
            std::cout << "Saliendo del programa." << std::endl;
        break;
        
        default:
            std::cout << "Opcion no valida." << std::endl;
            break;
        }
    
     } while (opcion != 6);
}


void CreateClub(Club& club){
    std::cout << "Escribe el nombre del club: ";
    std::cin.getline(club.name, MAX_TAMANO_NOMBRE);
    std::cout << "Ingrese la fecha de creacion del club: ";
    std::cin.getline(club.creation_date, MAX_TAMANO_NOMBRE);
    std::cout << "Ingresa la capacidad maxima del club: ";
    std::cin >> club.max_capacity;
    std::cin.ignore();
    club.num_miembros = 0;
    std:: cout << "Club creado." << std:: endl;
}


void ListClubs(const Club clubs[],int num_clubs){
    if (num_clubs == 0)
    {
        std::cout << "No hay clubs registrados";
        return;
    }
    std::cout << "Clubs registrados:" << std:: endl;
    for (int i = 0; i < num_clubs; i++)
    {
        std::cout << i + 1 << ". " << clubs[i].name << std:: endl;
        std::cout << "Creado el: " << clubs[i].creation_date << std:: endl;
        std::cout << "Capacidad: " << clubs[i].max_capacity << std:: endl;
    }
}


void RegisterMember(Club& club){
    if (club.num_miembros >= club.max_capacity)
    {
        std::cout << "El club ha alcanzado su capacidad maxima." << std::endl;
        return;
    }
    
    Miembros& nuevo_miembro = club.miembros[club.num_miembros];
    std::cout << "Ingrese el nombre del miembro: ";
    std::cin.getline(nuevo_miembro.first_name, MAX_TAMANO_NOMBRE);
    std::cout << "Ingrese el apellido del miembro: ";
    std::cin.getline(nuevo_miembro.last_name, MAX_TAMANO_NOMBRE);
    std::cout << "Ingrese la edad del miembro: ";
    std::cin >> nuevo_miembro.age;
    std::cin.ignore(); // Limpiar el buffer

    club.num_miembros++;
    std::cout << "Miembro registrado." << std::endl;
}


void ListMembers(const Club& club){
        if (club.num_miembros == 0) {
        std::cout << "No hay miembros registrados en este club." << std::endl;
        return;
    }

    std::cout << "Miembros en el club " << club.name << ":" << std::endl;
    for (int i = 0; i < club.num_miembros; ++i) {
        std::cout << "- " << club.miembros[i].first_name << " " << club.miembros[i].last_name 
                  << " (Edad: " << club.miembros[i].age << ")" << std::endl;
}
}


void TotalMembers(const Club& club){
    std::cout << "Total de miembros en el club " << club.name << ": "
              << club.num_miembros << std::endl;
}