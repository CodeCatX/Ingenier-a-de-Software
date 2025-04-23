#include <iostream>
using namespace std;

int longitud(string cad) {
    int contador = 0;
    while (cad[contador] != '\0') {
        contador++;
    }
    return contador;
}

int main() {
    string cadena = "Hola mundo, este es un programa que calcula la longitud de una cadena de texto";
    string cadena2 = "Hola mundo cruel";
    string cadena3 = "conteo";
    cout << longitud(cadena3);
}
