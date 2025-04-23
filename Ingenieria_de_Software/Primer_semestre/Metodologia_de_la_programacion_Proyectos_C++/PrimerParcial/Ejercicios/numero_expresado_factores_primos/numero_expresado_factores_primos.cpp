#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Introduce un número: ";
    cin >> n;

    cout << n << " = ";
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i;
            n /= i;
            if (n > 1) {
                cout << " x ";
            }
        }
    }

    return 0;
}







/*
#include <iostream>
using namespace std;
int main () {
    // Ejemplo: n = 18 = 2 x 3 x 3.
    int n;
    cin >> n;
    int i = 2;
    int factor = 1;
    while (i < n) {
        bool esPrimo = true;
        int j = 2;
        while (j < i) {
            if (esPrimo && (i % j == 0)) {
                    esPrimo = false;
            } else {
                j++;
            }
        }
        if (esPrimo) {
            factor += factor * j;
            cout << j << " x ";

        }

        i++;

    }
        cout << endl << "Factor: " << factor;

    return 0;
}
*/
