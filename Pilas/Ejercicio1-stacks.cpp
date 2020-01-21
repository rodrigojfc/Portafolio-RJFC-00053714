#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Pesas{
    string color;
    string material;
    int peso;
};
typedef struct Pesas Pesas;

int main(){
    // 1) Creando pila de Pesass vacia -------------
    stack<Pesas> pilaDePesass;
    
    // 2) Apilando Pesass --------------------------
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de Pesass actual: " << pilaDePesass.size();
        cout << "\nDesea apilar otro Pesas? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Pesas unPesas;
            cout << "Color: ";   getline(cin, unPesas.color);
            cout << "Material: ";   getline(cin, unPesas.material);
            cout << "Peso en libras: "; cin >> unPesas.peso;
            pilaDePesass.push(unPesas); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    // 3) Desapilando Pesass -----------------------
    cout << "\nDesapilando Pesass..." << endl;
    while(!pilaDePesass.empty()){
        // Obtener el Pesas de encima (sin sacarlo de la pila)
        Pesas PesasDeEncima = pilaDePesass.top();
        cout << "Pesas [" << PesasDeEncima.color;
        cout << ", " << PesasDeEncima.material;
        cout << ", " << PesasDeEncima.peso << "]\n";
        
        // Sacando Pesas de la pila
        pilaDePesass.pop();
    }
    cout << "Pila de Pesass vacia." << endl;

    return 0;
}

