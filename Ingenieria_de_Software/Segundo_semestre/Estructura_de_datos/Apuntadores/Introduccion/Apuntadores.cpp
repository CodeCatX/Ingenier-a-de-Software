#include <iostream>
using namespace std;

int main() {
    int a[5];
    int *p;
    p = a;
    *p = 3;
    p++; // Avanza 4 bytes = 32 bits
    *p = 8;
    // p = 8; // ESto da error

    cout << "Direccion de memoria: " << p;
    cout << endl;
    cout << *p << endl;


    return 0;
}