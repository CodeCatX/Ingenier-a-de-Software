#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
};

Nodo *crearNodo(int datoNodo) {
    Nodo *ap = new Nodo;
    ap -> dato = datoNodo;
    ap -> sig = nullptr;
    return ap;
}

void push(Nodo *&tope, int datoAInsertar) {
    Nodo *nuevoNodo = crearNodo(datoAInsertar);
    if (tope == nullptr) {
        tope = nuevoNodo;
    } else {
        nuevoNodo -> sig = tope;
        tope = nuevoNodo;
    }
}

void imprimirLista(Nodo *head) {
    if (head != nullptr) {
        cout << head -> dato << " ";
        imprimirLista(head -> sig);
    }
}

Nodo *convertirPilaCola(Nodo *pila, Nodo *&cola) {
    Nodo *actualPila = pila;
    while (actualPila != nullptr) {
        Nodo *nuevoNodo = crearNodo(actualPila -> dato);
        Nodo *actualCola = cola;
        if (actualCola == nullptr) {
            cola = nuevoNodo;
        } else {
            while (actualCola -> sig != nullptr) {
                actualCola = actualCola -> sig;
            }
            actualCola -> sig = nuevoNodo;
        }
        actualPila = actualPila -> sig;
    }
    return cola;
}

int main() {
    // Eliminar datoX de una lista
    Nodo *pila = nullptr;
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    
    cout << endl;
    push(pila, 1);
    push(pila, 2);
    push(pila, 3);
    push(pila, 4);
    push(pila, 5);
    push(pila, 6);
    
    Nodo *cola = nullptr;
    frente = convertirPilaCola(pila, cola);
    imprimirLista(cola);
    
    cout << endl;

    cout << "Cola:" << endl;
    imprimirLista(frente);

    return 0;
}