#include <iostream>
using namespace std;

bool leerArregloYComprobarEsPrimoUnElemento(int n, int conjuntoD[]) {
    bool esPrimo = true;
    int i = 0;
    while (i < n) {
        cin >> conjuntoD[i];
        int x = conjuntoD[i];
        int j = 2;
        if (x > 1) {
        while (esPrimo && j < x) {
            if (x % j == 0) {
                esPrimo = false;
            } else {
                j++;
            }
        }
        }
        i++;
    }
    cout << endl;
    return esPrimo;
}

void escribirArreglo(int n, int conjuntoD[]) {
    for (int i = 0; i < n; i++) {
        cout << conjuntoD[i];
    }
}

bool esPrimoUnElemento(int n, int conjuntoD[]) {
    bool esPrimo = true;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if(conjuntoD[i] % j == 0) {
                esPrimo = false;
            }
        }
    }
    cout << endl;
    return esPrimo;
}

int main () {
    int n;
    cin >> n;
    int conjuntoD[n];
    cout << endl;
    cout << leerArregloYComprobarEsPrimoUnElemento(n, conjuntoD);
    return 0;
}
