#include <iostream>
using namespace std;
int main (){
    int n;
    int factorial = 1;
    cin >> n;
    cout << n << "! = " << n << " x ";

    for (int i = 1; i <= n; i++) {
        if (i < n) {
            cout << (n - i);
        }
        factorial = factorial * (i);
        if ((n - i) > 1) {
            cout << " x ";
        }
    }
        cout << " = " << factorial;

    return 0;
}
