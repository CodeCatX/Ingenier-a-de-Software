// Arboles AVL

#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Estructura Node
struct Node {
    int value;
    int FE;
    Node *left;
    Node *right;
    Node *parent;
};

/*──────────────────────── helpers ────────────────────────*/
struct Block {
    std::vector<std::string> rows;   // líneas ya compuestas
    int rootPos   = 0;               // columna donde cae la raíz dentro de rows[0]
    int width()   const { return rows.empty() ? 0 : rows[0].size(); }
};

// Convierte el valor del nodo a string.
std::string toStr(int v) {
    std::ostringstream oss; oss << v; return oss.str();
}

/*─────────────────── core pretty-print ───────────────────*/
Block layout(Node* n)
{
    if (!n) return {};                           // bloque vacío

    // 1) bloques de los subárboles
    Block left  = layout(n->left);
    Block right = layout(n->right);

    // 2) línea con el valor de la raíz
    std::string val = toStr(n->value);
    int valLen = (int)val.size();

    // 3) espacio entre sub-árboles
    int gap = 3;  // >=3 queda legible: ‘/  \’
    int totalWidth = std::max(left.width() + gap + right.width(),
                              left.rootPos + 1 + gap/2 + right.width());

    std::string rootLine(totalWidth, ' ');
    int rootPos;

    if (!left.rows.empty()) {
        rootPos = left.rootPos + 1 + gap/2;      // coloca raíz centrada sobre unión
    } else if (!right.rows.empty()) {
        rootPos = right.rootPos - 1 - gap/2 + valLen; // solo subárbol derecho
    } else {
        rootPos = 0;                             // nodo hoja
        totalWidth = valLen;
        rootLine.resize(totalWidth, ' ');
    }

    // Copia valor de la raíz
    rootLine.replace(rootPos, valLen, val);

    // 4) líneas de conexiones ‘/’ y ‘\’
    std::string branchLine(totalWidth, ' ');
    if (n->left)  branchLine[left.rootPos + 1]           = '/';
    if (n->right) branchLine[rootPos + valLen + gap/2 - 1] = '\\';

    // 5) fusionar todas las líneas
    std::vector<std::string> rows;
    rows.push_back(rootLine);
    if (n->left || n->right) rows.push_back(branchLine);

    // Combinar cuerpo de los sub-árboles
    size_t maxRows = std::max(left.rows.size(), right.rows.size());
    for (size_t i = 0; i < maxRows; ++i) {
        std::string l = (i < left.rows.size() ) ? left.rows[i ] : std::string(left.width(),  ' ');
        std::string r = (i < right.rows.size()) ? right.rows[i] : std::string(right.width(), ' ');
        rows.push_back(l + std::string(gap, ' ') + r);
    }

    return {rows, rootPos};
}

void printTreeDown(Node* root) {
    Block b = layout(root);
    for (auto& line : b.rows) std::cout << line << '\n';
}

void imprimirArbol(Node* raiz, int espacio = 0, int nivel = 5) {
    if (raiz == nullptr) return;

    espacio += nivel;

    imprimirArbol(raiz->right, espacio);

    cout << endl;
    for (int i = nivel; i < espacio; i++) cout << " ";
    cout << raiz->value << endl;

    imprimirArbol(raiz->left, espacio);
}

// FUNCIONES AUXILIARES /////////////////////////////////////////////////////////////////////
Node *createNodo(int NodeValue, Node *parent) { // Función para crear un nodo
    Node *newNode = new Node;
    newNode -> value = NodeValue;
    newNode -> FE = 0;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    newNode -> parent = parent;
    return newNode;
}

bool isLeaf(Node *node){
    return node -> right == nullptr && node -> left == nullptr;
}

bool isEmpty(Node *node){
    return node == nullptr;
}

