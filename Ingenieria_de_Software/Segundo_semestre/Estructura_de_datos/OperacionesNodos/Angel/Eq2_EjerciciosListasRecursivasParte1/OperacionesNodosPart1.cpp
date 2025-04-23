#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int value;
    Nodo *nextNdo;
};

bool isEmpty(Nodo *nodo){
    if (nodo == nullptr)
        return true;
    else
        return false;
}


Nodo *createNodo(int value){
    Nodo *ptr = new Nodo;
    ptr -> value = value;
    ptr -> nextNdo = nullptr;
    return ptr;
}


void iterativeRemove(Nodo *&head, int value){
    if (!isEmpty(head)){
        while ((!isEmpty(head) && head -> value == value)){
            Nodo *aux = head -> nextNdo;
            delete head;
            head = aux;
        }
    
        Nodo *currentNodo = head;
        while (!isEmpty(currentNodo) && !isEmpty(currentNodo -> nextNdo)){
            if (currentNodo -> nextNdo -> value == value){
                Nodo *aux = currentNodo -> nextNdo -> nextNdo;
                delete currentNodo -> nextNdo;
                currentNodo -> nextNdo = aux;
            } else {
                currentNodo = currentNodo -> nextNdo;
            }
        }
    }
}


void iterativeOrderedInser(Nodo *&head, int value){
    if (isEmpty(head) || head -> value > value){
        Nodo *newNodo = createNodo(value);
        newNodo -> nextNdo = head;
        head = newNodo;
    } else {
        Nodo *currentNodo = head;
        while (!isEmpty(currentNodo) && !isEmpty(currentNodo -> nextNdo) && currentNodo -> nextNdo -> value <= value){
            currentNodo = currentNodo -> nextNdo;
        }
        Nodo *newNodo = createNodo(value);
        newNodo -> nextNdo = currentNodo -> nextNdo;
        currentNodo -> nextNdo = newNodo;
    }
}


void printList(Nodo *n){
    if (n != nullptr){
       cout << n -> value << endl;
       printList(n -> nextNdo);
    }
}


void cleanup(Nodo *head){
    if (head != nullptr){
        Nodo *aux = head -> nextNdo;
        delete head;
        cleanup(aux);
    }
}


int main(){
    Nodo *head = nullptr;

    cout << "Enter the length of your list: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Enter a number: ";
        int value;
        cin >> value;

        iterativeOrderedInser(head, value);

        cout << "-- [new list] --" << endl;
        printList(head);

        cout << "Nodo with value [" << value << "] was created" << endl;
    }

    printList(head);


    int newValue;
    cout << "Enter the number you want remove: ";
    cin >> newValue;

    iterativeRemove(head, newValue);

    cout << "-- [new list] --" << endl;
    printList(head);

    cleanup(head);

    cout << "Program finalized successfully" << endl;
    getch();

    return 0;
}