// Realice una función que sume los elementos de un arreglo de enteros (con recursión).
#include <iostream>
using namespace std;

void insertarElementos(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el numero en la posicion " << i << " del arreglo:";
        cin >> a[i];
    }
}

int suma(int a[], int n) {
    if (n < 0) {
        return 0;
    } else {
        return a[n] += suma(a, n-1);
    }
}

int main() {
    int n;
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> n;
    int a[n];
    insertarElementos(a, n);
    cout << "El resultado es: " << suma(a, n);

    return 0;
}