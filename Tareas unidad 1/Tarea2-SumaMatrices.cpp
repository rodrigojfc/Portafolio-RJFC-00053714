#include <iostream>
using namespace std;

void suma_matrices(int *matrizA, int *matrizB,int filas, int cols);

int main(void){
    int colum = 0, filas = 0, number = 0;

    cout <<"Ingrese el numero de filas: "; cin >> filas; cin.ignore();
    cout <<"Ingrese el numero de columnas: "; cin>> colum; cin.ignore();
    
    int matriz1[filas][colum], mymatriz2[filas][colum];



    cout << "Ingrese digitos para la primer matriz:\n"; 


    for(int i = 0; i < filas; i++){
        for (int j = 0; j < colum; j++){
            cin >> number; cin.ignore();
            matriz1[i][j] = number;
        }
    }
    cout << "Ingrese digitos para la segunda matriz:\n"; 


     for(int i = 0; i < filas; i++){
        for (int j = 0; j < colum; j++){
            cin >> number; cin.ignore();
            mymatriz2[i][j] = number;
        }
    }
    suma_matrices(*matriz1, *mymatriz2, filas , colum);

return 0;
}

void suma_matrices(int *matrizA, int *matrizB,int filas, int cols){

        int matrizC[filas][cols];


    for (int i = 0; i < filas; i++){
        for (int j = 0; j < cols; j++){
         *(*(matrizC+i)+j) = (*(matrizA+i*cols+j))+(*(matrizB+i*cols+j)); 
        }
        cout << endl;
    }

   for (int i = 0; i < filas; i++){
        for (int j = 0; j < cols; j++){
            cout << matrizC[i][j] << " | ";
        }
        cout <<endl;
    }

}
