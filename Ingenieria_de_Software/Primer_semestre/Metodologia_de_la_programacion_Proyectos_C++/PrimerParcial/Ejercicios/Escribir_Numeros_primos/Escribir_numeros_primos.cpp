#include <iostream>
using namespace std;
int main () {
    int i = 2;

    while (i < 12) {
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
            cout << i << " Es primo " << endl;
        }else {
            cout << j << " No es primo ";
        }
        i++;
        }

    return 0;
}
