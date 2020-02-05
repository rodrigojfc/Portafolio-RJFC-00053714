#include <iostream>
using namespace std;

void buscarRecursivo(int *array, int aux, int num);

int main(void){
    int myArray[] = {1,3,4,5,17,18,31,33};


    int num = 0;
    cout<<"Ingrese numero a buscar: "; cin >> num; cin.ignore();

    buscarRecursivo(myArray, 0, num);


return 0;
}

void buscarRecursivo(int *array, int aux, int num){
    if (num == array[aux])
        cout << "Elemento encontrado!!\n";
    
    else 
        buscarRecursivo(array, aux+1, num);
}