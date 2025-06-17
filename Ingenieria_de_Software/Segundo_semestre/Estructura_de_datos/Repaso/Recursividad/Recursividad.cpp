#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int sumaArreglo(int a[], int n) {
    if (n < 0) {
        return 0;
    } else {
        return a[n] + sumaArreglo(a, n-1);
    }
}

int obtenerDigitos(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + obtenerDigitos(n/10);
    }
}

int potencia(int x, int e) {
    if (e == 0) {
        return 1;
    } else {
        return x * potencia(x, e-1);
    }
}

int sumarNones(int a[], int n) {
    if (n < 0) {
        return 0;
    } else {
        if (a[n] % 2 != 0) {
            return a[n] + sumarNones(a, n-1);
        } else {
            return sumarNones(a, n-1);
        }
    }
}

bool contiene(int a[], int n, int x) {
    if (n < 0) {
        return false;
    } else {
        if (a[n] == x) {
            return true;
        } else {
            return contiene(a, n-1, x);
        }
    }
}

void imprimirSerie(int n) {
    if (n > 0) {
        imprimirSerie(n-1);
        cout << n << " ";
    }
}

int main () {
    cout << "Factorial de 5: " << factorial(5) << endl;
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    cout << "Suma primeros 5 elementos de {1, 2, 3, 4, 5, 6, 7}: " << sumaArreglo(a, 4) << endl;
    cout << "Numero de digitos de 2500: " << obtenerDigitos(2500) << endl;
    cout << "Potencia de 5^3: " << potencia(5, 3) << endl;
    cout << "Suma numeros nones de {1, 2, 3, 4, 5, 6, 7}: " << sumarNones(a, 7) << endl;
    cout << "Verificar si 5 esta en  {1, 2, 3, 4, 5, 6, 7}: " << contiene(a, 7, 5) << endl;
    cout << "Verificar si 8 esta en  {1, 2, 3, 4, 5, 6, 7}: " << contiene(a, 7, 8) << endl;
    cout << "Imprimir serie hasta el 100: ";
    imprimirSerie(100);
    cout << endl;

    return 0;
}