#include <iostream>

using namespace std;

void imprimirArreglo(char *my_arr1, int item) {

      if(item<=0) return;

      imprimirArreglo(my_arr1, item-1);

      cout << ' ' << my_arr1[item-1];


}
int main()
{
 
    char my_arr1 [] = {'h','e','l','l','o'};
    imprimirArreglo(my_arr1, 5);
    
    
    return 0;
}
