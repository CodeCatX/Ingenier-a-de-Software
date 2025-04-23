#include <iostream>
using namespace std;

struct Nodo {
    char letter;
    Nodo *next;
};

bool empty(Nodo *stackTop) {
    return (stackTop == nullptr);
}

// Inicializar
void init(Nodo *&stackTop, Nodo *&queueFront, Nodo *& queueRear) {
    stackTop = nullptr;
    queueFront = nullptr;
    queueRear = nullptr;
}

// Meter un elemento a la pila
void push(Nodo *&stackTop, char letterToInput) {
    Nodo *aux = new Nodo;
    aux -> letter = letterToInput;
    aux -> next = stackTop;
    stackTop = aux;
}

// Sacar un elemento de la pila
void pop(Nodo *&stackTop, char &element) {
    Nodo *aux;
    if (!empty(stackTop)) {
        aux = stackTop;
        element = stackTop -> letter;
        stackTop = stackTop -> next;
        delete aux;
    }
}

// Meter un elemento a la cola
void enqueue(Nodo *&queueFront, Nodo *&queueRear, char letterToInput) {
    Nodo *aux = new Nodo;
    aux -> letter = letterToInput;
    aux -> next = nullptr;
    if (queueRear == nullptr) {
        queueFront = aux;
    } else {
         queueRear -> next = aux;
    }
    queueRear = aux;
}

// Imprimir lista
void printRecursive(Nodo *stackTop) {
    if (stackTop != nullptr) {
        cout << stackTop -> letter << " ";
        printRecursive(stackTop -> next);
    }
}

// Limpiar memoria
void clearMemory(Nodo*& listHead) {
    if (listHead != nullptr) {
        pop(listHead, listHead -> letter);
        clearMemory(listHead);
    }
}

// Ingresar frase
string requestPhrase() {
    string phrase;
    cout << "Escriba una frase: ";
    getline(cin, phrase);
    return phrase;
}

// Rellenar la pila y cola con las letras de la frase ingresada por el usuario
void fillStackAndQueue(Nodo *&stackTop, Nodo *&queueFront, Nodo *&queueRear) {
    string phrase = requestPhrase();
    char letter;
    int i = 0;
    while (phrase[i] != '\0') {
        if (phrase[i] != ' ') {
            if (phrase[i] >= 'a' && phrase[i] <= 'z') {
                phrase[i] -= 32;
            }
            push(stackTop, phrase[i]);
            enqueue(queueFront, queueRear, phrase[i]);
        }
        i++;
    }
}

bool esPalindromo(Nodo *stackTop, Nodo *queueFront) {
    if (stackTop != nullptr) {
        if (stackTop->letter != queueFront->letter) {
            return false;
        }
        return esPalindromo(stackTop->next, queueFront->next);
    } else {
        return true;
    }
}


int main() {
    cout << "----- Evaluar si una frase es palindromo -----\n";

    Nodo *stackTop, *queueFront, *queueRear;
    init(stackTop, queueFront, queueRear);
    fillStackAndQueue(stackTop, queueFront, queueRear);
    cout << esPalindromo(stackTop, queueFront);
    cout << endl;
    clearMemory(stackTop);
    clearMemory(queueFront);
    return 0;
}