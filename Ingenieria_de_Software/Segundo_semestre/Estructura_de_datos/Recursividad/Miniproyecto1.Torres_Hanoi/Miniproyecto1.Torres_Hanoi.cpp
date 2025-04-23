#include <iostream>
using namespace std;

void llenarArreglo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
}

int obtenerPosicionDisco(int torre[], int n) {
    for (int i = 0; i < n; i++) {
        if (torre[i] != 0) {
            return i;
        }
    }
    return -1;
}

int obtenerEspacioDisco(int torre[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (torre[i] == 0) {
            return i;
        }
    }
    return -1;
}

void moverDiscos(int torre1[], int torre2[], int n) {
    int posDisco = obtenerPosicionDisco(torre1, n);
    int espDisco = obtenerEspacioDisco(torre2, n);

    if (posDisco != -1 && espDisco != -1) {
        torre2[espDisco] = torre1[posDisco];
        torre1[posDisco] = 0;
    }
}

void mostrarTorre(int n, int a[], int b[], int c[]) {
    cout << "Torre A: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "Torre B: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    
    cout << "Torre C: ";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl << "-------------------------" << endl;
}

void torreHanoi(int n, int origen[], int auxiliar[], int destino[], int tamanio) {
    if (n == 1) {
        moverDiscos(origen, destino, tamanio);
        mostrarTorre(tamanio, origen, auxiliar, destino);
        return;
    }
    
    torreHanoi(n - 1, origen, destino, auxiliar, tamanio);
    moverDiscos(origen, destino, tamanio);
    mostrarTorre(tamanio, origen, auxiliar, destino);
    torreHanoi(n - 1, auxiliar, origen, destino, tamanio);
}

int main() {
    int n;
    cout << "\033[93mIngrese el numero de discos: \033[0m";
    cin >> n;

    int a[n] = {0};
    llenarArreglo(a, n);
    int b[n] = {0};
    int c[n] = {0};

    cout << "\033[93mEstado inicial:\033[0m" << endl;
    mostrarTorre(n, a, b, c);
    cout << endl;

    torreHanoi(n, a, b, c, n);

    cout << "\033[93mEstado final:\033[0m" << endl;
    mostrarTorre(n, a, b, c);
    cout << endl;

    return 0;
}