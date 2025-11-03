#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo * sig;
};

void ingresar_dato(Nodo * &inicio){
    int aux;
    cout << "\nIngresa un numero >= 0 (finalizar con <0): ";
    cin >> aux;

    while(aux >= 0){
        Nodo * nuevo = new Nodo();
        nuevo->dato = aux;
        nuevo->sig = nullptr;
        
        if(inicio == nullptr){
            inicio = nuevo;
        }
        else{
            Nodo * auxiliar = inicio;
            while(auxiliar->sig != nullptr){
                auxiliar = auxiliar->sig;
            }
            auxiliar->sig = nuevo;
        }
        cout << "Ingrese numero >= 0 (<0 finaliza): ";
        cin >> aux;
    }
    cout << "Se finalizo la carga de numeros." << endl;
}

bool buscar(Nodo * inicio, int buscado){
    Nodo * auxi = inicio;
    while(auxi != nullptr){
        if(auxi->dato == buscado){
            return true;
        }
        auxi = auxi->sig;
    }
    return false;
}

void encontrar(Nodo * inicio){
    int buscado;
    cout << "\nIngrese numero a buscar: ";
    cin >> buscado;
    if(buscar(inicio, buscado)){
        cout << "\nExiste el numero " << buscado << " en la lista." << endl;
    }
    else{
        cout << "\nNo existe el numero " << buscado << " en la lista." << endl;
    }
}

void cant_ocurrencias(Nodo * inicio){
    int aux, contador = 0;
    cout << "\nIngrese numero para saber su cantidad de ocurrencias: ";
    cin >> aux;

    Nodo * aux1 = inicio;
    while(aux1 != nullptr){
        if(aux1->dato == aux){
            contador++;
        }
        aux1 = aux1->sig;
    }

    if(cant_ocurrencias == 0){
        cout << "\nEl numero no existe en la lista." << endl;
        return;
    }

    cout << "\nCantidad de ocurrencias del numero " << aux << ": " << contador << endl;
}

void imprimir_lista(Nodo * inicio){
    if(inicio == nullptr){
        cout << "\nLa lista esta vacia." << endl;
        return;
    }

    Nodo * aux2 = inicio;
    while(aux2 != nullptr){
        cout << aux2->dato << endl;
        aux2 = aux2->sig;
    }
}

void separar_lista(Nodo * &inicio){
    if(inicio == nullptr){
        cout << "\nLa lista esta vacia" << endl;
        return;
    }

    Nodo * aux = inicio;
    Nodo * listaPar = nullptr;
    Nodo * listaImpar = nullptr;

    while (aux != nullptr) {
        Nodo * siguiente = aux->sig;    // guardamos el siguiente antes de modificar
        aux->sig = nullptr;     // “desenlazamos” el nodo actual del siguiente
        if (aux->dato % 2 == 0) {   // insertar al inicio de listaPar
            aux->sig = listaPar;
            listaPar = aux;
        } else {    // insertar al inicio de listaImpar
            aux->sig = listaImpar;
            listaImpar = aux;
        }
        aux = siguiente;    // avanzamos al siguiente nodo
    }

    inicio = nullptr;   // la lista original queda vacía

    cout << "\nLista de pares:" << endl;
    imprimir_lista(listaPar);

    cout << "\nLista de impares:" << endl;
    imprimir_lista(listaImpar);

    cout << "\nLista principal vacía..." << endl;
}

void menu(Nodo * &inicio){
    char opc;
    do{
        cout << "\n-------- MENU PRINCIPAL --------" << endl;
        cout << "\nA. Ingresar numeros" << endl;
        cout << "B. Buscar numero en la lista" << endl;
        cout << "C. Cantidad de ocurrencias de un numero" << endl;
        cout << "D. Separar listas con numeros pares e impares (borra lista principal)" << endl;
        cout << "E. Mostrar lista" << endl;
        cout << "F. Salir del programa" << endl;
        cin >> opc;
        opc = toupper(opc);

        switch(opc){
            case 'A':
                ingresar_dato(inicio);
                break;
            case 'B':
                encontrar(inicio);
                break;
            case 'C':
                cant_ocurrencias(inicio);
                break;
            case 'D':
                separar_lista(inicio);
                break;
            case 'E':
                cout << "Lista principal:" << endl;
                imprimir_lista(inicio);
                break;
            case 'F':
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nIngresa una opcion valida." << endl;
                break;
        }
    }while(opc != 'F');
}

int main(){
    Nodo * inicio = nullptr;

    menu(inicio);

    return 0;
}