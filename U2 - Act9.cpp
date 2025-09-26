#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    float primerTri, segundoTri, tercerTri;
};

void cargar_alumno(Alumno dato[], int & dl, const int max){
    string aux;
    cout << "Ingresa el nombre del alumno (fin para finalizar): ";
    getline(cin>>ws, aux);

    while(aux != "fin" && dl < max){
        dato[dl].nombre = aux;
        cout << "Nota del primer trimestre: ";
        cin >> dato[dl].primerTri;
        cout << "Nota del segundo trimestre: ";
        cin >> dato[dl].segundoTri;
        cout << "Nota del tercer trimestre: ";
        cin >> dato[dl].tercerTri;
        cout << "\nAlumno agregado exitosamente." << endl;
        dl++;

        cout << "\nIngresa el nombre del alumno (fin para finalizar): ";
        getline(cin>>ws, aux);
    }
    cout << "\nFinalizado la carga de alumnos." << endl;
}

float nota_alumno(Alumno dato[], int dl){
    float aux = (dato[dl].primerTri + dato[dl].segundoTri + dato[dl].tercerTri) / 3;
    return aux;
}

void aptos(Alumno dato[], int dl){
    cout << "Aptos: " << endl;
    cout << endl;
    for(int i = 0; i < dl; i++){
        if(nota_alumno(dato, i) >= 5){
            cout << "Nombre: " << dato[i].nombre << endl;
        }
    }
}

void no_aptos(Alumno dato[], int dl){
    cout << "No aptos: " << endl;
    cout << endl;
    for(int i = 0; i < dl; i++){
        if(nota_alumno(dato, i) < 5){
            cout << "Nombre: " << dato[i].nombre << endl;
        }
    }
}

int main(){
    const int max_alumnos = 5000;
    Alumno dato[max_alumnos];
    int cant_alumnos = 0;

    cargar_alumno(dato, cant_alumnos, max_alumnos);
    aptos(dato, cant_alumnos);
    no_aptos(dato, cant_alumnos);

    return 0;
}