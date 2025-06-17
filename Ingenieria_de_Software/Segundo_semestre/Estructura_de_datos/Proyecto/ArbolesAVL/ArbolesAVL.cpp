#include <iostream>
#include <conio.h>
using namespace std;


struct Node {
    int value;
    int FE;
    Node *right;
    Node *left;
    Node *parent;
};

bool isEmpty(Node *root){
    return root == nullptr;
}

Node *createNode(int value, Node *parent){
    Node *newNode = new Node;
    newNode -> FE = 0;
    newNode -> value = value;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    newNode -> parent = parent;
    return newNode;
}


void RDD(Node *&root, Node *node){
    Node *Parent = node -> parent;
    Node *P = node;
    Node *Q = P -> left;
    Node *R = Q -> right;
    Node *B = R -> left;
    Node *C = R -> right;

    if (!isEmpty(Parent)){
        if(Parent -> right == node){
            Parent -> right = R;
        } else {
            Parent -> left = R;
        }
    } else {
        root = R;
    }

    Q -> right = B;
    P -> left = C;
    R -> left = Q;
    R -> right = P;

    R -> parent = Parent;
    P -> parent = R;
    Q -> parent = R;

    if (!isEmpty(B)){
        B -> parent = Q;
    }
    if (!isEmpty(C)){
        C -> parent = P;
    }

    switch(R->FE) {
      case -1: Q->FE = 0; P -> FE = 1; break;
      case 0:  Q->FE = 0; P -> FE = 0; break;
      case 1:  Q->FE = -1; P -> FE = 0; break;
   }
   R->FE = 0;
}



void RDI(Node *&root, Node *node){
    Node *Parent = node->parent;
    Node *P = node;
    Node *Q = P->right;
    Node *R = Q->left;
    Node *B = R->left;
    Node *C = R->right;

    if (Parent != nullptr)
    {
        if (Parent->right == P)
            Parent->right = R;
        else
            Parent->left  = R;
    }
    else
    {
        root = R;    
    }

    P->right = B;
    Q->left  = C;
    R->left  = P;
    R->right = Q;
    R->parent = Parent;
    P->parent = R;
    Q->parent = R;

    if (B != nullptr)
        B->parent = P;
    if (C != nullptr)
        C->parent = Q;

    switch (R->FE)
    {
        case -1:
            P->FE = 0;
            Q->FE = 1;
            break;
        case 0:
            P->FE = 0;
            Q->FE = 0;
            break;
        case 1:
            P->FE = -1;
            Q->FE = 0;
            break;
    }
    R->FE = 0;
}

void RSD(Node *&root, Node *node){
    Node *Padre = node -> parent;
    Node *P = node;
    Node *Q = P->left;
    Node *B = Q->right;

    if(Padre)
        if(Padre->right == P) Padre->right = Q;
        else Padre->left = Q;
    else {
        root = Q;
    }

    P->left = B;
    Q->right = P;

    P->parent = Q;
    if(B) B->parent= P;
    Q->parent = Padre;

    P->FE = 0;
    Q->FE = 0;
}


void RSI(Node *&root, Node *node){
    Node *Padre = node -> parent;
    Node *P = node;
    Node *Q = P -> right;
    Node *B = Q->left;

    if(Padre)
        if(Padre->right == P) Padre->right = Q;
        else Padre->left = Q;
    else {
        root = Q;
    };

   P->right = B;
   Q->left = P;

   P->parent = Q;
   if(B) B->parent = P;
   Q->parent = Padre;

   P->FE = 0;
   Q->FE = 0;
}

void balance(Node *&root, Node *&node, bool isLeftDirection, bool isNew){
    bool exit = false;

    while(node && !exit){
        if (isNew){
            if (isLeftDirection){
                node -> FE--;
            } else {
                node -> FE++;
            }
        } else {
            if (isLeftDirection){
                node -> FE++;
            } else {
                node -> FE--;
            }
        }
        if (node -> FE == 0){
            exit = true;
        } else if (node -> FE == -2){
            if (node -> left -> FE == 1){
                RDD(root, node);
            } else {
                RSD(root, node);
            }
            exit = true;
        } else if (node -> FE == 2){
            if (node -> right -> FE == -1){
                RDI(root, node);
            } else {
                RSI(root, node);
            }
            exit = true;
        }
        if(node->parent)
        if(node->parent->right == node) isLeftDirection = false; else isLeftDirection = true;
        node = node->parent;
    }
}


bool isLeaf(Node *root){
    return isEmpty(root->right) && isEmpty(root -> left);
}


