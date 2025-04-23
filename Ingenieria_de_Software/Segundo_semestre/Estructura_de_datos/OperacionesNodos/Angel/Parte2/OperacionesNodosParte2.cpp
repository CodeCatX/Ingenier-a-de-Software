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

bool hasValue(Nodo *head, int value){
    if (isEmpty(head)) return false;

    if (head -> value == value){
        return true;
    } else {
        return hasValue(head -> nextNdo, value);
    }
}


void insert(Nodo *&head, int value){
    if (isEmpty(head)){
        head = createNodo(value);
    } else if (head -> nextNdo == nullptr){
       head -> nextNdo = createNodo(value);
    } else {
        insert(head -> nextNdo, value);
    }
}


int find(Nodo *head, int value){
    if (isEmpty(head)) return -1;

    if (head -> value == value){
        return 0;
    }else {
        int result = find(head -> nextNdo, value);
        if (result == -1){
            return -1;
        }else {
            return 1 + result;
        }
    }
}


void update(Nodo *&head, int value, int newValue){
    if (!isEmpty(head)){
        if (head -> value == value){
            head -> value = newValue;
        }else {
            update(head -> nextNdo, value, newValue);
        }
    }
}


void removeDuplicates(Nodo *head, Nodo *&newList){
    if (!isEmpty(head)){
        if (!hasValue(newList, head -> value)){
            insert(newList, head -> value);
            removeDuplicates(head -> nextNdo, newList);
        } else {
            removeDuplicates(head -> nextNdo, newList);
        }
    }
}


void removeDuplicatesIterative(Nodo *head, Nodo *&newList){
    Nodo *currentNodo = head;
    while (!isEmpty(currentNodo)){
        if (!hasValue(newList, currentNodo -> value)){
            insert(newList, currentNodo -> value);
        }
        currentNodo = currentNodo -> nextNdo;
    }
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

        insert(head, value);

        cout << "-- [new list] --" << endl;
        printList(head);

        cout << "Nodo with value [" << value << "] was created" << endl;
    }

    printList(head);

    cout << "Enter a number whose position you want to know: ";
    int findNumber;
    cin >> findNumber;
    int i = find(head, findNumber);

    cout << "value " << findNumber << " found in the position: " << i << endl;

    int oldValue;
    cout << "Enter a number you want update: ";
    cin >> oldValue;

    int newValueUpdated;
    cout << "Enter the new value: ";
    cin >> newValueUpdated;

    update(head, oldValue, newValueUpdated);

    cout << "-- [new list] --" << endl;
    printList(head);

    Nodo *newList = nullptr;

    removeDuplicatesIterative(head, newList);
    cout << "-- [new list without duplicates iterative] --" << endl;

    printList(newList);

    Nodo *newListRecursiva = nullptr;

    removeDuplicates(head, newListRecursiva);

    cout << "-- [new list without duplicates recursive] --" << endl;

    printList(newListRecursiva);

    cleanup(head);
    cleanup(newList);
    cleanup(newListRecursiva);

    cout << "Program finalized successfully" << endl;
    getch();

    return 0;
}