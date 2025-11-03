#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo * sig;
};

int main(){
    int n;
    Nodo * inicio = nullptr;

    cout << "Ingrese un numero (0 para finalizar): ";
    cin >> n;

    while(n != 0){
        Nodo * nuevo = new Nodo();
        nuevo->dato = n;    //Guardo el dato.
        nuevo->sig = nullptr;   //El nuevo nodo no apunta a nada al principio.

        if(inicio == nullptr){  //Si la lista está vacía, el último nodo será el primero.
            inicio = nuevo;
        }
        else{   //Si la lista tiene elementos, buscamos el último e insertamos a continuación.
            Nodo * aux = inicio;    //Uso puntero auxiliar par evitar perder el inicial.
            while(aux->sig != nullptr){     //Busco el ultimo.
                aux = aux->sig;
            }
            aux->sig = nuevo;   //Agrego el elemento al final de la lista.
        }

        cout << "Ingrese un numero (0 para finalizar): ";
        cin >> n;
    }

    //Imprimir lista
    Nodo * aux2 = inicio;
    while(aux2 != nullptr){
        cout << aux2->dato << endl;
        aux2 = aux2->sig;
    }

    return 0;
}