#include <iostream>

using namespace std;


int suma_rec(int a){
    int resultado;
    if (a == 0){
        resultado = 0;
    }
    else {
        resultado = a + suma_rec(a-1);
    }
    return resultado;
}

int main()
{
    int num;
    int result;
    cout<<"Ingresa en el que termina la suma: " << endl;
    cin>>num;
    
    result = suma_rec(num);
    
    cout << "El la suma de todos los numeros hasta " << num << " es: " << result << endl;

    return 0;
}

