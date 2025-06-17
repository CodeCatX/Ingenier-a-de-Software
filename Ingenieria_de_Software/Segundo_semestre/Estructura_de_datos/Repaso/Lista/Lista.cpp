#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
};

Nodo *crearNodo(int x) {
    Nodo *ap = new Nodo;
    ap -> dato = x;
    ap -> sig = nullptr;
    return ap;
}

void imprimirRecursivo(Nodo *head) {
    if (head != nullptr) {
        cout << head -> dato << " ";
        imprimirRecursivo(head -> sig);
    }
}

void insertarOrdenado(Nodo *&head, int x) {
    Nodo *nuevo = crearNodo(x);
    bool insertado = false;
    if (head == nullptr || head -> dato > x) {
        nuevo -> sig = head;
        head = nuevo;
    } else {
        Nodo *actual = head;
        while (actual -> sig != nullptr && actual -> sig -> dato <= x) {
            actual = actual -> sig;
        }
        nuevo -> sig = actual -> sig;
        actual -> sig = nuevo;
    }
}

void eliminar(Nodo *&head, int x) {
    if (head != nullptr) {
        if (head -> dato == x) {
            Nodo *aux = head;
            head = head -> sig;
            delete aux;
            eliminar(head, x);
        } else {
            eliminar(head -> sig, x);
        }
    }
}

void buscar(Nodo *head, int x) {
    if (head != nullptr) {
        if (head -> dato == x) {
            cout << "\nEl dato " << head -> dato << " fue encontrado.\n";
        }
        buscar(head -> sig, x);
    }
}

void modificar(Nodo *&head, int x, int y) {
    if (head != nullptr) {
        if (head -> dato == x) {
            head -> dato = y;
        }
        modificar(head -> sig, x, y);
    }
}

bool estaVacia(Nodo *head) {
    return (head == nullptr);
}

int posicion(Nodo *head, int x) {
    if (head == NULL) {
        return -1;
    }
    if (head -> dato == x) {
        return 0;
    } else {
        int result = posicion(head -> sig, x);
        if (result == -1) {
            return -1;
        } else {
            return 1 + result;
        }
    }
}

bool existe(Nodo *head, int x) {
    if (head != nullptr) {
        if (head -> dato == x) return true;
        return existe(head -> sig, x);
    } else {
        return false;
    }
}

void eliminarDuplicados(Nodo* lista1, Nodo*& lista2) {
    Nodo* actualL1 = lista1;
    while (actualL1 != nullptr) {
        if (!existe(lista2, actualL1->dato)) {
            Nodo* nuevoNodo = crearNodo(actualL1->dato);
            if (lista2 == nullptr) {
                lista2 = nuevoNodo;
            } else {
                Nodo* actualL2 = lista2;
                while (actualL2->sig != nullptr) {
                    actualL2 = actualL2->sig;
                }
                actualL2->sig = nuevoNodo;
            }
        }
        actualL1 = actualL1->sig;
    }
}

void eliminarDuplicadosRecursivo(Nodo* lista1, Nodo*& lista2) {
    if (lista1 != nullptr) {
        if (!existe(lista2, lista1 -> dato)) {
            Nodo *nuevoNodo = crearNodo(lista1 -> dato);
            if (lista2 == nullptr) {
                lista2 = nuevoNodo;
            } else {
                Nodo *actualLista2 = lista2;
                while (actualLista2 -> sig != nullptr) {
                    actualLista2 = actualLista2 -> sig;
                }
                actualLista2 -> sig = nuevoNodo;
            }
        }
        eliminarDuplicadosRecursivo(lista1 -> sig, lista2);
    }
}

int main() {
    Nodo *head = nullptr;

    insertarOrdenado(head, 1);
    insertarOrdenado(head, 4);
    insertarOrdenado(head, 3);
    insertarOrdenado(head, 2);
    insertarOrdenado(head, 5);
    insertarOrdenado(head, 5);
    imprimirRecursivo(head);
    //eliminar(head, 5);
    cout << endl;
    //buscar(head, 5);
    //modificar(head, 5, 6);
    imprimirRecursivo(head);
    cout << endl << estaVacia(head);
    cout << endl << "Posicion del numero 5: " << posicion(head, 5);
    Nodo *lista2 = nullptr;
    eliminarDuplicadosRecursivo(head, lista2);
    cout << endl;
    imprimirRecursivo(lista2);
    return 0;
}