#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    string palabra;
    Nodo * siguiente;
};

string minuscula(string aux){
    int longitud = aux.length();
    for(int i = 0; i < longitud; i++){
        aux[i] = tolower(aux[i]);
    }
    return aux;
}

void insertarOrdenado(Nodo *& inicio, string palabra){
    Nodo * nuevo = new Nodo();
    nuevo->palabra = palabra;
    nuevo->siguiente = nullptr;
    // Caso 1: lista vacía o va al principio
    if(inicio == nullptr || palabra < inicio->palabra){
        nuevo->siguiente = inicio;
        inicio = nuevo;
        return;
    }
    // Caso 2: buscar su lugar
    Nodo * aux = inicio;
    while(aux->siguiente != nullptr && aux->siguiente->palabra < palabra){
        aux = aux->siguiente;
    }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
}

void cargarLista(Nodo *& inicio){
    string aux;
    cout << "Ingresa una palabra ('fin' para finalizar): ";
    cin >> aux;
    aux = minuscula(aux);
    while(aux != "fin"){
        insertarOrdenado(inicio, aux);
        cout << "Ingresa una palabra ('fin'): ";
        cin >> aux;
        aux = minuscula(aux);
    }
    cout << "Se finalizo la carga de la Lista" << endl;
}

Nodo * ordenarLista(Nodo * lista1, Nodo * lista2){
    if(lista1 == nullptr && lista2 == nullptr){
        cout << "\nAmbas listas vacias." << endl;
        return nullptr;
    }
    Nodo * resultado = nullptr;
    // Pasar los elementos de la lista 1
    Nodo * aux = lista1;
    while(aux != nullptr){
        insertarOrdenado(resultado, aux->palabra);
        aux = aux->siguiente;
    }
    // Pasar los elementos de la lista 2
    aux = lista2;
    while(aux != nullptr){
        insertarOrdenado(resultado, aux->palabra);
        aux = aux->siguiente;
    }
    return resultado;
}

void imprimir(Nodo * inicio){
    Nodo * aux = inicio;
    while(aux != nullptr){
        cout << aux->palabra << endl;
        aux = aux->siguiente;
    }
}

int main(){
    Nodo * lista1 = nullptr;
    Nodo * lista2 = nullptr;
    cout << "Carga de lista 1:" << endl;
    cargarLista(lista1);
    cout << "\nCarga de lista 2:" << endl;
    cargarLista(lista2);
    Nodo * listaFinal = ordenarLista(lista1, lista2);
    cout << "\nLista ordenada alfabeticamente:" << endl;
    imprimir(listaFinal);
    return 0;
}