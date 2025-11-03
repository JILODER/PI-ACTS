#include <iostream>
using namespace std;

struct Nodo{    //Estructura basica de nodo.
    int dato;
    Nodo * siguiente;
};

int main(){
    int n;
    Nodo * inicio = nullptr;    //Declaro un puntero que no apunta a nada.

    cout << "Ingrese un numero (0 para finalizar): ";   //Ingresa un dato.
    cin >> n;

    while(n != 0){      //El ultimo nodo ingresado lo dejo primero
        Nodo * nuevo = new Nodo();
        nuevo->dato = n;
        nuevo->siguiente = inicio;
        inicio = nuevo;

        cout << "Ingrese un numero (0 para finalizar): ";
        cin >> n;
    }

    //Imprimir lista
    Nodo * aux = inicio;
    while(aux != nullptr){
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }

    return 0;
}