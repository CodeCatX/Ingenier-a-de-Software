#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = n;
    int binario = 0;
    int factor = 1;

    while (num > 0) {
        int residuo = num % 2;
        binario += residuo * factor;
        num /= 2;
        factor *= 10;
    }

    cout << binario << endl;
    return 0;
}
