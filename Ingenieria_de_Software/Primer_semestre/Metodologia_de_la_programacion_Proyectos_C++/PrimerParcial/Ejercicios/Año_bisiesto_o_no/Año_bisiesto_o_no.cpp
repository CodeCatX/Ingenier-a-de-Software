#include<iostream>
using namespace std;
int main(){
    cout << "Ingresa un anio: ";
    int anio;
    cin >> anio;
    if (anio%4 == 0 && anio%100 != 0 || anio % 400 == 0){
             cout << "Es un anio bisiesto";
    }else {
    cout << "No es un anio bisiesto.";
    }

return 0;
}
