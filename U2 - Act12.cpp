#include <iostream>
#include <string>
using namespace std;

struct Sucursal{
    string nombre_sucursal;
    int legajo_encargado;
};

struct Empleado{
    string nombre;
    int legajo, dni;
};

string minuscula(string auxiliar){
    for(int i = 0; i < auxiliar.length(); i++){
        auxiliar[i] = tolower(auxiliar[i]);
    }
    return auxiliar;
}

//Busca si el legajo existe
bool legajo_existe(Empleado dato[], int dl, int legajoBuscado){
    for(int i = 0; i < dl; i++){
        if(legajoBuscado == dato[i].legajo){
            return true;
        }
    }
    return false;
}

//Asigno el encargado
int encargado(int dl, Empleado dato[]){
    int legajo;
    do{
        cout << "Ingrese numero del legajo del encargado: ";
        cin >> legajo;
        if(!legajo_existe(dato, dl, legajo)){
            cout << "El legajo no existe, intente de nuevo." << endl;
            cout << endl;
        }
    }while(!legajo_existe(dato, dl, legajo));
    return legajo;
}

int legajo_nombre(int dl, Empleado dato[]){
    int legajo;
    do{
        cout << "Ingrese numero del legajo del encargado: ";
        cin >> legajo;
        if(!legajo_existe(dato, dl, legajo)){
            cout << "El legajo no existe, intente de nuevo." << endl;
            cout << endl;
        }
    }while(!legajo_existe(dato, dl, legajo));
    return legajo;
}

void cargar_empleado(Empleado dato[], int &dl, int max){
    string aux;
    cout << "Nombre del empleado (fin para finalizar): ";
    getline(cin>>ws, aux);
    while(minuscula(aux) != "fin" && dl < max){
        dato[dl].nombre = aux;
        cout << "DNI: ";
        cin >> dato[dl].dni;
        cout << "Numero de legajo: ";
        cin >> dato[dl].legajo;
        dl++;
        cout << "Empleado cargado correctamente." << endl;

        cout << "\nNombre del empleado (fin para finalizar): ";
        getline(cin>>ws, aux);
    }
    cout << "Fin de la carga de empleados." << endl;
}

void cargar_sucursal(Sucursal info[], int &dls, int MAX, int dl, Empleado dato[]){
    string aux;
    cout << "\nNombre de la sucursal (fin para finalizar): ";
    getline(cin>>ws, aux);
    while(minuscula(aux) != "fin" && dls < MAX){
        info[dls].nombre_sucursal = aux;
        info[dls].legajo_encargado = encargado(dl, dato);
        dls++;
        cout << "Sucursal con encargado ingresado exitosamente." << endl;

        cout << "\nNombre de la sucursal (fin para finalizar): ";
        getline(cin>>ws, aux);
    }
    cout << "Fin de carga de sucursales." << endl;
}

void nombre_empleado(Empleado dato[], int dl){
    int aux;
    cout << "\nIngrese numero de legajo para buscar su nombre (-1 para finalizar): ";
    cin >> aux;
    while(aux != -1){
        bool encontrado = false;
        for(int i = 0; i < dl; i++){
            if(dato[i].legajo == aux){
                cout << "Legajo encontrado. Nombre del empleado: " << dato[i].nombre << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            cout << "Legajo no encontrado." << endl;
        }
        cout << "\nNuevo legajo a encontrar (-1 para finalizar): ";
        cin >> aux;
    }
    cout << "Fin del buscado de nombres." << endl;
}

void listado_sucursales(Sucursal info[], Empleado dato[], int dls, int dl){
    cout << "\nListado de sucursales:" << endl;
    for(int i = 0; i < dls; i++){
        cout << "Sucursal: " << info[i].nombre_sucursal << endl;

        bool encontrado = false;
        for(int j = 0; j < dl; j++){
            if(dato[j].legajo == info[i].legajo_encargado){
                cout << "Encargado: " << dato[j].nombre << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            cout << "Encargado: No tiene." << endl;
        }
        cout << endl;
    }
}

int main(){
    const int max_empleados = 2000;
    const int max_sucursales = 20;
    Empleado dato[max_empleados];
    Sucursal info[max_sucursales];
    int cant_empleados = 0, cant_sucursales = 0;

    cargar_empleado(dato, cant_empleados, max_empleados);
    cargar_sucursal(info, cant_sucursales, max_sucursales, cant_empleados, dato);
    nombre_empleado(dato, cant_empleados);
    listado_sucursales(info, dato, cant_sucursales, cant_empleados);

    return 0;
}