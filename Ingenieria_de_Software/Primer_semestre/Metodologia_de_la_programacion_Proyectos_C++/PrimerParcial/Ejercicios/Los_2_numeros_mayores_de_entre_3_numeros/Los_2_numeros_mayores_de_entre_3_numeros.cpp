#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1;
    cin >> n2;
    cin >> n3;

    if (n1>n2){
        if (n1>n3){
                if (n2 > n3 && n2 > n1)
                cout << "El numero mayor es " << n1 << " y " << n2;
        }else {
                cout << "Los numeros mayores erwrson " << n1 << " y " << n3;
        }
    }

    if(n2>n3) {
        if (n2>n1) {
                if (n1 > n3 && n1 > n2)
                cout << "El numero mayor es " << n1 << " y " << n2;
        }else {
                cout << "Los numeros mayores son " << n2 << " y " << n3;
        }
    }

    if(n3>n1 && n3>n2 && n2 > n1 && n2 > n3) {
        cout << "El numero mayor es: " << n2 << n3;
    }

    return 0;
}
