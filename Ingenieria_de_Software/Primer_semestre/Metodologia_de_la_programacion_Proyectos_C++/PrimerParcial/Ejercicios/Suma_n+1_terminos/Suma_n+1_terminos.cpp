#include <iostream>
using namespace std;
int main () {
    //Suma para n+1 términos. n > 1.
    int n;
    cin >> n;
    int sumaTerminos = 2;
    for (int i = 2; i < n; i++) {
        sumaTerminos += i+1;
    }
    cout << sumaTerminos;

    return 0;
}
