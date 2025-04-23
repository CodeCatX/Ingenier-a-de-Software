/*
Realiza una función que imprima la serie:
1, 2, 3, 4, ..., n-1, n
*/
#include <iostream>
using namespace std;

void serie(int n) {
    if (n > 1) {
        serie(n - 1);
    }
    cout << n << " ";
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    cout << "Serie: ";
    serie(n);
    return 0;
}