/**
2 4 6 11 34 7
El número que ha roto la secuencia ascendente: 7
La cantidad de números introducidos: 6
*/
#include <iostream>
using namespace std;
int main () {
    int n1;
    int n2;

    cout << "Ingrese una secuencia de numeros cada uno mayor que el anterior: \n";
    cin >> n1;
    cin >> n2;
    int contador = 2;
    while (n2 > n1) {
        cin >> n1;
        cin >> n2;
        contador += 2;
    }

    cout << "El numero que rompio la secuencia fue: " << n2 << endl;
    cout << "La cantidad de numeros introducidos fueron: " << contador;

    return 0;
}
