/*
**********STRUCT ANIDADOS***************

#include <iostream>
struct Info_Direccion{
    std::string direccion;
    std::string ciudad;
    std::string departamento;
};

struct Empleado{
    std::string nombre;
    struct Info_Direccion direccion;
    float salario;
}empleado[2];


int main(int argc, char *argv[]){
for (int i = 0; i < 2; i++)
{
 fflush(stdin);
    std::cout<<"digite su nombre: ";
    std::getline(std::cin,empleado[i].nombre);
    std::cout<<"digite su direccion: ";
    std::getline(std::cin,empleado[i].direccion.direccion);
    std::cout<<"digite su ciudad: ";
    std::getline(std::cin,empleado[i].direccion.ciudad);
    std::cout<<"digite su departamento: ";
    std::getline(std::cin,empleado[i].direccion.departamento);
    std::cout<<"digite su salario: ";
    std::cin>>empleado[i].salario;
   
}
for (int i = 0; i < 2; i++)
{
    std::cout<<"el nombre es:"<<empleado[i].nombre<<"\n";
    std::cout<<"la direccion  es:"<<empleado[i].direccion.direccion<<"\n";
    std::cout<<"la ciudad es:"<<empleado[i].direccion.ciudad<<"\n";
    std::cout<<"el departamento es:"<<empleado[i].direccion.departamento<<"\n";
    std::cout<<"el salario es:"<<empleado[i].salario<<"\n";
}
    return 0;
}
*/

/*
*********STRUCT CON N ELEMENTOS**************
#include <iostream>
#include <string>
struct Corredor{
std::string nombre;    
int edad;    
std::string sexo;    
std::string club;    
};

const int numero_de_corredor=100;
Corredor corredor[numero_de_corredor];

int main(int argc, char *argv[]){

int numero_corredores;
std::cout<<"ingrese el numero de corredores: ";
std::cin>>numero_corredores;
if (numero_corredores>numero_de_corredor)
{
    std::cout<<"haz alcazado el numero maximo de corredores";

}
   std::cin.ignore();
for (int i = 0; i <numero_corredores; i++)
{
    std::cout<<"ingrese el nombre: ""\n";
    std::getline(std::cin,corredor[i].nombre);
    std::cout<<"ingrese su edad: "<<"\n";
    std::cin>>corredor[i].edad;
    std::cin.ignore();
    std::cout<<"ingrese el sexo: "<<"\n";
    std::getline(std::cin,corredor[i].sexo);
    std::cout<<"ingrese el club: "<<"\n";
    std::getline(std::cin,corredor[i].club);
}


for (int i = 0; i <numero_corredores; i++)
{
    std::cout<<"el nombre del corredor es:"<<corredor[i].nombre<<"\n";
    std::cout<<"la edad del corredor es:"<<corredor[i].edad<<"\n";
    std::cout<<"el sexo del corredor es:"<<corredor[i].sexo<<"\n";
    std::cout<<"el club del corredor es:"<<corredor[i].club<<"\n";
if (corredor[i].edad<=18)
{
std::cout<<"su categoria es juvenil""\n";
}else if (corredor[i].edad<=40)
{
std::cout<<"su categoria es senior""\n";   
}
std::cout<<"su categoria es veterano""\n";   
std::cout << "------------------------\n";
}

    return 0;
}
*/

/*
********OTRA FORMA DE STRUCT CON ARREGLO**********
#include <iostream>
struct Empleado{
    std::string nombre;
    int salario;
}empleado[100];



int main(int argc, char *argv[]){
int empleados;
int emayor=0,emenor=0;
float mayor=0, menor=999999;

std::cout<<"cuantos empleados son en tu empresa: ";
std::cin>>empleados;

for (int i = 0; i < empleados; i++)
{
    std::cin.ignore();
    std::cout<<i+1<<" cual es tu nombre:""\n";
    std::getline(std::cin,empleado[i].nombre);
    std::cout<<i+1<<"cual en tu salario""\n";
    std::cin>>empleado[i].salario;
    


if (empleado[i].salario>mayor)
{
    mayor=empleado[i].salario;
    emayor=i;
}
if (empleado[i].salario<menor)
{
    menor=empleado[i].salario;
    emenor=i;
}
}
std::cout<<"el empleado que tiene mayor salario es el "<<empleado[emayor].nombre<<"-----"<<empleado[emayor].salario<<"\n";
std::cout<<"el empleado que tiene menor salario es el "<<empleado[emenor].nombre<<"-----"<<empleado[emenor].salario<<"\n";

    return 0;
}
*/

/*
***punteros void*****
#include <iostream>

void Ingreso_datos(int &a, int &b);
int Multiplicacion(int a,int b);


int main(int argc, char *argv[]){
int a,b;  
Ingreso_datos(a,b);   
int resultado = Multiplicacion(a,b);
std::cout<<"el resultado es "<<resultado;

    return 0;   
}


void Ingreso_datos(int &a, int &b){
    std::cout<<"ingrese un numero para multiplicar: ""\n";
    std::cin>>a;
    std::cout<<"ingrese un numero otro multiplicar: ""\n";
    std::cin>>b;
}

int Multiplicacion(int a, int b){
    
    return a *b;
}
*/