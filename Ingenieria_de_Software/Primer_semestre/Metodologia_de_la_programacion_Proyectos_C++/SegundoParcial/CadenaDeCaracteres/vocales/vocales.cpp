#include <iostream>
using namespace std;

int longitud(string cad) {
    int contador = 0;
    while (cad[contador] != '\0') {
        contador++;
    }
    return contador;
}

void vocales(string cad) {
    int contadorA = 0, contadorE = 0, contadorI = 0, contadorO = 0, contadorU = 0;
    int l = longitud(cad);

    for (int i = 0; i < l; i++) {
        switch (cad[i]) {
            case 'a':

                contadorA++;
                break;
            case 'e':
                contadorE++;
                break;
            case 'i':
                contadorI++;
                break;
            case 'o':
                contadorO++;
                break;
            case 'u':
                contadorU++;
                break;
        }
    }

    cout << "a: ";
    for (int i = 0; i < contadorA; i++) cout << "*";

    cout << "\ne: ";
    for (int i = 0; i < contadorE; i++) cout << "*";

    cout << "\ni: ";
    for (int i = 0; i < contadorI; i++) cout << "*";

    cout << "\no: ";
    for (int i = 0; i < contadorO; i++) cout << "*";

    cout << "\nu: ";
    for (int i = 0; i < contadorU; i++) cout << "*";
}



int main() {
    string cadena = "Hola mundo cruel";
    vocales(cadena);
}
