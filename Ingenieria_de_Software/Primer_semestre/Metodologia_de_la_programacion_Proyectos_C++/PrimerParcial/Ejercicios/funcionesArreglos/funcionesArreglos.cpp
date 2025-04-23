// Hacer una función que lea un número y escriba sus factores primos. 5 x 2, 5= 5,
#include <iostream>
using namespace std;

int sumaArreglo(int a[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += a[i];
    }
    return suma;
}

int maxArreglo (int a[], int n) {
    int max = a[0];
    int i = 0;
    while (i < n) {
            if (max < a[i+1]) {
                max = a[i+1];
            }
        i++;
    }
    return max;
}

int minArreglo (int a[], int n) {
    int min = a[0];
    int i = 1;
    while (i < n) {
            if (min > a[i]) {
                min = a[i];
            }
        i++;
    }
    return min;
}

int main () {
    int tamanio;
    cin >> tamanio;
    int a[tamanio];

    for (int i = 0; i < tamanio; i++) {
        cin >> a[i];
    }

    cout << "Suma: " << sumaArreglo(a, tamanio) << endl;
    cout << "Promedio: " << sumaArreglo(a, tamanio)/tamanio << endl;
    cout << "Numero maximo: " << maxArreglo(a, tamanio) << endl;
    cout << "Numero minimo: " << minArreglo(a, tamanio) << endl;


}
