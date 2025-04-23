#include <iostream>
using namespace std;
float getPromedio (float a[], int n) {
    float suma = a[0];
    for (int i = 1; i < n; i ++) {
        suma += a[i];
    }

    return suma/n;
}

int estaOrdenado (float a[], int n) {
    int bandera = true;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return 0;

        }
    }
    return bandera;
}

int getPosX (float a[], int n, int x) {
    int posicion = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return posicion;
        }
        posicion++;
    }
    return -1;

}

int main () {
    int tamanioArreglo;
    cin >> tamanioArreglo;
    float arreglo[tamanioArreglo];
    for (int i = 0; i < tamanioArreglo; i++) {
        cin >> arreglo[i];
    }
    cout << "Promedio: " << getPromedio(arreglo, tamanioArreglo) << endl;
    cout << "Esta ordenado?: " << estaOrdenado(arreglo, tamanioArreglo) << endl;
    int x;
    cout << "Ingresa el valor de x: ";
    cin >> x;
    cout << "x se encuentra en la posicion: " << getPosX(arreglo, tamanioArreglo, x) << endl;
    return 0;
}
