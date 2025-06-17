#include <iostream>
using namespace std;

// Estructura Nodo
struct Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
};

// Función para crear un nodo
Nodo *crearNodo(int datoNodo) {
    Nodo *ap = new Nodo;
    ap -> dato = datoNodo;
    ap -> izq = nullptr;
    ap -> der = nullptr;

    return ap;
}

// Función para verificar si un nodo es hoja
bool esHoja(Nodo *nodo) {
    if (nodo -> izq == nullptr && nodo -> der == nullptr) {
        return true;
    } else {
        return false;
    }
}

// Función para buscar un dato y evaluar si está duplicado
bool buscar(Nodo *&raiz, int x) {
    bool encontrado = false;
    Nodo *actual = raiz;
    while (!encontrado && actual != nullptr) {
        if (actual -> dato == x) {
            encontrado = true;
        } else {
            if (actual -> dato > x) {
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
    return encontrado;
}

// Función para insertar un dato en el árbol
void insertar(Nodo *&raiz, int elementoAInsertar) {
    bool encontrado = buscar(raiz, elementoAInsertar);
    Nodo *anterior = nullptr;
    Nodo *actual = raiz;

    if (!encontrado) {
        Nodo *nuevo = crearNodo(elementoAInsertar);
        while (actual != nullptr) {
            anterior = actual;
            if (actual -> dato > elementoAInsertar) {
                actual = actual -> izq;
            } else {
                actual = actual -> der;
            }
        }
        if (anterior == nullptr) {
            raiz = nuevo;
        } else if (anterior -> dato > elementoAInsertar) {
            anterior -> izq = nuevo;
        } else {
            anterior -> der = nuevo;
        }
    }
}

// Función para eliminar un dato en el árbol
void eliminar(Nodo *&raiz, int elementoAEliminar) {
    Nodo *padre = nullptr; Nodo *actual = raiz; Nodo *nodo = nullptr; int aux; bool termina = false;
    while((actual != nullptr && termina != true)) {
        if (elementoAEliminar == actual -> dato) {
            if (esHoja(actual)) {
                if (padre != nullptr) {
                    if (padre -> der == actual) padre -> der = nullptr;
                    else
                    if (padre -> izq == actual) padre -> izq = nullptr;
                }
                delete actual;
                actual = nullptr; termina = true;
            } else {
                padre = actual;
                if (actual -> der = nullptr) {
                    nodo = actual -> izq;
                    while (nodo -> izq != nullptr) {
                        padre = nodo;
                        nodo = nodo -> izq;
                    }
                } else {
                    nodo = actual -> der;
                    while (nodo -> der != nullptr) {
                        padre = nodo;
                        nodo = nodo -> der;
                    }
                }
                aux = actual -> dato;
                actual -> dato = nodo -> dato;
                nodo -> dato = aux;
                actual = nodo;
            }
        } else {
            padre = actual;
            if (elementoAEliminar > actual -> dato) actual = actual -> der;
            else
                if (elementoAEliminar < actual -> dato) actual = actual -> izq;
        }
    }
}

// Función para imprimir los datos del arbol en recorrido inorden
void inorder(Nodo *raiz) {
    if (raiz != nullptr){
        inorder(raiz -> izq);
        cout << raiz -> dato << " ";
        inorder(raiz -> der);
    }
}

// Función para imprimir los datos del arbol en recorrido preorden
void preorden(Nodo *raiz) {
    if (raiz != nullptr){
        cout << raiz -> dato << " ";
        preorden(raiz -> izq);
        preorden(raiz -> der);
    }
}

// Función para imprimir los datos del arbol en recorrido postorden
void postorden(Nodo *raiz) {
    if (raiz != nullptr){
        postorden(raiz -> izq);
        postorden(raiz -> der);
        cout << raiz -> dato << " ";
    }
}

int main() {
    Nodo *raiz = nullptr;

    // Insertar datos
    insertar(raiz, 1);
    insertar(raiz, 5);
    insertar(raiz, 2);
    insertar(raiz, 4);
    insertar(raiz, 1);

    // Imprimir los datos utilizando los 3 recorridos
    cout << "\nIn-orden: ";
    inorder(raiz);
    cout << endl;

    cout << "Pre-orden: ";
    preorden(raiz);
    cout << endl;

    cout << "Post-orden: ";
    postorden(raiz);

    // Eliminar un dato
    eliminar(raiz, 3);
    eliminar(raiz, 4);

    cout << "\nIn-orden: ";
    inorder(raiz);
    cout << endl;

    return 0;
}