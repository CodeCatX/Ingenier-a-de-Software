/*
Realiza una función que imprima la serie:
n, n-1 ,n-2, ...,1
*/
#include <iostream>
using namespace std;

int serie(int n) {
    cout << n << " ";
    if (n == 1) {
        return 1;
    } else {
        return serie(n-1);
    }
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    cout << "Serie: ";
    serie(n);
    return 0;
}