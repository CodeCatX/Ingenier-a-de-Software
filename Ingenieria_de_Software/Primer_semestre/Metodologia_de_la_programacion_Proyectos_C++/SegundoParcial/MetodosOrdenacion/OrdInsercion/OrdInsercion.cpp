#include <iostream>
using namespace std;

void ordInsercion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = a[i];
        int j = i-1;
        int finj = false;
        while ((!finj) && (j > -1)) {
            if (a[j] > aux) {
                a[j+1] = a[j];
                j--;
            } else {
                finj = true;
            }
        }
        a[j+1] = aux;
    }
}

int main () {
    int tamanio = 6;
    int arreglo[tamanio] = {55, 22, 44, 11, 66, 33};

    ordInsercion(arreglo, tamanio);

    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;
}
