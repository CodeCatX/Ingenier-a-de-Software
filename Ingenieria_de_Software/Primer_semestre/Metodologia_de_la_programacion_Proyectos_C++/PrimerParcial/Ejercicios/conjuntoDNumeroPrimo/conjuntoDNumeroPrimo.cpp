#include <iostream>
using namespace std;

int main() {
    bool esPrimo= false;
    int n;
    cin >> n;
    int conjuntoD[n];
    for (int i = 0; i < n; i++) {
        cin >> conjuntoD[i];
    }
    for (int i = 0; i < n; i++) {
        cout << conjuntoD[i];
    }
    int i = 0;
    int j = 2;
    while (!esPrimo && i < n) {
            if (!(conjuntoD[i] > 1 && conjuntoD[i] % j == 0)) {
                esPrimo = true;
            } else {
                i++;
                j++;
            }
    }
    cout << endl;
    cout << esPrimo;
    return 0;
}
