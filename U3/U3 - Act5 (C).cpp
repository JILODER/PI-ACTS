#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo * sig;
};

//void insertar_ordenado(Nodo * inicio, Nodo * nuevo){}   //Puedo retornar tipo Nodo, o si es void paso el inicio como referencia.

int main(){
    int n;
    Nodo * inicio = nullptr;

    cout << "Ingrese un dato: ";
    cin >> n;

    while(n != 0){
        Nodo * nuevo = new Nodo();
        nuevo->dato = n;
        
        if(inicio == nullptr || nuevo->dato < inicio->dato){    //Si la lista esta vacia o el elemento insertado es más chico que el menor elemento.
            nuevo->sig = inicio;
            inicio = nuevo;
        }

        else{
            Nodo * aux = inicio;
            while(aux->sig != nullptr && aux->sig->dato < nuevo->dato){    //Busco en la lista el primer numero que sea mayor al dato ingresado.
                aux = aux->sig;
                nuevo->sig = aux->sig;   //El nuevo nodo apunta al siguiente nodo.
                aux->sig = nuevo;   //Enlazo el nodo anterior al nuevo nodo.
            }
        }
    }

    //Imprimir lista
    Nodo * aux2 = inicio;
    while(aux2 != nullptr){
        cout << aux2->dato << endl;
        aux2 = aux2->sig;
    }

    return 0;
}