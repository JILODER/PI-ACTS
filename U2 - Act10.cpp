#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre, apellido;
    int legajo, cantFaltas;
    float calificacion;
};

string mayuscula(string auxiliar){
    int cadena = auxiliar.length();
    for(int i = 0; i < cadena; i++){
        auxiliar[i] = toupper(auxiliar[i]);
    }
    return auxiliar;
}

void cargar_alumnos(Alumno datos[], int & dl, const int df){
    string aux;
    cout << "Nombre del alumno (fin para finalizar): ";
    getline(cin>>ws, aux);
    while(mayuscula(aux) != "FIN" && dl < df){
        datos[dl].nombre = aux;
        cout << "Apellido: ";
        getline(cin>>ws, datos[dl].apellido);
        cout << "Numero de legajo: ";
        cin >> datos[dl].legajo;
        cout << "Cantidad de inasistencias: ";
        cin >> datos[dl].cantFaltas;
        cout << "Calificacion: ";
        cin >> datos[dl].calificacion;
        cout << "\nAlumno cargado." << endl;
        dl++;
        cout << endl;

        cout << "Nombre del alumno: ";
        getline(cin>>ws, aux);
    }
    cout << "\nSe finalizo la carga de alumnos." << endl;
}

void alumnos_5_inasistencias(Alumno datos[], int dl){
    cout << "\nAlumnos con mas de 5 faltas: " << endl;
    for(int i = 0; i < dl; i++){
        if(datos[i].cantFaltas > 5){
            cout << "Nombre y apellido: " << datos[i].nombre << " " << datos[i].apellido << endl;
        }
    }
}

void promedio_total(Alumno datos[], int dl){
    float promedio_total, aux;
    for(int i = 0; i < dl; i++){
        aux += datos[i].calificacion;
    }
    promedio_total = aux / dl;
    cout << "\nPromedio total de todos los alumnos: " << promedio_total << endl;
    cout << "\nAlumnos encima del promedio total:" << endl;
    for(int j = 0; j < dl; j++){
        if(datos[j].calificacion > promedio_total){
            cout << "Numero de legajo: " << datos[j].legajo << endl;
        }
    }
}

void mayoresAlPromedio(Alumno datos[], int dl){
    cout << "\nAlumnos con promedio >= 9:" << endl;
    for(int i = 0; i < dl; i++){
        if(datos[i].calificacion >= 9){
            cout << "Numero de legajo: " << datos[i].legajo;
        }
    }
    cout << endl;
}

void borrar_persona(Alumno datos[], int & dl){
    string decision;
    int legajo;
    cout << "\nDesea borrar a una persona? (s/n): ";
    cin >> decision;
    while(mayuscula(decision) != "N" && dl > 0){
        bool encontrado = false;
        cout << "Ingrese el legajo de la persona: ";
        cin >> legajo;
        for(int i = 0; i < dl; i++){
            if(datos[i].legajo == legajo){
                for(int j = i; j < dl-1; j++){
                    datos[j] = datos[j+1];
                }
                dl--;
                cout << "Se elimino la persona." << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            cout << "La persona no existe o ingreso mal los datos. Intente de nuevo." << endl;
        }
        cout << "\nDesea borrar a una persona? (s/n): ";
        cin >> decision;
    }
    cout << "\nFinalizado el borrado de personas." << endl;
}

void mostrar_alumnos(Alumno datos[], int dl){
    cout << "\nListado final:---------------------------------------" << endl;
    for(int i = 0; i < dl; i++){
        cout << "Nombre y apellido: " << datos[i].nombre << " " << datos[i].apellido << endl;
        cout << "Legajo: " << datos[i].legajo << endl;
        cout << "Cantidad de inasistencias: " << datos[i].cantFaltas << endl;
        cout << "Calificacion: " << datos[i].calificacion << endl;
        cout << endl;
    }
}

int main(){
    const int estudiantes_historicos = 1000;
    Alumno datos[estudiantes_historicos];
    int cantidad_alumnos = 0;

    cargar_alumnos(datos, cantidad_alumnos, estudiantes_historicos);
    cout << "-----------------------------------------------------" << endl;
    alumnos_5_inasistencias(datos, cantidad_alumnos);
    promedio_total(datos, cantidad_alumnos);
    mayoresAlPromedio(datos, cantidad_alumnos);
    borrar_persona(datos, cantidad_alumnos);
    mostrar_alumnos(datos, cantidad_alumnos);

    return 0;
}