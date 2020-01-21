//obteniendo ultimo elemento

Ultimo_Elemento(Pila s){
    if (s.empty())
        return -1; //Lista vacia
        
        int myArray[s.size()];

    for (int i = 0; i < s.size(); i++){
        myArray[i] = s.pop();


    }
    cout << "Ultimo elemento: " << myArray[s.size()-1];

     for (int i = s.size(); i >= 0; i--){
        s.push(myArrar[i]);
    }
}

