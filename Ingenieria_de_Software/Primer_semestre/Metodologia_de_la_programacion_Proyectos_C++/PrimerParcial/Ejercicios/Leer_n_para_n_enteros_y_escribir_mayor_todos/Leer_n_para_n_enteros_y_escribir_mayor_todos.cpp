#include <iostream>
using namespace std;
int main() {
    int numeros_enteros;
    int mayor;
    int n;

    cin >> numeros_enteros;
    if (numeros_enteros > 0) {
        cin >> n;
        mayor = n;
        int i = 1;
        while (i < numeros_enteros) {
            cin >> n;
            if (n > mayor) {
                mayor = n;
            }
            i++;
        }
        cout << "El número mayor es: " << mayor;
    }

    return 0;
}
