/* 
Realice una función que intercambie el valor de las variables recibidas.
 void intercambia(int &a, int &b)
*/

#include <iostream>
using namespace std;

void intercambia(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {
    int a, b;
    cout << "Ingrese un valor para la variable a: ";
    cin >> a;
    cout << "Ingrese un valor para la variable b: ";
    cin >> b;
    cout << endl;

    intercambia(a, b);

    cout << "a: " << a;
    cout << endl;
    cout << "b: " << b;
    return 0;
}