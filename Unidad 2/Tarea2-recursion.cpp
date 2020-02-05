#include <iostream>
using namespace std;


void buscar(int *array, int inicio,int fin, int num);

int main(void){
    int myArray[] = {1,3,4,5,17,18,31,33};


    int num = 0;
    cout<<"Ingrese numero a buscar: "; cin >> num; cin.ignore();

   buscar(myArray, 0, 7, num);


return 0;

}

void buscar(int *array, int inicio,int fin, int num)
{
int mitad=(inicio+fin)/2;
if(num==array[mitad])
    cout<<"Numero "<<array[mitad]<<" encontrado" << endl;
else{
    if(num<array[mitad])
     buscar(array, inicio, mitad, num);
        else{
            if(num>array[mitad]){
            inicio = mitad+1;
            mitad = (inicio + fin)/2; 

            buscar(array, inicio, mitad, num);
            }
            else
             cout<<" Numero no encontrado =(";

}

}
    
}