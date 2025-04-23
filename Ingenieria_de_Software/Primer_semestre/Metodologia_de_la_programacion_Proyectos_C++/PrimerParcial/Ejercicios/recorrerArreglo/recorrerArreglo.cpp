#include <iostream>
using namespace std;

void recorrerArreglo(int a[], int n) {
    int aux = a[n-1];
    for(int i = n-1; i >= 1; i--) {
        a[i] = a[i - 1];
    }
    a[0] = aux;

}

int main() {
    int tamanio;
    cin >> tamanio;
    int a[tamanio];

    for (int i = 0; i < tamanio; i++) {
        cin >> a[i];
    }

    recorrerArreglo(a, tamanio);

    for (int i = 0; i < tamanio; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
