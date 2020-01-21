#include <iostream>
#include <string>
using namespace std;

// Definicion de nodo ------------------------
struct Pesa{
    string color;
    string material;
    int peso;
};
typedef struct Pesa Pesa;

struct nodo{
    Pesa elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

// Prototipos de funciones ------------------------
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Pesa e);
Pesa pop(Pila *s);
Pesa top(Pila *s);

// Programa principal ------------------------
int main(){
    // 1) Creando pila de Pesas vacia -------------
    Pila pilaDePesas;
    initialize(&pilaDePesas);
    
    // 2) Apilando Pesas --------------------------
    bool continuar = true;
    do{
        char opcion = 's';
        //cout << "\nCantidad de Pesas actual: " << pilaDePesas.size();
        cout << "\nDesea apilar otra Pesa? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Pesa unPesa;
            cout << "Color: ";      getline(cin, unPesa.color);
            cout << "Material: ";   getline(cin, unPesa.material);
            cout << "Peso en libras: ";       cin >> unPesa.peso;
            push(&pilaDePesas, unPesa);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    // 3) Desapilando Pesas -----------------------
    cout << "\nDesapilando Pesas..." << endl;
    while(!empty(&pilaDePesas)){
        // Obtener el Pesa de encima (sin sacarlo de la pila)
        Pesa PesaDeEncima = top(&pilaDePesas);
        cout << "Pesa [" << PesaDeEncima.color;
        cout << ", " << PesaDeEncima.material;
        cout << ", " << PesaDeEncima.peso << "]\n";
        
        // Sacando Pesa de la pila
        pop(&pilaDePesas);
    }
    cout << "Pila de Pesas vacia." << endl;

    return 0;
}

// Implementacion de funciones ------------------------
void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, Pesa e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

Pesa pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Pesa e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return {{" "},{" "}};
}

Pesa top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else // Underflow!
        return {{" "},{" "}};
}
