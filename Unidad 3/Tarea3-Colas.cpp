#include <iostream>
#include <queue>
#include <string>
using namespace std; 

struct Actividad{
    string nombre_actividad;
    string hora;
    int duracion;
};typedef struct Actividad actividad;

struct Agenda{
    queue <actividad> lista_actividades;
    queue <actividad> lista2;
    int cant_actividades;   
    
};typedef struct Agenda agenda;


void agregar();
void consultar();
void borrarActividad();
void borrar_todo();

Agenda my_shedule;

int main(void){
    my_shedule.cant_actividades = 0;
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar una nueva actividad\n";
        cout << "2) Ver actividades del dia\n";
        cout << "3) Borrar una actividad\n";
        cout << "4) Borrar todas las actividades\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: borrarActividad(); break;
            case 4: borrar_todo(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
            
        }
    }while(continuar);

    return 0;
}

void agregar(){
     // Solicitar datos del la actividad
    actividad unaActividad;
    cout << "Digite nombre de la actividad: "; getline(cin, unaActividad.nombre_actividad);
    cout << "Ingrese hora de la actividad (texto): "; getline(cin, unaActividad.hora); 
    cout << "Duracion en minutos: "; cin >> unaActividad.duracion; cin.ignore();
    
    // Agregar a la cola
    my_shedule.lista_actividades.push(unaActividad);
}


void consultar(){
    cout << "Total de actividades del dia: " << my_shedule.lista_actividades.size() << endl<< endl;
    while(!my_shedule.lista_actividades.empty()){
        actividad my_Activity = my_shedule.lista_actividades.front();
        my_shedule.lista2.push(my_Activity);
        cout << "Actividades del dia:\n " << my_Activity.nombre_actividad << endl;
        my_shedule.lista_actividades.pop();
        }
    while (!my_shedule.lista2.empty()){
        actividad new_activity = my_shedule.lista2.front();
        my_shedule.lista_actividades.push(new_activity);
        my_shedule.lista2.pop();
    }
    
}


void borrarActividad(){
    if (my_shedule.lista_actividades.empty()){
        cout <<"No hay activades para borrar"<<endl;
    }
    else{
        my_shedule.lista_actividades.pop();
        cout <<"Se ha borrado una actividad" << endl;
    }

}

void borrar_todo(){
    while(!my_shedule.lista_actividades.empty()){
        my_shedule.lista_actividades.pop();
    }
    cout<<"Las actividades se han borrado" << endl;

}