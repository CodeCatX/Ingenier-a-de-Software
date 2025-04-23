#include <iostream>
using namespace std;

int longitud(string cad) {
    int contador = 0;
    while (cad[contador] != '\0') {
        contador++;
    }
    return contador;
}

string iniciales(string cad) {
    int lCad = longitud(cad);
    int i = 0;
    string ini = "";
    ini = cad[i];


    while (i < lCad) {
        if (cad[i] == ' ') {
            ini += cad[i+1];
        }
        i++;
    }
    return ini;

}


int main() {
    string cadena = "Hoy no se come";
    cout << iniciales(cadena);
}
