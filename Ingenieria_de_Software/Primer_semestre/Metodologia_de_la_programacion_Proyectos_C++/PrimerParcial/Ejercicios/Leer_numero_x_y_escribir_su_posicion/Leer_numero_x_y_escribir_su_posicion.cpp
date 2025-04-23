#include <iostream>
using namespace std;
int main () {
    int x;
    int n;
    int i = 0;

    cout << "Ingrese el valor de x: ";
    cin >> x;
    do {
        cout << "Ingrese un numero: ";
        cin >> n;
        i++;
    } while (n != x);
    cout << i;

    return 0;
}
