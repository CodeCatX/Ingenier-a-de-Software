#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
};

void inicializar(Nodo *&raiz) {
    raiz = nullptr;
}

bool vacio(Nodo *raiz) {
    return (raiz == nullptr);
}

bool esHoja(Nodo *nodo) {
    if (nodo == nullptr) {
        return false;
    }
    return (nodo->izq == nullptr && nodo->der == nullptr);
}

// Función para buscar un dato y evaluar si está duplicado
void buscar(Nodo *&raiz, int elementoAInsertar, Nodo *&anterior, Nodo *&actual) {
    bool encontrado = false;
    anterior = nullptr;
    actual = raiz;
    while (!encontrado && actual != nullptr) {
        if (actual -> dato == elementoAInsertar) {
            encontrado = true;
        } else {
            anterior = actual;
            if (actual -> dato > elementoAInsertar) {
                actual = actual -> izq;
            } else {
                actual = actual -> der;
            }
        }
    }

    if (!encontrado) {
        cout << "\nNo existe el elemento.";
    } else {
        cout << "\nSe encontro el elemento.";
    }
}

// Función para insertar un dato en el árbol
void insertar(Nodo *&raiz, int elementoAInsertar) {
    Nodo *nuevo, *actual, *anterior;
    buscar(raiz, elementoAInsertar, anterior, actual);
    if (actual != nullptr) {
        cout << "\nElemento duplicado.\n";
    } else {
        nuevo = crearNodo(elementoAInsertar);
        if (anterior == nullptr) {
            raiz = nuevo;
        } else {
            if (anterior -> dato > elementoAInsertar) {
                anterior -> izq = nuevo;
            } else {
                anterior -> der = nuevo;
            }
        }
    }
}

void inorden(Nodo *raiz) {
    if (raiz != nullptr) {
        inorden(raiz -> izq);
        cout << " " << raiz -> dato;
        inorden(raiz -> der);
    }
}

void preorden(Nodo *raiz) {
    if (raiz != nullptr) {
        cout << " " << raiz -> dato;
        preorden(raiz -> izq);
        preorden(raiz -> der);
    }
}

void postorden(Nodo *raiz) {
    if (raiz != nullptr) {
        postorden(raiz -> izq);
        postorden(raiz -> der);
        cout << " " << raiz -> dato;
    }
}

int contarNodos(Nodo *raiz) {
    if (!vacio(raiz)) {
        return 1 + contarNodos(raiz -> der) + contarNodos(raiz -> izq);
    } else {
        return 0;
    }
}

void auxAltura(Nodo *&nodo, int a, int &altura) {
    if (nodo -> izq) {
        auxAltura(nodo -> izq ,a+1, altura);
    }
    if (nodo -> der) {
        auxAltura(nodo -> der ,a+1, altura);
    }
    if (esHoja(nodo) && a > altura) {
        altura = a;
    }
}

int alturaArbol(Nodo *&raiz) {
    int altura = 0;
    auxAltura(raiz, 0, altura);
    return altura+1;
}

int main() {
    Nodo *raiz;
    inicializar(raiz);

    insertar(raiz, 4);
    insertar(raiz, 3);
    insertar(raiz, 7);
    insertar(raiz, 9);
    insertar(raiz, 1);

    cout << "\nIn-orden: ";
    inorden(raiz);

    // Número de nodos
    int numeroElementos = contarNodos(raiz);
    cout << "\nEl arbol tiene " << numeroElementos << " elementos.";

    // Altura del árbol
    cout << "\nLa altura del arbol es de " << alturaArbol(raiz) << " elementos.";

    return 0;
}