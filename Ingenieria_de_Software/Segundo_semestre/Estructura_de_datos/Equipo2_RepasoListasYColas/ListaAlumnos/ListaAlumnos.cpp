#include <iostream>

using namespace std;

struct Nodo{
    string name;
    float average;
    Nodo *nextNdo;
};


bool isEmpty(Nodo *nodo){
    if (nodo == nullptr)
        return true;
    else
        return false;
}


Nodo *createNodo(string name, float average){
    Nodo *ptr = new Nodo;
    ptr -> name = name;
    ptr -> average = average;
    ptr -> nextNdo = nullptr;
    return ptr;
}


void insert(Nodo *&head, string name, float average){
    if (isEmpty(head)){
        head = createNodo(name, average);
    } else if (head -> nextNdo == nullptr){
       head -> nextNdo = createNodo(name, average);
    } else {
        insert(head -> nextNdo, name, average);
    }
}


void printList(Nodo *n){ // funcion auxiliar para imprimir una lista de alumnos
    if (n != nullptr){
       cout << "Nombre: " << n -> name << endl;
       cout << "Promedio: " << n -> average << endl;
       printList(n -> nextNdo);
    }
}


void setOrdinaryList(Nodo *&ordinaryList, Nodo *&studentsList){ // crear lista de ordinarios
    if (!isEmpty(studentsList)){
        float average = studentsList -> average;
        string name = studentsList -> name;
        if (average == 6){
            ordinaryList = createNodo(name, average);
            setOrdinaryList(ordinaryList -> nextNdo, studentsList -> nextNdo);
        } else {
            setOrdinaryList(ordinaryList, studentsList -> nextNdo);
        }
    }
}


void setExtraordinaryList(Nodo *&extraordinaryList, Nodo *&studentsList){ // crear lista de Extraordinarios
    if (!isEmpty(studentsList)){
        float average = studentsList -> average;
        string name = studentsList -> name;
        if (average < 6 && average >= 4){
            extraordinaryList = createNodo(name, average);
            setExtraordinaryList(extraordinaryList -> nextNdo, studentsList -> nextNdo);
        } else {
            setExtraordinaryList(extraordinaryList, studentsList -> nextNdo);
        }
    }
}


void init(Nodo *&studentsList, Nodo *&ordinaryList, Nodo *&extraordinaryList){ // inicializacion del programa
    studentsList = nullptr;
    ordinaryList = nullptr;
    extraordinaryList = nullptr;
}


void showHeader(){ // Header del programa
    cout<<" +------------------------------------------+\n";
    cout<<" |            -Programa DE ESTUDIANTES-     |\n";
    cout<<" |        -ORDINARIOS Y EXTRAORDINARIOS-    |\n";
    cout<<" +------------------------------------------+\n";
}

void showMenu(){ // Funcion visual del menu
    cout<<" +------------------------------------------+\n";
    cout<<" |            -MENU DE ESTUDIANTES-         |\n";
    cout<<" +------------------------------------------+\n";
    cout << "Elige una opcion" << endl;
    cout << "[1] Mostrar todos los estudiantes." << endl;
    cout << "[2] Mostrar los estudiantes que se van a ordinario." << endl;
    cout << "[3] Mostrar los estudiantes que se van a extraordinario." << endl;
    cout << "[4] Salir." << endl;
}

void onMenu(int &state){ // Funcion logica del menu
    showMenu();
    int option;
    cout << "Opcion: ";
    cin >> option;
    state = option;
}

void requireStudents(Nodo *&studentsList, const int Max_Students){
    cout << "-- Ingresa todos los estudiantes (15) --" << endl;
    for (int i = 0; i < Max_Students; i++){
        cout << "--[Ingresa los datos del estudiante #" << i + 1 << "]--" << endl;
        string name;
        cout << "Nombre: ";
        getline(cin, name);
        cout << "Promedio: ";
        float average;
        cin >> average;
        cin.ignore();
        insert(studentsList, name, average);
        cout << endl;
    }
}


void showAllStudents(Nodo *studentsList){
    cout << "-- [Lista de alumnos] --" << endl;
    printList(studentsList);
}

void showOrdinaryList(Nodo *ordinaryList){
    cout << "-- [Lista de alumnos que se van a ordinario] --" << endl;
    printList(ordinaryList);
}

void showExtraordinaryList(Nodo *extraordinaryList){
    cout << "-- [Lista de alumnos que se van a extraordinario] --" << endl;
    printList(extraordinaryList);
}


void requireReturToMenu(int &state){
    cout << "Ingresa 0 para volver al menu: ";
    int answer;
    cin >> answer;
    if (answer != 0){
        requireReturToMenu(state);
    } else {
        state = answer;
    }
}


void start(Nodo *&studentsList, Nodo *&ordinaryList, Nodo *&extraordinaryList){
    const int Max_Students = 7;
    int state = 0;

    showHeader();
    requireStudents(studentsList, Max_Students);
    setOrdinaryList(ordinaryList, studentsList);
    setExtraordinaryList(extraordinaryList, studentsList);
    showAllStudents(studentsList);

    while (state != 4){
        switch (state)
        {
        case 0:
            onMenu(state);
            break;
        case 1:
            showAllStudents(studentsList);
            requireReturToMenu(state);
            break;
        case 2:
            showOrdinaryList(ordinaryList);
            requireReturToMenu(state);
            break;
        case 3:
            showExtraordinaryList(extraordinaryList);
            requireReturToMenu(state);
            break;
        default:
            cout << "Opcion ingresada no valida!" << endl;
            cout << "Vuelve a intentarlo!" << endl;
            requireReturToMenu(state);
            break;
        }
    }
}


void clearList(Nodo *list){
    if (list != nullptr){
        Nodo *aux = list -> nextNdo;
        delete list;
        clearList(aux);
    }
}


void cleanup(Nodo *&studentsList, Nodo *&ordinaryList, Nodo *&extraordinaryList){
    clearList(studentsList);
    clearList(ordinaryList);
    clearList(extraordinaryList);
}


int main(){
    Nodo *studentsList, *ordinaryList, *extraordinaryList;
    init(studentsList, ordinaryList, extraordinaryList);
    start(studentsList, ordinaryList, extraordinaryList);
    cleanup(studentsList, ordinaryList, extraordinaryList);
    return 0;
}