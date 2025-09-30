#include <iostream>
#include <string>
using namespace std;

struct Ciudadano{
    string nombre, apellido, direccion, tipoDoc;
    long nacimiento;
    int doc;
    char sexo;
};

string minuscula(string aux){
    for(int i = 0; i < aux.length(); i++){
        aux[i] = tolower(aux[i]);
    }
    return aux;
}

void tipo_documento(Ciudadano datos[], int dl) {
    int opc;
    string aux;

    do {
        cout << "Tipo de documento:" << endl;
        cout << "1 - DNI." << endl;
        cout << "2 - Pasaporte." << endl;
        cout << "3 - Otro." << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                datos[dl].tipoDoc = "DNI";
                break;
            case 2:
                datos[dl].tipoDoc = "Pasaporte";
                break;
            case 3:
                cout << "Especificar: ";
                getline(cin>>ws, aux);
                datos[dl].tipoDoc = aux;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opc < 1 || opc > 3);
}

string sexo(Ciudadano datos[], int dl){
    string genero;
    if(datos[dl].sexo == 'm'){
        genero = "masculino";
    }
    else {
        genero = "femenino";
    }
    return genero;
}

void fecha_nacimiento(Ciudadano datos[], int i){
    int year = (datos[i].nacimiento/10000) % 100; //Obtiene los ultimos 2 digitos del año
    int month = (datos[i].nacimiento / 100) % 100; //Obtiene los dos digitos del mes
    int day = datos[i].nacimiento % 100; //Obtiene los dos ultimos

    //cout << "Fecha de nacimiento: " << day << "/" << month << "/" << year << endl;
    cout << "Fecha de nacimiento: ";
    if(day < 10) cout << "0";
    cout << day << "/";
    if(month < 10) cout << "0";
    cout << month << "/";
    if(year < 10) cout << "0";
    cout << year << endl;
}

void registro(Ciudadano datos[], int & dl, const int MAX){
    string aux;
    cout << "Nombre del ciudadano: ";
    getline(cin>>ws, aux);

    while(minuscula(aux) != "fin" && dl < MAX){
        datos[dl].nombre = aux;
        cout << "Apellido: ";
        getline(cin>>ws, datos[dl].apellido);
        cout << "Fecha de nacimiento (AAAAMMDD): ";
        cin >> datos[dl].nacimiento;
        cout << "Direccion: ";
        getline(cin>>ws, datos[dl].direccion);
        tipo_documento(datos, dl);
        cout << "Numero del tipo de documento elegido: ";
        cin >> datos[dl].doc;
        cout << "Sexo (m/f): ";
        cin >> datos[dl].sexo;
        dl++;
        cout << "Ciudadano cargado exitosamente." << endl;

        cout << "\nNombre del ciudadano: ";
        getline(cin>>ws, aux);
    }
}

void mostrar_ciudadanos(Ciudadano datos[], int dl){
    cout << "\nListado de ciudadanos inscriptos:--------------------------" << endl;
    for(int i = 0; i < dl; i++){
        cout << "\nNombre y apellido: " << datos[i].nombre << " " << datos[i].apellido << endl;
        cout << "Direccion: " << datos[i].direccion << endl;
        fecha_nacimiento(datos, i);
        cout << "Tipo de documento: " << datos[i].tipoDoc << endl;
        cout << "Numero de documento: " << datos[i].doc << endl;
        cout << "Sexo: " << sexo(datos, i) << endl;
    }
}

void filtrado(Ciudadano datos[], int dl, char sexo, string tipo){
    cout << "\n" <<tipo << ":" << endl;
    for(int i = 0; i < dl; i++){
        if(datos[i].sexo == sexo){
            cout << datos[i].nombre << " " << datos[i].apellido << endl;
        }
    }
}

int main(){
    const int MAX = 500;
    Ciudadano datos[MAX] = {};
    int dl = 0;

    registro(datos, dl, MAX);
    mostrar_ciudadanos(datos, dl);
    filtrado(datos, dl, 'm', "Masculinos");
    filtrado(datos, dl, 'f', "Femeninos");

    return 0;
}