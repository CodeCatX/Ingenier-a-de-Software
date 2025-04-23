#include <iostream>
using namespace std;
int main () {
    //Suma para n+1 términos. n > 1.
    float n;
    cin >> n;
    float sumaTerminos = 0;
    float terminos = 0;
    for (float i = 2; i <= n; i++) {
        sumaTerminos += i/(i+1);
    }
    cout << sumaTerminos;

    return 0;
}
