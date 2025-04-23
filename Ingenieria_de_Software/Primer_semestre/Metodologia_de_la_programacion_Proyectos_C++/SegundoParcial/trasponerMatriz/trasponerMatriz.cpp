#include <iostream>
using namespace std;

void leerMatriz(int mat[][10]) {
    int filas;
    int columnas;
    cout << "Escribe el numero de filas: ";
    cin >> filas;
    cout << "Escribe el numero de columnas: " ;
    cin >> columnas;

    for (int i = 0; i < filas; i ++) {
        for (int j = 0; j < columnas; j++) {
            cin >> mat[i][j];
        }
    }
}

void escribirMatriz(int mat[][10]) {
    cout << endl;
    int filas;
    int columnas;

    for (int i = 0; i < filas; i ++) {
        for (int j = 0; j < columnas; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void trasponerMatriz(int mat[][10]) {
    int filas;
    int columnas;

    int i = 0;
    int j = 1;
    while (i < filas) {
        while (j < columnas) {
            int aux = mat[i][j];
            mat[i][j] = mat[j][i];;
            mat[j][i] = aux;
            j++;
        }
        i++;
    }
}

void trasponerMatrizBucleFor(int mat[][10]) {
    int filas;
    int columnas;

    for (int i = 0; i < filas; i++) {
        for (int j =  1; j < columnas; j++) {
            int aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

int main() {
    int mat1[10][10];
    int mat2[10][10];

    cout << "MATRIZ 1\n";
    leerMatriz(mat1);
    cout << "Matriz 1: ";
    escribirMatriz(mat1);
    cout << "Matriz 1 traspuesta: ";
    //trasponerMatriz(mat1);
    trasponerMatrizBucleFor(mat1);
    escribirMatriz(mat1);
    return 0;
}
