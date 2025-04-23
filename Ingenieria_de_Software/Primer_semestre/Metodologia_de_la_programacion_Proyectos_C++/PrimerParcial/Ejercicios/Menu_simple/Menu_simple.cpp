#include <iostream>
using namespace std;
int main () {
    int opcion;
        do {
            cout << "Desea salir? SI: 1, NO: 0" << endl;
            cin >> opcion;
        } while (opcion != 1);

    return 0;
}
