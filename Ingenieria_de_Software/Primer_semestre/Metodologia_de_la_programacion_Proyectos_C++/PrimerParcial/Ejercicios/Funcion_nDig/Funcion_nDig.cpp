#include <iostream>
using namespace std;

nDig (int n) {
    if (n > 0) {
        if (n < 10) {
            n = 1;
        }
        else if (n < 100) {
            n = 2;
        }
        else if (n < 1000) {
            n = 3;
        }
        else if (n < 10000) {
            n = 4;
        }
        else if (n < 100000) {
            n = 5;
        }
        else if (n < 1000000) {
            n = 6;
        }
        else if (n < 10000000) {
            n = 7;
        }
        else if (n < 100000000) {
            n = 8;
        }
        else if (n < 1000000000) {
            n = 9;
        }
        else if (n < 10000000000) {
            n = 10;
        }
    } else {
        cout << "No se pueden calcular los digitos de los numeros negativos";
    }

    return n;
}

int main () {
    int n;
    cin >> n;

    cout << n << " tiene " << nDig(n) << " digitos.";
    return 0;
}

/*}
#include <iostream>

using namespace std;

int nDig(int n) {
    if (n <= 0) {
        cout << "No se pueden calcular los dígitos de los números negativos" << endl;
        return -1;
    }

    int digits = 0;
    while (n > 0) {
        n /= 10;
        digits++;
    }

    return digits;
}

int main() {
    int n;
    cout << "Introduce un número: ";
    cin >> n;

    if (n > 0) {
        cout << n << " tiene " << nDig(n) << " dígitos." << endl;
    } else {
        nDig(n);
    }

    return 0;
}
*/
