#include<iostream>
using namespace std;
int main(){
    cout << "Introduce un número de entre 0 a 9999: ";
    int numero;
    cin >>  numero;

    if (numero < 1 || numero > 9999) {
        cout << "No permitido";
    }

    if (numero > 0 && numero < 10){
        cout << "Un dígito";
    }

    if (numero > 9 && numero < 100) {
        cout << "Dos digitos";
    }

    if (numero > 99 && numero < 1000) {
        cout << "Tres digitos";
    }

    if (numero > 999 && numero < 10000) {
        cout << "Cuatro digitos";
    }

return 0;
}
