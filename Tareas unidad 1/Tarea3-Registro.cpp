#include <iostream>
#include <string>
using namespace std;

struct Pais{
    string nombrePais;
    string capital;
    int habitantesNum;
    int edadPromedio;

};

struct Continente{
    Pais elemento;
   
};

void InformacionContinente(Continente* array, int size);

int main(void){
    int size = 0;
    Continente *continentes;


    cout <<"Ingrese numero de paises a ingresar: "; cin >> size; cin.ignore();

    continentes = new Continente[size];

    for (int i = 0; i < size; i++){
        cout << "Ingrese nombre del pais: "; getline(cin, continentes[i].elemento.nombrePais); 
        cout << "Ingrese numero de habitantes: "; cin >>continentes[i].elemento.habitantesNum; cin.ignore();
        cout <<"Ingrese la capital del pais: "; getline(cin, continentes[i].elemento.capital);
        cout <<"Ingrese la edad promedio de los habitantes: "; cin >>continentes[i].elemento.edadPromedio; cin.ignore();
    }

    InformacionContinente(continentes, size);

return 0;
    }

//Funcion para obtener datos de la estructura por referencia
void InformacionContinente(Continente* array, int size){
    int choice = 0;
    int Totales = 0;
    float promedio = 0;

    do{
    cout <<"1- Calcular la poblacion total del continente\n";
    cout <<"2- Encontrar capital con mayor poblacion\n";
    cout <<"3- Calcular la edad promedio del continente\n";
    cout <<"0- Salir\n";
    cout <<"Su opcion: "; cin>> choice; cin.ignore();
        switch(choice){
            case 1:
            for(int i = 0; i < size; i++){
            Totales = Totales + array[i].elemento.habitantesNum;
            }
            
            cout <<"La poblacion total es: "<< Totales << endl;
            break;
            
            case 2:
            for (int i = 0; i < size; i++){
                if(array[i].elemento.habitantesNum > array[i+1].elemento.habitantesNum)
                    cout <<"La capital con mas habitantes es: " << array[i].elemento.capital<< endl;
                else 
                    cout <<"La capital con mas habitantes es: " << array[i+1].elemento.capital<< endl;
            }


            break;

            case 3:
                for(int i = 0; i < size; i++){
                    Totales = Totales + array[i].elemento.edadPromedio;
                }
                promedio = Totales/size;
                cout <<"La edad promedio del continente es: " << promedio << endl;
            break;

            default:
            break;

            
        }

    }while(choice!=0);
    
}