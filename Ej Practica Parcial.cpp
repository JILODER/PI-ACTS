#include <iostream>
#include <string>
using namespace std;

const int max_participantes = 3000;

struct Direccion{
    string calle, localidad;
    int altura;
};

struct Participante{
    int dni;
    string apellido, nombre;
    Direccion dir;
};

void alta(Participante datos[], int &dl){
    int aux;
    cout << "\nIngrese DNI del participante (0 para finalizar): ";
    cin >> aux;

    while(aux != 0 && dl < max_participantes){
        datos[dl].dni = aux;
        cout << "Apellido: ";
        getline(cin>>ws, datos[dl].apellido);
        cout << "Nombre: ";
        getline(cin>>ws, datos[dl].nombre);
        cout << "Calle: ";
        getline(cin>>ws, datos[dl].dir.calle);
        cout << "Altura: ";
        cin >> datos[dl].dir.altura;
        cout << "Localidad: ";
        getline(cin>>ws, datos[dl].dir.localidad);
        cout << "Participante cargado exitosamente." << endl;
        dl++;

        cout << "\nIngrese DNI del participante (0 para finalizar): ";
        cin >> aux;
    }
    cout << "\nFinalizo la alta de participantes." << endl;
}

void emitirCredencial(Participante datos[], int dl){
    if(dl == 0){
        cout << "No hay participantes registrados." << endl;
        return;
    }

    int dni_buscado;
    char opcion;

    do{
        cout << "Ingrese DNI del participante a buscar: ";
        cin >> dni_buscado;

        bool encontrado = false;
        for(int i = 0; i < dl; i++){
            if(dni_buscado == datos[i].dni){
                cout << "\nCredencial emitida con exito." << endl;
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "\nPara obtener la credencial, primero tiene que acreditarse." << endl;
        }

        cout << "Desea emitir otra credencial? (S/N): ";
        cin >> opcion;
        opcion = toupper(opcion);
    } while(opcion == 'S');
}

void listaParticipantes(Participante datos[], int dl){
    cout << "\nListado de participantes:" << endl;
    for(int i = 0; i < dl; i++){
        cout << "DNI: " << datos[i].dni << endl;
        cout << "Apellido: " << datos[i].apellido << endl;
        cout << "Nombre: " << datos[i].nombre << endl;
        cout << "Localidad: " << datos[i].dir.localidad << endl;
        cout << endl;
    }
}

int main(){
    Participante datos[max_participantes];
    int dl = 0;

    int opc;

    do{
        cout << "\n---Menu principal---\n";
        cout << "1. Alta de participantes" << endl;
        cout << "2. Emitir credencial" << endl;
        cout << "3. Lista de participantes" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opc;

        switch(opc){
            case 1:
                alta(datos, dl);
                break;
            case 2:
                emitirCredencial(datos, dl);
                break;
            case 3:
                listaParticipantes(datos, dl);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion incorrecta, intenta de nuevo." << endl;
        }
    } while(opc != 0);

    return 0;
}