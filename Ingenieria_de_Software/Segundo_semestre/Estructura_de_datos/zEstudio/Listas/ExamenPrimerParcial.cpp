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

void insertarDato(Nodo *&head, int datoAInsertar) {
    if (head == nullptr) {
        head = crearNodo(datoAInsertar);
    } else {
        if (head -> sig == nullptr) {
            head -> sig = crearNodo(datoAInsertar);
        } else {
            insertarDato(head -> sig, datoAInsertar);
        }
    }
}

void imprimirLista(Nodo *head) {
    if (head != nullptr) {
        cout << head -> dato << " ";
        imprimirLista(head -> sig);
    }
}

// Sumar nones
int sumarNones(int arr[], int n) {
    if (n <= 0) {
        return 0;
    } else {
        if (arr[n] % 2 != 0) {
            return arr[n] + sumarNones(arr, n-1);
        } else {
            return sumarNones(arr, n-1);
        }
    }
}

// Eliminar datoX de una lista
void eliminarX(Nodo *&head, int datoX) {
    if (head != nullptr) {
        if (head -> dato == datoX) {
            Nodo *aux = head;
            head = head -> sig;
            delete aux;
            eliminarX(head, datoX);
        } else {
            eliminarX(head -> sig, datoX);
        }
    }
}

// Formarse
void formarse(Nodo *&front, Nodo *&queue, int datoX) {
    Nodo *nuevoDato = crearNodo(datoX);
    if (queue == nullptr) {
        front = nuevoDato;
        queue = front;
    } else {
        queue -> sig = nuevoDato;
    }
    queue = nuevoDato;
}

int desformarse(Nodo *&front, Nodo *&queue) {
    Nodo *aux = front;
    int elemento = aux -> dato;
    front = front -> sig;
    if (front == nullptr) {
        queue = front;
    }
    delete aux;
    return elemento;
}

int main() {
    // Sumar numeros nones
    int n = 8;
    int arr[n] = { 2, 3, 3, 6, 4, 8, 10, 11 };
    cout << "\033[33mResultado de la función \033[35msumarNones\033[0m: \033[0m" << sumarNones(arr, n);
    
    // Eliminar datoX de una lista
    Nodo *head = nullptr;
    int datoX;
    //cout << "\nIngrese el valor a eliminar de la lista: ";
    //cin >> datoX

    cout << endl;
    insertarDato(head, 2);
    insertarDato(head, 3);
    insertarDato(head, 3);
    insertarDato(head, 6);
    insertarDato(head, 4);
    insertarDato(head, 8);
    insertarDato(head, 10);
    insertarDato(head, 11);
    imprimirLista(head);
    cout << endl;

    // Eliminar el dato con valor 3
    eliminarX(head, 3);
    imprimirLista(head);
    
    // Formarse
    cout << endl << "Formarse" << endl;
    Nodo *front = nullptr;
    Nodo *queue = nullptr;
    formarse(front, queue, 1);
    formarse(front, queue, 2);
    formarse(front, queue, 3);
    formarse(front, queue, 4);
    formarse(front, queue, 5);
    formarse(front, queue, 6);
    imprimirLista(front);

    // Despachar
    cout << endl << "Despachar" << endl;
    desformarse(front, queue);
    imprimirLista(front);

    return 0;
}