#include <iostream>
using namespace std;
int main () {
    for (int i = 1; i <= 10; i++) {
        cout << "Tabla del " << i << endl;
            for (int j = 1; j <= 10; j++) {
                cout << i << " x " << j << " = " << i * j << endl;
            }
        cout << endl;
    }

    return 0;

}
