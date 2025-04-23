#include <iostream>
using namespace std;

/*
Realiza una función que calcule el número de dígitos
de un número entero.
*/
long digitos(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + digitos(n/10);
    }
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    cout << "Resultado: ";
    cout << digitos(n) << " digitos";
    return 0;
}