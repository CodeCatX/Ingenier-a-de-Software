#include <iostream>
using namespace std;

void imprimirArreglo(int n, int a[]) {
    for(int i = 0; i < n; i++) {
        cout << a[i];
    }
}

int busquedaBinaria(int fin, int a[], int numeroBuscado) {
    int i = 0;
    int band = -1;
    while(i < fin && band == -1) {
        int posMedia = (i+fin)/2;
        if (a[posMedia] == numeroBuscado) {
            band = posMedia;
        }
        if (a[posMedia] < numeroBuscado) {
            i = posMedia+1;
        } else {
            fin = posMedia;
        }
    }
    return band;
}

// Busqueda binaria con recursion y punteros
int busquedaBinaria2(int *i, int *n, int *a, int numeroBuscado) {
    int posMedia = (*i+*n)/2;
    if (a[posMedia] == numeroBuscado) {
        return posMedia;
    }
    if(*i > *n) {
        return -1;
    }
    if(a[posMedia] < numeroBuscado) {
        *i = posMedia+1;
        return busquedaBinaria2(i, n, a, numeroBuscado);
    } else {
        *n = posMedia-1;
        return busquedaBinaria2(i, n, a, numeroBuscado);
    }
}


int main() {
    int n = 10;
    int a[n] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    int numeroBuscado;
    cout << "Ingresa un número para buscar: ";
    cin >> numeroBuscado;

    int i = 0;
    cout << "Numero encontrado en la posicion " << busquedaBinaria2(&i, &n, a, numeroBuscado);

    return 0;
}