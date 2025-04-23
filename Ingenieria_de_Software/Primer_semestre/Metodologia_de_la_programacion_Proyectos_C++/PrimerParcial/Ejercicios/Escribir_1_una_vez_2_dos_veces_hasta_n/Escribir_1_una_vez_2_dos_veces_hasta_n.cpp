// Escribir el 1 una vez, el 2 dos veces... hasta el n.
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingresa un numero mayor a 0: ";
    cin >> n;

    if (n >= 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << n-1;
            }
            cout << endl;
        }
    } else {
        cout << "El numero ingresado debe ser mayor a 0";
    }

    return 0;
}
