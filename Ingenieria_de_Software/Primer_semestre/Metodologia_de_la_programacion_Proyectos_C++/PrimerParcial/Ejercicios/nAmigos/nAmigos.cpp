#include <iostream>
using namespace std;

int sumaDiv(int n) {
    int div = 0;
    int contador = 0 ;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            div += i;
            contador ++;
        }
    }
    return div;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    cout << endl;
    if (sumaDiv(n1) == n2) {
        cout << endl << "Son amigos" << endl;
    } else {
        cout << endl << "No son amigos" << endl;
    }
    cout << sumaDiv(n1);
    cout << endl;
    cout << sumaDiv(n2);
}
