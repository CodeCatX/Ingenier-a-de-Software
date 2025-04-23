#include <iostream>
using namespace std;

void ordSeleccion(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int PM = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[PM]) {
                PM = j;
            }
        }
        int aux = a[i];
        a[i] = a[PM];
        a[PM] = aux;
    }
}

int main () {
    int tamanio = 6;
    int arreglo[tamanio] = {55, 22, 44, 11, 66, 33};

    ordSeleccion(arreglo, tamanio);

    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;
}
