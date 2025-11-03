#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    string nombre;
    Nodo * sig;
};

string mayus(string aux){
    for(int i = 0; i < aux.length(); i++){
        aux[i] = toupper(aux[i]);
    }
    return aux;
}

void ingresar_dato(Nodo * &inicio){
    string auxiliar;
    cout << "Ingrese un nombre ('x' para finalizar): ";
    getline(cin>>ws, auxiliar);

    while(mayus(auxiliar) != "X"){
        Nodo * nuevo = new Nodo();
        nuevo->nombre = auxiliar;
        nuevo->sig = nullptr;

        if(inicio == nullptr){
            inicio = nuevo;
        }
        else{
            Nodo * aux = inicio;
            while(aux->sig != nullptr){
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }

        cout << "Ingrese un nombre ('x' para finalizar): ";
        getline(cin>>ws, auxiliar);
    }
    cout << "Se finalizo la carga de nombres." << endl;
}

bool buscar(Nodo * inicio, string buscado){
    buscado = mayus(buscado);
    Nodo * aux3 = inicio;
    while(aux3 != nullptr){
        if(mayus(aux3->nombre) == buscado){
            return true;
        }
        aux3 = aux3->sig;
    }
    return false;
}

void existe(Nodo * inicio){
    string buscado;
    cout << "\nIngrese nombre a buscar: ";
    getline(cin>>ws, buscado);
    if(buscar(inicio, buscado) == true){
        cout << "Se encontro el nombre en la lista." << endl;
    }
    else{
        cout << "No se encontro el nombre en la lista." << endl;
    }
}

void imprimir_lista(Nodo * inicio){
    cout << "\nLista:" << endl;
    Nodo * aux2 = inicio;
    while(aux2 != nullptr){
        cout << aux2->nombre << endl;
        aux2 = aux2->sig;
    }
}

void eliminar_nombre(Nodo *& inicio){
    if(inicio == nullptr){
        cout << "\nLa lista esta vacia..." << endl;
        return;
    }

    string nombre_eliminar;
    cout << "\nIngrese nombre a eliminar ('X' para salir): ";
    getline(cin>>ws, nombre_eliminar);

    while(mayus(nombre_eliminar) != "X"){
        if(buscar(inicio, nombre_eliminar) == true){
            Nodo * aux = inicio;
            Nodo * anterior;
            while(mayus(aux->nombre) != mayus(nombre_eliminar)){
                anterior = aux;
                aux = aux->sig;
            }
            Nodo * siguiente = aux->sig;
            anterior->sig = siguiente;
            cout << "Nombre eliminado correctamente." << endl;
        }
        else{
            cout << "Nombre no encontrado." << endl;
        }

        cout << "\nIngrese nombre a eliminar ('X' para salir): ";
        getline(cin>>ws, nombre_eliminar);
    }
}

int main(){
    Nodo * inicio = nullptr;
    int opc;

    do{
        cout << "\n-------- MENU PRINCIPAL --------" << endl;
        cout << "1. Ingresar nombre a la lista" << endl;
        cout << "2. Buscar nombre en la lista" << endl;
        cout << "3. Eliminar nombre de la lista" << endl;
        cout << "4. Mostar lista" << endl;
        cout << "5. Salir" << endl;
        cout << endl;
        cin >> opc;

        switch(opc){
            case 1:
                ingresar_dato(inicio);
                break;
            case 2:
                existe(inicio);
                break;
            case 3:
                eliminar_nombre(inicio);
                break;
            case 4:
                imprimir_lista(inicio);
                break;
            case 5:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nIngresa una opcion valida" << endl;
                break;
        }
    } while(opc != 5);

    return 0;
}