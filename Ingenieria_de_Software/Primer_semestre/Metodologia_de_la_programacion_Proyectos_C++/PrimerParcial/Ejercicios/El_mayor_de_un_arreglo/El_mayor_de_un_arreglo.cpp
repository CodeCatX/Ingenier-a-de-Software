#include <iostream>
using namespace std;
int mayorDeUnArreglo (int a[], int n) {
    int mayor = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > mayor) {
            mayor = a[i];
        }
    }

    return mayor;
}

int main () {
    int tamanio;
    cin >> tamanio;
    int arreglo[tamanio];
    for (int i = 0; i < tamanio; i++) {
        cin << arreglo[i];
    }

    cout << mayorDeUnArreglo(arreglo, tamanio);

    return 0;
}
