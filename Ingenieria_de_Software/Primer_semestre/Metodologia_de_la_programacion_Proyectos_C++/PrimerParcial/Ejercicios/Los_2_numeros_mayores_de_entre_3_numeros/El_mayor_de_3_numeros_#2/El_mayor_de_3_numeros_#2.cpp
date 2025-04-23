#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3, mayor;
    cout << "Ingresa 3 numeros: " << endl;
    cout << "> ";cin >> n1; cout << "> "; cin >> n2; cout << "> "; cin >> n3; cout << "> ";
    mayor = n1;

    if (n2 > mayor) {
        mayor = n2;
        if (n3 > mayor) {
            mayor = n3;
    }
    }

    cout << "Mayor: " << mayor;

    return 0;
}
