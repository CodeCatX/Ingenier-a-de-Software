#include <iostream>
using namespace std;
int main () {
    int n1, n2;
    cin >> n1;
    cin >> n2;

    if (n2 % n1 == 0 || n1 % n2 == 0) {
        cout << n2 << " es multiplo de " << n1;
    } else {
        cout << n2 << " no es multiplo de " << n1;
    }

    return 0;
}
