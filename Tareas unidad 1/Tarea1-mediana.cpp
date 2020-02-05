#include <iostream>
#include <algorithm>
using namespace std;

float mediana(int *miMatriz, int num);

int main(void){
    int num = 0;
    int myMatriz[num];
    int number;
    float mdiana = 0;

    cout <<"Ingrese la cantidad de numeros: "; cin >> num; cin.ignore();
    cout << "\nIngrese los digitos de menor a mayor:\n";
    for(int i = 0; i < num; i++){
        cin >> number;
        myMatriz[i] = number;
    }

    mdiana = mediana(myMatriz, num);
    cout << "La mediana es: " << mdiana << endl;

    return 0;
}

float mediana(int *miMatriz, int num){
    float mediana = 0;
        if (num%2 == 0){
            mediana = miMatriz[num/2] + miMatriz[(num/2) - 1];
            mediana = mediana/2;

    }
    else{
        mediana = miMatriz[num/2];
    }


    return mediana;
}