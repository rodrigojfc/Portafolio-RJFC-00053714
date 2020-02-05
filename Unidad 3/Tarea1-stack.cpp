#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Ordenar apilar libros

struct Libro{
    string nombre;
    string autor;
    int FechaLanzamiento;
};

int main(void){
    Libro unLibro;
    stack<Libro> myStack;
    int option = 0;
    do{
        cout<<"1- Ingresar nuevo libro\n";
        cout<<"0- Salir\n";
        cout <<"Su eleccion:\t"; cin >> option; cin.ignore();
        switch (option)
        {
        case 1:
            cout<<"Ingrese nombre del libro: "; getline(cin, unLibro.nombre);
            cout<<"Ingrese autor del libro: "; getline(cin, unLibro.autor);
            cout<<"Ingrese fecha de lanzamieno: "; cin>>unLibro.FechaLanzamiento; cin.ignore();
            myStack.push(unLibro);
            break;
        
        default:
            break;
        }

    }while(option !=0);


return 0;
}