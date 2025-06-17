#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
};

bool vacia(Nodo *tope) {
    return (tope == nullptr);
}

void imprimirRecursivo(Nodo *tope) {
    if (tope != nullptr) {
        cout << tope -> dato << " ";
        imprimirRecursivo(tope -> sig);   
    }
}

void inicializar(Nodo *&tope) {
    tope = nullptr;
}

void push(Nodo *&tope, int elemento) {
    Nodo *aux = new Nodo;
    aux -> dato = elemento;
    aux -> sig = tope;
    tope = aux;
}

void pop(Nodo *&tope, int &elemento) {
    Nodo *aux;
    if(!vacia(tope)) {
        aux = tope;
        elemento = tope -> dato;
        tope = tope -> sig;
        delete aux;
    }
}

void consultarTope(Nodo *tope, int &elemento) {
    if (tope != nullptr) {
        elemento = tope -> dato;
    }
}

int main() {
    Nodo *tope;
    inicializar(tope);
    push(tope, 5);
    push(tope, 6);
    imprimirRecursivo(tope);
    
    int elemento;
    consultarTope(tope, elemento);
    cout << endl << elemento;
    
    return 0;
}