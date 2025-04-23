#include <iostream>
using namespace std;

/*
Realiza una función que calcule el resultado de la expresión b^e
*/
long potencia(long b, long e) {
    if (e == 0)
        return 1;
    else
    return b * potencia(b, e-1);
}

int main() {
    long b, e;
    cout << "Ingrese un numero: ";
    cin >> b;
    cout << "Ingrese el valor de e: ";
    cin >> e;
    cout << "Resultado: ";
    cout << potencia(b, e);
    return 0;
}