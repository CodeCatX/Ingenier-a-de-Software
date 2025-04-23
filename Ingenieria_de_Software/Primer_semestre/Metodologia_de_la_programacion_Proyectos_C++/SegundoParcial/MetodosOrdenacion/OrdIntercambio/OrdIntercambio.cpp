#include <iostream>
using namespace std;

void ordIntercambio(int a[], int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n;  j++) {
            if (a[i] < a[j-1]) {
                int aux = a[j-1];
                a[j-1] = a[i];
                a[i] = aux;
            }
        }
    }
}

int main () {
    cout << "Ordenamiento por intercambio (Burbuja)" << endl;
    cout << "Ingresa el tamaño del arreglo: ";
    int tamanio;
    cin >> tamanio;
    cout << endl << "Ingresa los datos del arreglo: ";
    int arreglo[tamanio];

    for(int i = 0; i < tamanio; i++) {
        cin >> arreglo[i];
        cout << " ";
    }

    ordIntercambio(arreglo, tamanio);

    cout << endl << "Arreglo ordenado" << endl;
    for(int i = 0; i < tamanio; i++) {
        cout << arreglo[i];
        cout << " ";
    }

    return 0;
}
