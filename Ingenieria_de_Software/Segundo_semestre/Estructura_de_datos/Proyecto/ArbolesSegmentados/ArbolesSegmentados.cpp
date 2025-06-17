#include <iostream>
#include <conio.h>
using namespace std;

// Estructura Node
struct Node {
    int rangeStart;
    int rangeEnd; 
    int minIndex;
    Node *left;
    Node *right;
};

Node *createNode(int start, int end){
    Node *newNode = new Node;
    newNode -> rangeStart = start;
    newNode -> rangeEnd = end;
    newNode -> minIndex = -1;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    return newNode;
}

int rangeMinQuery(Node *root, int arr[], int start, int end){
    if (root == nullptr || start > root -> rangeEnd || end < root -> rangeStart){
        return -1;
    }

    if (start <= root -> rangeStart && end >= root -> rangeEnd){
        return root -> minIndex;
    } else {
        int leftIdx  = rangeMinQuery(root -> left, arr, start, end);
        int rightIdx = rangeMinQuery(root -> right, arr, start, end);

        if (leftIdx  == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;

        return (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
    }
}


Node *build(int arr[], int start, int end){
    Node *newNode = createNode(start, end);
    if (start == end){
        newNode -> minIndex = start;
    } else {
        int mid = (start + end) / 2;
        newNode -> left = build(arr, start, mid);
        newNode -> right = build(arr, mid + 1, end);

        int leftIdx  = newNode -> left -> minIndex;
        int rightIdx = newNode -> right -> minIndex;
        newNode -> minIndex = (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
    }
    return newNode;
}

// Funciones usadas para construir el arbol
void validateSize(int &size){
    while (size < 1) {
        cout << "Digite un tamaño válido: ";
        cin >> size;
    }
}

void fillArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        int value;
        cout << "Digite el valor de "<<i << ": " << endl;
        cin >> value;
        arr[i] = value;
    }
}

// Funciones usadas en la opción 1
void validateStart(int &start, int size) {
    cout << "Ingrese el valor inicial: ";
    cin >> start;
    while (start < 0 || start >= size) {
        cout << "Digite un índice válido: ";
        cin >> start;
    }
}

void validateEnd(int &end, int size, int start) {
    cout << "Ingrese el valor final: ";
    cin >> end;
    while (end < start || end >= size) {
        cout << "Digite un límite válido (mayor o igual a " << start << " y menor que " << size << "): ";
        cin >> end;
    }
}

void option1(int arr[], Node *root, int &size){
    int start, end;
    validateStart(start, size);
    validateEnd(end, size,start);

    int rangeMin = rangeMinQuery(root, arr, start, end);
    cout<<"El indice del valor minimo de "<<start<<" a "<<end<<" es : "<<rangeMin<<endl;
}

void printBanner() {
    cout << "\n---------------------------------" << endl;
    cout << "------ Arboles Segmentados ------" << endl;
    cout << "---------------------------------" << endl;
    cout << "[1] Obtener valor minimo." << endl;
    cout << "[0] Salir." << endl << endl;
}

void menu(Node *&root, int arr[], int size) {
    int option;

    do {
        printBanner();
        
        cout << "Ingresa la opcion: ";
        cin >> option;
    
        switch (option) {
        case 1:
            option1(arr, root, size);
            break;
        case 0:
            break;

        default:
            break;
        }
    } while (option != 0);
}

int main(){
    Node *root = nullptr;
    int size;
    cout << "Ingrese el numero de elementos que tendrá el arreglo: ";
    cin >> size;
    validateSize(size);
    int arr[size];
    fillArray(arr, size);
    
    root = build(arr, 0, size - 1);
    
    menu(root, arr, size);

    getch();
    return 0;
}