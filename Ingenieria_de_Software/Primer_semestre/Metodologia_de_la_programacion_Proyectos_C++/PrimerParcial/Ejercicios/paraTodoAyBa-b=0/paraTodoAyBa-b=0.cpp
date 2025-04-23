#include <iostream>
using namespace std;

void conjuntoA(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

void conjuntoB(int B[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
}

bool condicion(int A[], int nA, int B[], int nB) {
    bool bandera = false;
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            // Verifica |a-b|=0
            if (A[i] - B[j] == 0 || B[j] - A[i] == 0) {
                bandera = true;
            }
        }
    }
    return bandera;
}

int main() {
    int nA;
    cout << "Introduce el tamaño del conjunto A: ";
    cin >> nA;
    int A[nA];
    conjuntoA(A, nA);
    cout << endl;

    int nB;
    cout << "Introduce el tamaño del conjunto B: ";
    cin >> nB;
    int B[nB];
    conjuntoB(B, nB);
    cout << endl;

    cout << condicion(A, nA, B, nB);
    cout << endl;

    return 0;
}
