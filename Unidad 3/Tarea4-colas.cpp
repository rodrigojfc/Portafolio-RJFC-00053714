#include <iostream>
#include <string>
using namespace std;

enum Especialidades {vegetariana, carnivora, cuatroQuesos, suprema};

struct Pedido{
    string apellido;
    int mesa;
    Especialidades tipoPizza;
    int tiempo;
};

// Tipo de dato que contendran los nodos de la Cola
typedef Pedido T;
const T noValido = {{" "},-1,{} ,-1};

// Registros: nodo y Cola
struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

// Prototipos de funciones para Cola
void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

struct Pizzeria{
    Cola colaPedidos;
    int pizzasHechas;
};
Pizzeria elGanadero;

void agregar();
void consultar();
void servir();
void vertodos();

int main(){
    initialize(&elGanadero.colaPedidos);
    elGanadero.pizzasHechas = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

// Implementacion de funciones
void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente==NULL) ? true : false;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
        
    q->final = unNodo;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *q){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;
    // Transfiriendo desde q hasta colaTemporal
    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    // Transfiriendo desde colaTemporal hasta q
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}

// Funciones ---------------------------------------
void agregar(){
    // Solicitar datos del pedido

    int choice;
    
    Pedido unPedido;
    cout << "Digite su apellido: "; getline(cin, unPedido.apellido);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Especialidad de la pizza: " << endl;
    cout << "1) Vegetariana "<< endl;
    cout << "2) Carnivora" << endl;
    cout <<"3) Cuatro Quesos"<< endl;
    cout <<"4) Suprema"<< endl;
    cout << "Ingrese opcion de la pizza:\t"; cin >> choice; cin.ignore();

    if(choice == 1)
        unPedido.tipoPizza = vegetariana;
    else if(choice == 2)
        unPedido.tipoPizza = carnivora;
    else if(choice == 3)
        unPedido.tipoPizza = cuatroQuesos;
    else
    {
        unPedido.tipoPizza = suprema;
    }
    
    
    // Agregar a la cola
    enqueue(&elGanadero.colaPedidos, unPedido);
    // Modificar contadores
    elGanadero.pizzasHechas += 1;
}

void consultar(){
    cout << "Pedidos en espera: " << size(&elGanadero.colaPedidos) << endl;
    cout << "Total pizzas hechas: " << elGanadero.pizzasHechas << endl;
}

void servir(){
    Pedido pedidoDespachado = dequeue(&elGanadero.colaPedidos);
    cout << "Familia " << pedidoDespachado.apellido << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.mesa << endl;
}

void vertodos(){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    // Transfiriendo desde elGanadero.colaPedidos hasta colaTemporal
    while(!empty(&elGanadero.colaPedidos)){
        Pedido unPedido = dequeue(&elGanadero.colaPedidos);
        enqueue(&colaTemporal, unPedido);
        
        cout << "Info del pedido: "<< endl;
        cout <<"Familia " << unPedido.apellido << ", ";
        if (unPedido.tipoPizza == 0)
            cout <<"Especialidad de la pizza: " << "Vegetariana" <<"\n\n";
        else if(unPedido.tipoPizza == 1)
            cout <<"Especialidad de la pizza: " << "Carnivora" <<"\n\n";
        else if(unPedido.tipoPizza == 2)
            cout <<"Especialidad de la pizza: " << "Cuatro Quesos" <<"\n\n";
        else
        {
            cout <<"Especialidad de la pizza: " << "Suprema" <<"\n\n";
        }
        

    }
    // Transfiriendo desde colaTemporal hasta elGanadero.colaPedidos
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&elGanadero.colaPedidos, elemento);
    }
}
