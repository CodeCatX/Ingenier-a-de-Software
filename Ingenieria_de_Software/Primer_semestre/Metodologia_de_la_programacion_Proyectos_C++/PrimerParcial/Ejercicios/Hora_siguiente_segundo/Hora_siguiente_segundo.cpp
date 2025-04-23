//#include<iostream>
//using namespace std;
//
//int main() {
//    int horas, minutos, segundos, horas_sobrantes, minutos_sobrantes, segundos_sobrantes;
//
//    cout << "Inserta una hora: ";
//    cin >> horas;
//
//    cout << "Inserta los minutos: ";
//    cin >> minutos;
//
//    cout << "Inserta los segundos: ";
//    cin >> segundos;
//
//    segundos++;
//
//    if (horas >= 24){
//        int division_horas = horas/24;
//        horas_sobrantes = (horas%24)/3600;
//        segundos += horas_sobrantes;
//        horas = division_horas;
//    }
//
//    if (segundos >= 60){
//        segundos_sobrantes = (segundos%60)/60;
//        minutos = (segundos/60) + segundos_sobrantes;
//        segundos = segundos - horas_sobrantes;
//    }
//
//    if (minutos >= 60){
//        minutos_sobrantes = (minutos%60)/60;
//        horas += (minutos/60) + minutos_sobrantes;
//        minutos = minutos - segundos_sobrantes;
//    }
//
//    cout << horas << ":" << minutos << ":" << segundos;
//
//    return 0;
//}

#include<iostream>
using namespace std;

int main() {
    int horas, minutos, segundos, horas_sobrantes, minutos_sobrantes, segundos_sobrantes;

    cout << "Inserta una hora: ";
    cin >> horas;

    cout << "Inserta los minutos: ";
    cin >> minutos;

    cout << "Inserta los segundos: ";
    cin >> segundos;
segundos++;
    if (horas == 24){
        horas=0;
    }

    if (segundos == 60){
        segundos=0;
        minutos++;
    }

    if (minutos == 60){
        minutos=0;
        horas++;
    }



    cout << horas << ":" << minutos << ":" << segundos;

    return 0;
}
