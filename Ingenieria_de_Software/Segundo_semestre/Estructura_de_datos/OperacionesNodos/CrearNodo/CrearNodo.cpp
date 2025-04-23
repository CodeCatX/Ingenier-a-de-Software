#include <iostream>
using namespace std;

struct Nodo {
    int valor;
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
    p -> valor = 5;
    p -> sig  = NULL;
    head = p;

    // Segundo nodo
    Nodo *ap = NULL;
    ap = new Nodo;
    ap -> valor = 6;
    ap -> sig = NULL;
    p -> sig = ap;

    cout << ap->valor << endl;
    return 0;
}