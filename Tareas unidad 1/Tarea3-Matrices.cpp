#include <iostream>

using namespace std;

void puntero(int *a, int cols){
    int suma = 0;
    int suma2 = 0;
    //cout << "*(p+i*COLS+j): " << endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            
            if(i == 0){
            
        suma = suma + (*(a+i*cols+j));
            }
        else{
            suma2 = suma2 + (*(a+i*cols+j));
            
        }
        
        }
        
        
    }
    if(suma<suma2){
        cout<<"La semana 2 tuvo mas ventas: "<<suma2<<endl;
    }
    else if(suma2 < suma){
        cout<<"La semana 1 tuvo mas ventas: "<<suma<<endl;
    }
    else{
        cout<<"Se vendio la misma cantidad de unidades en ambas semanas"<<endl;
    }

}

int main()
{
    
int cols = 5;
int quincena[2][cols];
int venta;

for (int i = 0;i < 2; i++){
    for (int j = 0;j < 5; j++){
        cout<<"Ingrese unidades vendidad de semana: "<<i+1<<" dia: "<<j+1<<endl;
        cin>>venta;
        quincena[i][j]=venta;
        
    }
    
}

puntero(*quincena, cols);
    return 0;
}
