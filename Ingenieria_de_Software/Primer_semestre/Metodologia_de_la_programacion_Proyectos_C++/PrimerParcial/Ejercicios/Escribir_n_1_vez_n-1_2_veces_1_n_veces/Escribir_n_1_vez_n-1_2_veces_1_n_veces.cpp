#include <iostream>
using namespace std;
int main () {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    if (n >= 1){
    int i = 1;

    while (i <= n) {
        int j = 1;
        while (j <= i) {
            cout << n-i+1;
            j++;
        }
        cout << endl;
        i++;
    }
    }else{
        cout << "Solo se aceptan numeros mayores a cero";
    }

    return 0;
}



/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    if (n >= 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << n - i + 1;
            }
            cout << endl;
        }
    } else {
        cout << "Solo se aceptan numeros mayores a cero";
    }

    return 0;
}

*/
