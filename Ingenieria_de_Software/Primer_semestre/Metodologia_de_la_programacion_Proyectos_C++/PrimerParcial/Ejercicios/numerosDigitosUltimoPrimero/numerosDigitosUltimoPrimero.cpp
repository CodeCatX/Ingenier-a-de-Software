#include <iostream>
using namespace std;

void invertirDigitos(int a[], int n) {
    for (int i = n-1; i >= 0; i--) {
        cout << a[i];
    }
}

int main () {
    int tamanio;
    cin >> tamanio;
    int a[tamanio];

    for (int i = 0; i < tamanio; i++) {
        cin >> a[i];
    }

    invertirDigitos(a, tamanio);

    return 0;
}
