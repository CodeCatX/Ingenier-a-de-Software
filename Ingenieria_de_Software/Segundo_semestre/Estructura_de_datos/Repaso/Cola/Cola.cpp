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

void inicializar(Nodo *&frente, Nodo *&final) {
    frente = nullptr;
    final = nullptr;
}

int consultarFrente(Nodo *frente) {
    if (frente != nullptr) {
        return frente -> dato;
    } else {
        return -1;
    }
}

bool vacia(Nodo *frente) {
    return (frente == nullptr);
}

int sacar(Nodo *&frente, Nodo *& final) {
    if (frente != nullptr) {
        Nodo *aux = frente;
        int elemento = aux -> dato;
        frente = frente -> sig;
        if (frente == nullptr) {
            final = frente;
        }
        delete aux;
        return elemento;
    } else {
        return -1;
    }
}

void agregar(Nodo *&frente, Nodo *&final, int x) {
    Nodo *nuevoNodo = crearNodo(x);
    if (frente == nullptr) {
        frente = nuevoNodo;
        final = frente;
    } else {
        final -> sig = nuevoNodo;
        final = nuevoNodo;
    }
}

void imprimirCola(Nodo *frente) {
    if (frente != nullptr) {
        cout << frente -> dato << " ";
        imprimirCola(frente -> sig);
    }
}

// Complementarias
int tamanioCola(Nodo *frente) {
    if (frente != nullptr) {
        return 1 + tamanioCola(frente -> sig);
    } else {
        return 0;
    }
}

bool estaLlena(Nodo *frente, int tope) {
    if (tamanioCola(frente) >= tope) {
        return true;
    } else {
        return false;
    }
}

void vaciarCola(Nodo *&frente, Nodo *&final) {
    while (frente != nullptr) {
        Nodo *aux = frente;
        frente = frente -> sig;
        delete aux;
    }
    final = frente;
}

int main() {
    // Creación de los nodos frente y final
    Nodo *frente, *final;
    inicializar(frente, final);
    agregar(frente, final, 1);
    agregar(frente, final, 2);
    agregar(frente, final, 3);
    agregar(frente, final, 4);
    agregar(frente, final, 5);
    imprimirCola(frente); cout << endl;
    vaciarCola(frente, final);

    return 0;
}