#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    cout << "Llamando factorial(" << n << ")" << endl;
    if (n == 0 || n == 1) {
        cout << "Retornando 1 porque n = " << n << endl;
        return 1;
    } else {
        unsigned long long resultado = n * factorial(n - 1);
        cout << "factorial(" << n << ") = " << resultado << endl;
        return resultado;
    }
}

int main() {
    int n;
    cout << "Ingrese un número: ";
    cin >> n;
    cout << "El factorial de " << n << " es " << factorial(n) << endl;
    return 0;
}
