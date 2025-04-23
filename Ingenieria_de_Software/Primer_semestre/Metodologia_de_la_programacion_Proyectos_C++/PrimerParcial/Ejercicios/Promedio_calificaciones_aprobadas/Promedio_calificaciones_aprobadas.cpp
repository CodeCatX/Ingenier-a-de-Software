#include <iostream>
using namespace std;
int main() {
    int nAp = 0;
    int sumaAp = 0;
    int c;
    cin >> c;
    while (c >= 0) {
        if (c >= 6){
            sumaAp = sumaAp + c;
            nAp++;

        }
        cin >> c;
    }
    if (nAp == 0) {
        cout << "No se puede dividir entre 0";
    }
    else {
        cout << sumaAp / nAp;
    }

return 0;
}
