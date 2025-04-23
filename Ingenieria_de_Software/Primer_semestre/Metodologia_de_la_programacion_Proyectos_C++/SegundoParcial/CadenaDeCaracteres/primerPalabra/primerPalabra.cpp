#include <iostream>
using namespace std;

int longitud(string cad) {
    int contador = 0;
    while (cad[contador] != '\0') {
        contador++;
    }
    return contador;
}

string palabra1(string cad) {
    int l = longitud(cad);
    string primeraPalabra = "";
    int i = 0;
    while (i < l && cad[i] != ' ') {
            primeraPalabra += cad[i];
        i++;
    }
    return primeraPalabra;

}

int main() {
    string cadena = "Hola mundo, este es un programa que calcula la longitud de una cadena de texto";
    string cadena2 = "Hola mundo cruel";
    cout << palabra1(cadena2);
    cout << endl << "Longitud: " << longitud(cadena2) << endl;
}
