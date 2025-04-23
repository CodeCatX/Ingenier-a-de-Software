#include <iostream>
using namespace std;

void leerMatriz (int matriz[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
}

void escribirMatriz (int matriz[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int esSimetrica (int m[][100], int n) {
    int simetrica = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (simetrica && (m[i][j] == m[j][i])) {
                simetrica = 1;
            } else {

                simetrica = 0;
            }
        }
    }
    return simetrica;
}

int main () {

    int n;
    cout << "Ingresa el numero de filas y columnas de la matriz cuadrada: ";
    cin >> n;

    int matriz[100][100];
    leerMatriz(matriz, n);
    cout << "La matriz es: " << endl;
    escribirMatriz(matriz, n);
    cout << endl << "Es simetrica: ";
    cout << esSimetrica(matriz, n);
}