// FUNCIONES DE OPERACIONES BÁSICAS //
bool search(Node *root, int searchValue){ // Función para buscar un valor en el árbol
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


void SRR(Node *&root)
{
    Node* P = root;              // FE == -2
    Node* Q = P->left;           // hijo izquierdo
    Node* B = Q->right;

    
    P->left  = B;  if (B) B->parent = P;
    Q->right = P;
    Q->parent = P->parent;
    P->parent = Q;
    root = Q;

    
    if (Q->FE == 0) {            // ---- BORRADO ----
        P->FE = -1;              //  <--  signo correcto
        Q->FE = +1;
    } else {                     // Q->FE == -1 (inserción)
        P->FE = 0;
        Q->FE = 0;
    }
}

void SLR(Node *&root)
{
    Node* P = root;              // FE == +2
    Node* Q = P->right;          // hijo derecho
    Node* B = Q->left;

    
    P->right = B; if (B) B->parent = P;
    Q->left  = P;
    Q->parent = P->parent;
    P->parent = Q;
    root = Q;

    
    if (Q->FE == 0) {            // ---- BORRADO ----
        P->FE = +1;              //  <--  signo correcto
        Q->FE = -1;
    } else {                     // Q->FE == +1 (inserción)
        P->FE = 0;
        Q->FE = 0;
    }
}

void DRR(Node *&root) {
    SLR(root -> left);
    SRR(root);

    Node* R = root;
    Node* Q = R->left;
    Node* P = R->right;

    switch (R->FE) {
        case -1: Q->FE = 0;  P->FE = 1;  break;
        case  0: Q->FE = 0;  P->FE = 0;  break;
        case  1: Q->FE = -1; P->FE = 0;  break;
    }

    R->FE = 0;
}

void DLR(Node *&root) {
    SRR(root->right);
    SLR(root);

    Node* R = root;
    Node* P = R->left;
    Node* Q = R->right;

    switch (R->FE) {
        case -1: P->FE = 0;  Q->FE = 1;  break;
        case  0: P->FE = 0;  Q->FE = 0;  break;
        case  1: P->FE = -1; Q->FE = 0;  break;
    }

    R -> FE = 0;
}

void balance(Node *&root) {
    if (!isEmpty(root)){
        if (root -> FE > 1) {
            if (root -> right -> FE >= 0) {
                SLR(root);
            } else {
                DLR(root);
            }
        } else if (root -> FE < -1) {
            if (root->left -> FE <= 0) {
                SRR(root);
            } else {
                DRR(root);
            }
        }
    }
}


void insert(Node *&root, int value, Node *parent){ // Función para insretar un valor
    if (root == nullptr){
        root = createNodo(value, parent);
    }else{
        if (value == root->value){
            cout<<"ERROR, No se puede insertar el mismo valor :("<<endl;
        }else{
            if(value < root -> value){
                insert(root -> left, value, root);
                root -> FE--;
            }else{
                insert(root -> right, value, root);
                root -> FE++;
            }
            balance(root);
        }
    }
}

Node *&maxNode(Node *&root){ // Función para obtener el nodo más a la derecha posible
    if (root && root -> right){
        return maxNode(root -> right);
    } else {
        return root;
    }
}

bool remove(Node *&root, int value){
    if (isEmpty(root)) return false;

    bool alturaBajo = false;

    if (value < root->value) {                      
        alturaBajo = remove(root -> left, value);
        if (alturaBajo) root->FE++;               
    }
    else if (value > root -> value) {
        alturaBajo = remove(root->right, value);
        if (alturaBajo) root->FE--;
    }
    else {
        if (isLeaf(root)) {
            delete root; root = nullptr;
            return true;
        }

        if (!isEmpty(root -> left) && !isEmpty(root -> right)) {
            Node *&m = maxNode(root -> left);
            root -> value = m->value;
            alturaBajo = remove(root -> left, m -> value); 
            if (alturaBajo) root -> FE++;        
        } else {
            Node *child = (root -> left) ? root->left : root->right;
            child -> parent = root -> parent;
            delete root; root = child;
            return true;                        
        }
    }

    if (alturaBajo) {
        balance(root);
        return (root->FE == 0);
    } else {
        return false;   
    }
}

void encontrado(Node *root, int Value){
    if (search(root, Value)){
        cout<<"El valor "<<Value<<" fue encontrado "<<endl;
    }else{
        cout<<"El valor "<<Value<<" NO fue encontrado "<<endl;
    }
}

// Función para imprimir los datos del arbol en recorrido inorden
void inorder(Node *root) {
    if (root != nullptr) {
        inorder(root -> left);
        cout << root -> value << " ";
        inorder(root -> right);
    }
}
// Función para imprimir los datos del arbol en recorrido preorden
void preorder(Node *root) {
    if (root != nullptr) {
        cout << root -> value << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
// Función para imprimir los datos del arbol en recorrido postorden
void postorder(Node *root) {
    if (root != nullptr) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> value << " ";
    }
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
            insert(root, valueToInsert, nullptr);
            cout << "FE:" << root -> FE;
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
            encontrado(root, valueToSearch);
        
            break;

        case 4:
            imprimirArbol(root);
            cout << endl;
            break;

        case 5:
            inorder(root);
            cout << endl;
            break;

        case 6:
            preorder(root);
            cout << endl;
            break;

        case 7:
            postorder(root);
            cout << endl;
            break;

        default:
            break;
        }
    } while (opcion != 0);
}

int main() {
    Node *root = nullptr;

    menu(root);
    
    return 0;
}