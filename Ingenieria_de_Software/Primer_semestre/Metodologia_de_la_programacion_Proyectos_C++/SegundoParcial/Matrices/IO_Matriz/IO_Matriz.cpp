#include <iostream>
using namespace std;

void leerMatriz(int matriz[][100], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }
}

void escribirMatriz(int matriz[][100], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j];
        }
        cout << endl;
    }
}

void promFilas (int matriz[][100], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        float suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
        cout << endl << "El promedio de sus filas es: ";
        cout << suma/(float)columnas;
    }
}

int main () {

    int filas, columnas;
    cout << "Ingresa las filas de la matriz: ";
    cin >> filas;
    cout << "Ingresa las columnas de la matriz: ";
    cin >> columnas;

    int matriz[100][100];
    leerMatriz(matriz, filas, columnas);
    cout << "La matriz es: " << endl;
    escribirMatriz(matriz, filas, columnas);
    promFilas(matriz, filas, columnas);
}
