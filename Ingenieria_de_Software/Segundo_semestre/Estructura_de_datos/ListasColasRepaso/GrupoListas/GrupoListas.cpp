#include <iostream>
using namespace std;

struct Nodo {
    string nombre;
    int calificacion;
    Nodo *sig;
};

void inicializar(Nodo *&frente, Nodo *&frenteOrdinario, Nodo *&frenteExtraordinario) {
    frente = nullptr;
    frenteOrdinario = nullptr;
    frenteExtraordinario = nullptr;
}

Nodo *crearNodo(string nombreAlumno, int calificacionAlumno) {
    Nodo *ap = new Nodo;
    ap -> nombre = nombreAlumno;
    ap -> calificacion = calificacionAlumno;
    ap -> sig = nullptr;
    return ap;
}

bool estaVacia(Nodo *frente) {
    if (frente == nullptr) {
        return true;
    } else {
        return false;
    }
}

void agregar(Nodo *&frente, string nombreAlumno, int calificacionAlumno) {
    if (estaVacia(frente) == true) {
        frente = crearNodo(nombreAlumno, calificacionAlumno);
    } else if (frente -> sig == nullptr) {
        frente -> sig = crearNodo(nombreAlumno, calificacionAlumno);
    } else {
        agregar(frente -> sig, nombreAlumno, calificacionAlumno);
    }
}

void solicitarDatos(Nodo *&frente) {
    for (int i = 0; i < 4; i++) {
        string nombreAlumno;
        int calificacionAlumno;
        cout << endl << "\033[93m***** Alumno " << i+1 << " *****\033[0m" << endl;
        cout << "Ingrese el nombre del alumno: ";
        cin >> nombreAlumno;
        cout << "Ingrese la calificacion del alumno: ";
        cin >> calificacionAlumno;
        agregar(frente, nombreAlumno, calificacionAlumno);
    }
}

void imprimirLista(Nodo *frente) {
    if (frente != nullptr) {
        cout << endl << "\033[93mNombre: \033[0m" << frente -> nombre << endl;
        cout << "\033[93mCalificacion: \033[0m" << frente -> calificacion << endl;
        imprimirLista(frente -> sig);
    } else {
        cout << "eNulo" << " ";
    }
}

void distribuirGrupo(Nodo *&frente, Nodo *&frenteOrdinario, Nodo *&frenteExtraordinario) {
    if (frente != nullptr) {
        if (frente -> calificacion == 6) {
            agregar(frenteOrdinario, frente -> nombre, frente -> calificacion);
        } else if (frente -> calificacion >= 4 && frente -> calificacion < 6) {
            agregar(frenteExtraordinario, frente -> nombre, frente -> calificacion);
        }
        distribuirGrupo(frente -> sig, frenteOrdinario, frenteExtraordinario);
    }
}

int main() {
    Nodo *frente;
    Nodo *frenteOrdinario;
    Nodo *frenteExtraordinario;
    inicializar(frente, frenteOrdinario, frenteExtraordinario);

    solicitarDatos(frente);
    distribuirGrupo(frente, frenteOrdinario, frenteExtraordinario);

    int opcion = 0;

    do {
        cout << "\n---- Menú ----" << endl;
        cout << "1. Visualizar todos los alumnos" << endl;
        cout << "2. Visualizar alumnos que presentaran ordinario" << endl;
        cout << "3. Visualizar alumnos que presentaran extraordinario" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                imprimirLista(frente);
                break;
            case 2:
                imprimirLista(frenteOrdinario);
                break;
            case 3:
                imprimirLista(frenteExtraordinario);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no valida, intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}