void remove(Node *&root, int value){
    Node *parent = nullptr;
    Node *current = nullptr;
    Node *node = nullptr;
    int aux;

    current = root;
    while (!isEmpty(current))
    {
        if (value == current -> value){
            if (isLeaf(current)){
                if(parent)
               if(parent->right == current) parent->right = nullptr;
               else if(parent->left == current) parent->left = nullptr;
            delete current;
            current = nullptr;
            
            if((parent->right == current && parent->FE == 1) ||
               (parent->left == current && parent->FE == -1)) {
               parent->FE = 0;
               current = parent;
               parent = current->parent;
            }
            if(parent)
               if(parent->right == current) balance(root, parent, false, false);
               else                         balance(root, parent, true, false);
            return;
            } else {
                parent = current;
                if (current -> left){
                    node = current -> left;
                    while (node -> right)
                    {
                        parent = node;
                        node = node -> right;
                    }
                } else {
                    node = current -> right;
                    while (node -> left)
                    {
                        parent = node;
                        node = node -> left;
                    }
                }
                aux = current -> value;
                current -> value = node -> value;
                node -> value = aux;
                current = node;
            }
        } else {
            parent = current;
            if (value > current -> value){
                current = current -> right;
            } else if (value < current -> value){
                current = current -> left;
            }
        }
    }
}


void insert(Node *&root, int value){
    Node *parent = nullptr;
    Node *current = root;

    while(!isEmpty(current) && value != current -> value) {
        parent = current;
        if(value < current -> value){
            current = current -> left;
        } else if(value > current -> value){
            current = current -> right;
        }
    }

    if (isEmpty(current)){
        if (isEmpty(parent)){
            root = createNode(value, nullptr);
        } else if (value < parent -> value){
            current = createNode(value, parent);
            parent -> left = current;
            balance(root, parent, true, true);
        } else if (value > parent -> value){
            current = createNode(value, parent);
            parent -> right = current;
            balance(root, parent, false, true);
        }
    }

}


void inOrder(Node* node) {
    if (!isEmpty(node)){
        inOrder(node->left);
        int fe = node -> FE;
        cout << node->value << "(" << fe << "),";
        inOrder(node->right);
    }
}

void preOrder(Node* node) {
    if (!isEmpty(node)){
        int fe = node -> FE;
        cout << node->value << "(" << fe << "),";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node* node) {
    if (!isEmpty(node)){
        postOrder(node->left);
        postOrder(node->right);
        int fe = node -> FE;
        cout << node->value << "(" << fe << "),";
    }
}

bool search(Node *root, int searchValue){
    if (root != nullptr) {
        if (root -> value == searchValue) {
            return true;
        } else {
            if (searchValue < root -> value) {
                return search(root -> left, searchValue);
            } else {
                return search(root -> right, searchValue);
            }
        }
    } else {
        return false;
    }
}

void printTree(Node* raiz, int espacio = 0, int nivel = 5) {
    if (raiz == nullptr) return;

    espacio += nivel;

    printTree(raiz->right, espacio);

    cout << endl;
    for (int i = nivel; i < espacio; i++) cout << " ";
    cout << raiz->value << endl;

    printTree(raiz->left, espacio);
}

void imprimirBanner() {
    cout << "--------------------------------" << endl;
    cout << "--------- Arboles AVL ----------" << endl;
    cout << "--------------------------------" << endl;
    cout << "[1] Insertar un dato." << endl;
    cout << "[2] Eliminar un dato." << endl;
    cout << "[3] Buscar un dato." << endl;
    cout << "[4] Desplegar arbol" << endl;
    cout << "[5] Imprimir inorden." << endl;
    cout << "[6] Imprimir preorden." << endl;
    cout << "[7] Imprimir postorden." << endl;
    cout << "[0] Salir." << endl << endl;
}

void onSearch(Node *root, int valueToSearch){
     bool found = search(root, valueToSearch);

    if (found == true){
        cout << "El valor existe dentro del arbol." << endl;
    } else {
        cout << "El valor NO existe dentro del arbol." << endl;
    }
}

void menu(Node *&root) {
    int opcion;
    do {
        imprimirBanner();
        
        cout << "Ingresa la opcion: ";
        cin >> opcion;
    
        switch (opcion) {
        case 1:
            int valueToInsert;
            cout << "Ingresa el dato a ingresar: ";
            cin >> valueToInsert;
            insert(root, valueToInsert);
            cout << endl;
            break;

        case 2:
            int valueToRemove;
            cout << "Ingresa el dato a eliminar: ";
            cin >> valueToRemove;
            remove(root, valueToRemove);
            cout << endl;
            break;

        case 3:
            int valueToSearch;
            cout << "Ingresa el dato a buscar: ";
            cin >> valueToSearch;
           
            onSearch(root, valueToSearch);

            break;
        case 4:
            printTree(root);
            cout << endl;
            break;
        case 5:
            inOrder(root);
            cout << endl;
            break;

        case 6:
            preOrder(root);
            cout << endl;
            break;

        case 7:
            postOrder(root);
            cout << endl;
            break;

        default:
            break;
        }
    } while (opcion != 0);
}


int main(){
    Node *root = nullptr;

    menu(root);

    getch();
    return 0;
}