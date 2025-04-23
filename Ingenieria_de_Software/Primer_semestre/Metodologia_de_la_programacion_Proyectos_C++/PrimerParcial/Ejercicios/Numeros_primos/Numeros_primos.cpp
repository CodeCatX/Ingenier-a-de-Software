#include <iostream>
using namespace std;
int main (){
    // Es primo si n > 1 && (n % i == 0) si este es < n.
    int n;
    cin >> n;
    bool esPrimo = true;
    int i = 2;

    while (esPrimo && i < n) {
        if (n % i == 0) {
            esPrimo = false;
        } else {
            i++;
        }
    }

    if (esPrimo) {
        cout << "Es primo" << endl;
    }else {
        cout << "No es primo";
    }

    return 0;
}
