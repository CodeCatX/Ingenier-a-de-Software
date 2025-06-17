#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

Nodo *crearNodo(int x) {
    Nodo *ap = new Nodo;
    ap -> dato = x;
    ap -> sig = nullptr;
    return ap;
}

void inicializar(Nodo *&tope) {
    tope = nullptr;
}

bool vacia(Nodo *tope) {
    return (tope == nullptr);
}

void push(Nodo *&tope, int x) {
    Nodo *nuevoNodo = crearNodo(x);
    nuevoNodo -> sig = tope;
    tope = nuevoNodo;
}

int pop(Nodo *&tope) {
    if (tope != nullptr) {
        Nodo *aux = tope;
        int valor = tope -> dato;
        tope = tope -> sig;
        delete aux;
        return valor;
    } else {
        return -1;
    }
}

void imprimirPila(Nodo *tope) {
    if (tope != nullptr) {
        cout << tope -> dato << " ";
        imprimirPila(tope -> sig);
    }
}

int main() {
    // Creación de los nodos frente y final
    Nodo *tope;
    inicializar(tope);
    push(tope, 1);
    push(tope, 2);
    push(tope, 3);
    push(tope, 4);
    push(tope, 5);
    push(tope, 6);
    pop(tope);
    imprimirPila(tope); cout << endl;

    return 0;
}