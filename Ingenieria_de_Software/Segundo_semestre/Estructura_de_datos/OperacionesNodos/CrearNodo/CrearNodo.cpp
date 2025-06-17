#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
};

int main() {
    int n;
    cout << "Inserta el tamaño de la lista: ";
    cin >> n;
    // Primer nodo
    Nodo *head = NULL;
    Nodo *p = NULL;
    p = new Nodo;
    p -> dato = 5;
    p -> sig  = NULL;
    head = p;

    // Segundo nodo
    Nodo *ap = NULL;
    ap = new Nodo;
    ap -> dato = 6;
    ap -> sig = NULL;
    p -> sig = ap;

    cout << ap->dato << endl;
    return 0;
}