/* 
Realice un procedimiento que incremente el valor de i.
 void incrementa(int &i)
*/

#include <iostream>
using namespace std;

void incrementa(int &i) {
    i += 1;
}

int main() {
    int i;
    cout << "Asignale un valor a i: " ;
    cin >> i;

    incrementa(i);

    cout << "i + 1 = " << i;

    return 0;
}