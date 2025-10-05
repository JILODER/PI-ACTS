#include <iostream>
#include <string>
using namespace std;

struct Cliente{
    string nombre, apellido, email;
    int dni, fecha, monto_anual;
};

string minuscula(string aux){
    for(int i = 0; i < aux.length(); i++){
        aux[i] = tolower(aux[i]);
    }
    return aux;
}

void ordenar_dni(Cliente datos[], int &dl){
    for(int i = 0; i < dl; i++){
        for(int j = 0; j < dl-1; j++){
            if(datos[j].dni > datos[j+1].dni){
                Cliente aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
    }
}

void cumpleanos(Cliente datos[], int dl){
    int cumples[12] = {0};
    for(int i = 0; i < dl; i++){
        int mes = datos[i].fecha % 100;
        if(mes >= 1 && mes <= 12){
            cumples[mes - 1]++;
        }
    }

    cout << "\nCantidad de personas que cumplen años por mes:" << endl;
    for(int i = 0; i < 12; i++){
        cout << "Mes " << i + 1 << ":" << cumples[i] << endl;
    }
}

void mas_gasto(Cliente datos[], int dl){
    int aux, indice;
    for(int i = 0; i < dl; i++){
        if(datos[i].monto_anual > aux){
            aux = datos[i].monto_anual;
            indice = i;
        }
    }
    cout << "\nEl cliente que mas gasto tuvo es " << datos[indice].nombre << " " << datos[indice].apellido
    << " con $" << aux << endl;
}

void cargar_clientes(Cliente datos[], int &dl, const int MAX){
    string aux;
    cout << "Ingrese nombre del cliente (z para finalizar): ";
    getline(cin>>ws, aux);

    while(minuscula(aux) != "z" && dl < MAX){
        datos[dl].nombre = aux;
        cout << "Apellido: ";
        getline(cin>>ws, datos[dl].apellido);
        cout << "DNI: ";
        cin >> datos[dl].dni;
        cout << "Email: ";
        cin >> datos[dl].email;
        cout << "Fecha de cumpleanios (DDMM): ";
        cin >> datos[dl].fecha;
        cout << "Monto total de compras en el ultimo anio: ";
        cin >> datos[dl].monto_anual;
        cout << "Cliente cargado correctamente." << endl;
        dl++;
        ordenar_dni(datos, dl);

        cout << "\nIngrese nombre del cliente (z para finalizar): ";
        getline(cin>>ws, aux);
    }
    cout << "Finalizada la carga de clientes..." << endl;
}

void mostrar_clientes(Cliente datos[], int dl){
    cout << "\nListado de clientes:" << endl;
    for(int i = 0; i < dl; i++){
        cout << "Nombre: " << datos[i].nombre << endl;
        cout << "Apellido: " << datos[i].apellido << endl;
        cout << "DNI: " << datos[i].dni << endl;
        cout << "Email: " << datos[i].email << endl;
        cout << "Fecha de cumpleanios: " << datos[i].fecha << endl;
        cout << "Monto gastado el ultimo anio: " << datos[i].monto_anual << endl;
        cout << endl;
    }
}

int main(){
    const int df = 500;
    Cliente datos[df];
    int cant_clientes = 0;

    cargar_clientes(datos, cant_clientes, df);
    mostrar_clientes(datos, cant_clientes);
    cumpleanos(datos, cant_clientes);
    mas_gasto(datos, cant_clientes);

    return 0;
}