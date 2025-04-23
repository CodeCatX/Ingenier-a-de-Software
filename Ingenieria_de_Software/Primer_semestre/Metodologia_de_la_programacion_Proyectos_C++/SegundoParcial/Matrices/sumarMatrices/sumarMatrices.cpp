#include <iostream>
using namespace std;

void escribirMatriz(int mat[][10], int filas, int columnas) {
    cout << endl;

    for (int i = 0; i < filas; i ++) {
        for (int j = 0; j < columnas; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sumarMatrices(int a[][10], int b[][10], int c[][10], int m, int n) {
    //Amn + Bmn = Cmn
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    int mat1[10][10];
    int mat2[10][10];
    int mat3[10][10];

    cout << "MATRIZ 1\n";
        int filasM1;
        int columnasM1;
        cout << "Escribe el numero de filas: ";
        cin >> filasM1;
        cout << "Escribe el numero de columnas: " ;
        cin >> columnasM1;

        for (int i = 0; i < filasM1; i++) {
            for (int j = 0; j < columnasM1; j++) {
                cin >> mat1[i][j];
            }
        }
        cout << "Matriz 1: ";
        escribirMatriz(mat1, filasM1, columnasM1);

    cout << "MATRIZ 2\n";
        int filasM2;
        int columnasM2;
        cout << "Escribe el numero de filas: ";
        cin >> filasM2;
        cout << "Escribe el numero de columnas: " ;
        cin >> columnasM2;

        for (int i = 0; i < filasM2; i++) {
            for (int j = 0; j < columnasM2; j++) {
                cin >> mat2[i][j];
            }
        }
        cout << "Matriz 2: ";
        escribirMatriz(mat2, filasM2, columnasM2);

        cout << "Producto de las 2 matrices: " << endl;
        if (columnasM1 == columnasM2 && filasM1 == filasM2) {
            sumarMatrices(mat1, mat2, mat3, filasM1, columnasM1);
        } else {
            cout << "No se pueden sumar las matrices";
        }

        cout << "MATRIZ 3 (Suma Matriz 1 + Matriz 2)\n";
        escribirMatriz(mat3, filasM1, columnasM2);
    return 0;
}
