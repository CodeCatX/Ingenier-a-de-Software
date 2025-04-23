#include <iostream>
using namespace std;

void leerMatriz (int matriz[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
}

void escribirMatriz (int matriz[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int esIdentidad (int mat[][10], int n) {
    bool identidad = true;
    int i = 0;
    int j = 0;
    while (identidad && (i < n)) {
        while (j < n) {
            if (mat[i][j] != 1) {
                identidad = false;
            }
            i++;
            j++;
        }
    }
    return identidad;
}


int main () {

    int n;
    cout << "Ingresa el numero de filas y columnas de la matriz cuadrada: ";
    cin >> n;

    int matriz[10][10];
    leerMatriz(matriz, n);
    cout << "La matriz es: " << endl;
    escribirMatriz(matriz, n);
    cout << endl << "Es identidad: ";
    cout << esIdentidad(matriz, n);
}
