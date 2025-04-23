#include <iostream>
using namespace std;

int contarPalabras(string cad) {
    int contador = 0;
    int palabras = 1;
    while(cad[contador] != '\0') {
        if (cad[contador] == ' ') {
            palabras++;
        }
        contador++;
    }
    return palabras;
}

int main() {
    string cadena = "Hola mundo, este es un programa que calcula la longitud de una cadena de texto";
    string cadena2 = "Hola mundo cruel";
    cout << contarPalabras(cadena);
}
