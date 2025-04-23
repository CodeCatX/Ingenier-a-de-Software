#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo { // estructura del nodo
    char element;
    Nodo *nextNdo;
};

// Funciones auxiliares ////////////////////////////////////////////////////
bool isEmpty(Nodo *nodo){ // verifica si el nodo esta vacio (es nulo)
    return nodo == nullptr;
}


bool isUpper(char element){ // verifica si el elemento es una letra mayuscula
    return element >= 65 && element <= 90;
}


bool isLower(char element){ // verifica si el elemento es una letra minuscula
    return element >= 97 && element <= 122;
}


char toUpper(char element){
    return isLower(element) ? element - 32 : element;
}


void release(Nodo *&nodo){ // libera la memoria que ocupaba el nodo
    delete nodo;
    nodo = nullptr;
}


Nodo *createNodo(char newElement){ // crea un nodo
    Nodo *ptr = new Nodo;
    ptr -> element = newElement;
    ptr -> nextNdo = nullptr;
    return ptr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones de la pila ///////////////////////////////////////////////////////////////////////////////////
void push(Nodo *&top, char newElement){ // agrega un nuevo valor al tope de la pila
    Nodo *aux;
    aux = new Nodo;
    aux ->element = newElement;
    aux ->nextNdo = top;
    top = aux;
}


char pop(Nodo *&top){ // remueve el tope de la pila
    if (isEmpty(top)) return '\0';
    Nodo *aux;
    aux = top;
    char element = aux ->element;
    top = top ->nextNdo;
    release(aux);
    return element;
}


void clearStack(Nodo *&top){
    if (!isEmpty(top)){
        pop(top);
        clearStack(top);
    }
}


char getTop(Nodo *top){ // retorna el tope de la pila
    if (!isEmpty(top)){
        return top ->element;
    } else {
        return '\0';
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones de la cola ///////////////////////////////////////////////////////////////////////////////////
void enqueue(Nodo *&front, Nodo *&back, char value){ // agrega un nuevo valor al final de la cola
    Nodo *newNodo = createNodo(value);
    if (isEmpty(front)){
        front = newNodo;
    } else {
        back -> nextNdo = newNodo;
    }
    back = newNodo;
}


char dequeue(Nodo *&front, Nodo *&back){ // remueve el frante de la cola
    Nodo *aux = front;
    char element = aux -> element;
    front = front -> nextNdo;
    if (isEmpty(front)){
        back = nullptr;
    }
    release(aux);
    return element;
}


void clearQueue(Nodo *&front, Nodo *&back){
    if (!isEmpty(front)){
        dequeue(front, back);
        clearQueue(front, back);
    }
}


char getFront(Nodo *front){ // regresa el frente de la cola
    if (!isEmpty(front)){
        return front ->element;
    } else {
        return '\0';
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones principales //////////////////////////////////////////////////////////////////////////////////
bool isPalindromo(Nodo *&top, Nodo *&front, Nodo *&back){ // verifica si la palabra guardada en las estructuras pila y cola es un palindromo
    bool result = true;
    while (result && !isEmpty(top) && !isEmpty(front)){
        if (getTop(top) == getFront(front)){
            dequeue(front, back);
            pop(top);
        } else {
            result = false;
        }
    }

    return result;
}


void loadStackAndQueue(Nodo *&top, Nodo *&front, Nodo *&back, string phrase){ // asgina cada caracter de la frase en las estructuras pila y cola
    int i = 0;
    while (phrase[i] != '\0')
    {
        enqueue(front, back, phrase[i]);
        push(top, phrase[i]);
        i++;
    }
}


string filterPhrase(string phrase){ // funcion para filtrar la frase por una cadena que contiene unicamente letras mayusculas
    string filteredPhrase = "";
    int i = 0;
    while (phrase[i] != '\0')
    {
        if (isLower(phrase[i])){
            char higher = toUpper(phrase[i]);
            filteredPhrase += higher;
        } else if (isUpper(phrase[i])){
            filteredPhrase += phrase[i];
        }
        i++;
    }
    return filteredPhrase;
}


string requirePhrase(){ // requiere la frase al usuario y la retorna
    string phrase;
    cout << "ingresa la frase que quieres comprobar si es un palindromo: ";
    getline(cin, phrase);
    return phrase;
}


void init(Nodo *&top, Nodo *&front, Nodo *&back){ // funcion para iniciar el programa
    top = nullptr;
    front = nullptr;
    back = nullptr;
}


void start(Nodo *&top, Nodo *&front, Nodo *&back){ // funcion para empezar el programa
    string originalPhrase = requirePhrase();
    string filteredPhrase = filterPhrase(originalPhrase);
    loadStackAndQueue(top, front, back, filteredPhrase);
    bool result = isPalindromo(top, front, back);
    if (result){
        cout << filteredPhrase + " es un palindromo" << endl;
    } else {
        cout << filteredPhrase + " no es un palindromo" << endl;
    }
}


void cleanup(Nodo *&top, Nodo *&front, Nodo *&back){ // funcion para limpiar la memoria
    clearStack(top);
    clearQueue(front, back);
}


int main(){
    Nodo *top, *front, *back;
    init(top, front, back);
    start(top, front, back);
    cleanup(top, front, back);
    getch();
    return 0;
}