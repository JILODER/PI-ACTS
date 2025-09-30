#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    float notas[3];
};

const int max_alumnos = 5000;

string mayuscula(string aux1){
    for(int i = 0; i < aux1.length(); i++){
        aux1[i] = toupper(aux1[i]);
    }
}

void cargar_alumno(Alumno dato[], int & dl, const int max){
    string aux;
    cout << "Ingresa el nombre del alumno (fin para finalizar): ";
    getline(cin>>ws, aux);

    while(mayuscula(aux) != "FIN" && dl < max){
        dato[dl].nombre = aux;
        for(int i = 0; i < 3; i++){
            cout << i+1 << " Trimestre: ";
            cin >> dato[dl].notas[i];
        }
        dl++;

        cout << "\nIngresa el nombre del alumno (fin para finalizar): ";
        getline(cin>>ws, aux);
    }
    cout << "\nFinalizado la carga de alumnos." << endl;
}

void mostrarAptos(Alumno dato[], int dl){
		cout << "\nListado:------------------" << endl;
    for(int i = 0; i < dl; i++){
        for(int j = 0; j < 3; j++){
            if(dato[i].notas[j] < 5){
                cout << dato[i].nombre << " no apto." << endl;
                break;
            }
            else{
                cout << dato[i].nombre << " apto." << endl;
                break;
            }
        }
    }
}

int main(){
    Alumno dato[max_alumnos];
    int cant_alumnos = 0;

    cargar_alumno(dato, cant_alumnos, max_alumnos);
    mostrarAptos(dato, cant_alumnos);

    return 0;
}
