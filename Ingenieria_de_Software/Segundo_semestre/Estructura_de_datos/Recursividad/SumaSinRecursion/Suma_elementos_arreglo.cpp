// Realice una función que sume los elementos de un arreglo de enteros (sin recursión).
#include <iostream>
using namespace std;

void insertarElementos(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el numero en la posicion " << i << " del arreglo:";
        cin >> a[i];
    }
}

int suma(int a[], int n) {
    int sumaElementos = a[0];
    for(int i = 1; i < n; i++) {
        sumaElementos += a[i];
    }
    return sumaElementos;
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