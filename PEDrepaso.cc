/*
1. git clone 
2. cd (tabulador)
3. git config --local user.name "nombre"
4. git config --local user.email "email"
5. git flow init 
6. code .
7. git flow feature start "nombre"
8. git add main.cc
9. git commit -m "feat: agregando"
10. git push origin feature "nombre"
11. git flow feature finish
12. git push origin develop 
13. git flow feature start (otra rama)
14. git pull origin develop
15. code .
16. git add main.cc
17. git commit -m "feat: agregando"
18. git push origin feature "nombre"
19. git flow feature finish
20. git push origin develop 
21. git flow release start v1.0
22. git flow release finish v1.0
23. esc i : wq!
24. git push origin main


---cuando las ramas divergen---
1. git checkout develop 
2. git pull 
3. git pull origin develop 
4. git checkout (rama en la que estamos)*/



//---PARCIAL 1---
/* #include <iostream>


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
}*/


//---LISTAS SIMPLES---
/*#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void InsertarLista(Nodo *&lista, int numero){ //Se pasa por referencia para que la lista se modifique
    Nodo *nuevo_nodo = new Nodo(); //Reservar memoria para el nuevo nodo
    Nodo *aux; //Puntero auxiliar para recorrer la lista

    nuevo_nodo->dato = numero; //Asignar el valor al nuevo nodo
    nuevo_nodo->siguiente = nullptr; //Asignar el siguiente del nuevo nodo a nullptr

    if(lista == nullptr){ //Si la lista esta vacia
        lista = nuevo_nodo; //Asignar el nuevo nodo a la lista
    }else{
        aux = lista; //Asignar el puntero auxiliar a la lista
        while(aux->siguiente != nullptr){ //Recorrer la lista para que el puntero auxiliar quede en el ultimo nodo
            aux = aux->siguiente; //Avanza al siguiente nodo
        }
        aux->siguiente = nuevo_nodo; //Cuando llega al ultimo nodo, asigna el nuevo nodo
    }

    std::cout << "Elemento " << numero << " insertado a la lista" << std::endl;

    // No debes liberar la memoria aquí
    // delete nuevo_nodo; // Esta línea debe ser eliminada
}

void MostrarLista(Nodo *lista){
   while(lista != nullptr){ //Mientras no sea el final de la lista
       std::cout << lista->dato << " -> "; //Mostrar el dato del nodo
       lista = lista->siguiente; //Avanzar al siguiente nodo
   }
   std::cout << "nullptr" << std::endl; // Para indicar el final de la lista
}

void CalcularMayorMenor(Nodo *lista){ //No se pasa por referencia porque no se modifica la lista
    if (lista == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return; // Si la lista está vacía, no hay que calcular mayor y menor
    }

    int mayor = lista->dato; // Inicializar mayor con el primer elemento
    int menor = lista->dato; // Inicializar menor con el primer elemento

    while(lista != nullptr){ //Mientras no sea el final de la lista
        if(lista->dato > mayor){ //Calculando el mayor
            mayor = lista->dato;
        }
        if(lista->dato < menor){ //Calculando el menor
            menor = lista->dato;
        }

        lista = lista->siguiente; //Avanzar al siguiente nodo
    }

    std::cout << "Mayor: " << mayor << std::endl;
    std::cout << "Menor: " << menor << std::endl;
}

int main(){
    Nodo *lista = nullptr;
    int dato;
    char respuesta;

    do{
        std::cout << "Digite un numero: ";
        std::cin >> dato;
        InsertarLista(lista, dato);  

        std::cout << "Desea agregar otro elemento a la lista? (s/n): ";
        std::cin >> respuesta;

    }while(respuesta == 's' || respuesta == 'S');

    std::cout << "Elementos de la lista: ";
    MostrarLista(lista);

    std::cout << "El mayor y menor elemento de la lista son: ";
    std::cout << std::endl;
    CalcularMayorMenor(lista);

    // Liberar la memoria de la lista al final
    while (lista != nullptr) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    return 0;
}*/


//---PILAS---
/*#include <iostream>
#include <stack>

// Función para solicitar al usuario los valores para apilar
void IngresarValores(std::stack<int>& pila) {
    int valor;
    std::cout << "Ingrese los valores para apilar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        pila.push(valor);  // Apilando el valor
    }
}

// Función para mostrar todos los elementos de la pila sin modificarla
void MostrarPila(std::stack<int> pila) {
    if (pila.empty()) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    std::cout << "Elementos en la pila: ";
    while (!pila.empty()) {
        std::cout << pila.top() << " ";  // Muestra el elemento en la cima
        pila.pop();                      // Elimina el elemento de la cima
    }
    std::cout << std::endl;
}

// Función para eliminar el elemento en la cima de la pila
void EliminarElemento(std::stack<int>& pila) {
    if (!pila.empty()) {
        std::cout << "Cima de la pila: " << pila.top() << std::endl;
        pila.pop();
        std::cout << "Se ha eliminado el elemento de la cima." << std::endl;
    } else {
        std::cout << "La pila está vacía, no hay nada que eliminar." << std::endl;
    }
}

int main() {
    std::stack<int> pila;

    // Llamar a la función para ingresar los valores
    IngresarValores(pila);

    // Llamar a la función para mostrar los valores de la pila
    std::cout << "Mostrando la pila:" << std::endl;
    MostrarPila(pila);

    // Llamar a la función para eliminar el elemento en la cima de la pila
    std::cout << "Eliminando el elemento de la cima:" << std::endl;
    EliminarElemento(pila);

    // Mostrar pila después de eliminar
    std::cout << "Mostrando la pila despues de eliminar el elemento de la cima:" << std::endl;
    MostrarPila(pila);

    return 0;
}*/

//---COLAS---
/*#include <algorithm>
#include <iostream>

int main() {
    int n;

    std::cout << "Ingrese el numero de elementos que desea ordenar: ";
    std::cin >> n;

    // Crear un arreglo dinámico
    int* arr = new int[n];

    std::cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::sort(arr, arr + n);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Liberar la memoria del arreglo dinámico
    delete[] arr;

    return 0;
}*/


//---EMOJIS---
/*
:white_check_mark: agregar, actualizar o aprobar pruebas
:bug: arreglar un error
:sparkles: introducir nuevas caracteristicas
:rocket: implementar cosas
 */
#include <iostream>
#include <cstring>

const int MAX_TAMANO_NOMBRE = 100;

struct Miembro {
    char first_name[MAX_TAMANO_NOMBRE];
    char last_name[MAX_TAMANO_NOMBRE];
    int age;
    Miembro* next; // Puntero al siguiente miembro
};

struct Club {
    char name[MAX_TAMANO_NOMBRE];
    char creation_date[MAX_TAMANO_NOMBRE];
    int max_capacity;
    Miembro* miembros; // Puntero a la lista de miembros
    Club* next; // Puntero al siguiente club
};

Club* clubs = nullptr; // Puntero a la lista de clubes


void CreateClub() {
    Club* new_club = new Club;
    std::cout << "Escribe el nombre del club: ";
    std::cin.getline(new_club->name, MAX_TAMANO_NOMBRE);
    std::cout << "Ingrese la fecha de creacion del club: ";
    std::cin.getline(new_club->creation_date, MAX_TAMANO_NOMBRE);
    std::cout << "Ingresa la capacidad maxima del club: ";
    std::cin >> new_club->max_capacity;
    std::cin.ignore();
    new_club->miembros = nullptr; // Inicializar la lista de miembros
    new_club->next = clubs; // Insertar al inicio de la lista
    clubs = new_club; // Actualizar el puntero de clubes
    std::cout << "Club creado." << std::endl;
}

void ListClubs() {
    if (!clubs) {
        std::cout << "No hay clubs registrados." << std::endl;
        return;
    }
    std::cout << "Clubs registrados:" << std::endl;
    Club* current = clubs;
    int index = 1;
    while (current) {
        std::cout << index++ << ". " << current->name << std::endl;
        std::cout << "Creado el: " << current->creation_date << std::endl;
        std::cout << "Capacidad: " << current->max_capacity << std::endl;
        current = current->next;
    }
}

void RegisterMember(Club* club) {
    if (!club) return;

    Miembro* new_member = new Miembro;
    std::cout << "Ingrese el nombre del miembro: ";
    std::cin.getline(new_member->first_name, MAX_TAMANO_NOMBRE);
    std::cout << "Ingrese el apellido del miembro: ";
    std::cin.getline(new_member->last_name, MAX_TAMANO_NOMBRE);
    std::cout << "Ingrese la edad del miembro: ";
    std::cin >> new_member->age;
    std::cin.ignore(); // Limpiar el buffer

    // Insertar el nuevo miembro al inicio de la lista de miembros
    new_member->next = club->miembros;
    club->miembros = new_member;

    std::cout << "Miembro registrado." << std::endl;
}

void ListMembers(Club* club) {
    if (!club || !club->miembros) {
        std::cout << "No hay miembros registrados en este club." << std::endl;
        return;
    }

    std::cout << "Miembros en el club " << club->name << ":" << std::endl;
    Miembro* current = club->miembros;
    while (current) {
        std::cout << "- " << current->first_name << " " << current->last_name 
                  << " (Edad: " << current->age << ")" << std::endl;
        current = current->next;
    }
}

void TotalMembers(Club* club) {
    if (!club) return;

    int count = 0;
    Miembro* current = club->miembros;
    while (current) {
        count++;
        current = current->next;
    }
    std::cout << "Total de miembros en el club " << club->name << ": " << count << std::endl;
}


