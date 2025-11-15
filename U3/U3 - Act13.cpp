#include <iostream>
using namespace std;

struct Prod{
    int codigo, cantVendida = 0;
};

struct Nodo{
    Prod p;
    Nodo * sig;
};

void insertarNodo(Nodo *& inicio, Nodo *& nuevo){
    if(inicio == nullptr || nuevo->p.codigo < inicio->p.codigo){
        nuevo->sig = inicio;
        inicio = nuevo;
    }
    else{
        Nodo * aux = inicio;
        while(aux->sig != nullptr && aux->sig->p.codigo < nuevo->p.codigo){
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

void cargarProducto(Nodo *& inicio){
    int code;
    cout << "Ingresa codigo del producto [-1 para finalizar]: ";
    cin >> code;
    while(code != -1){
        Nodo * nuevo = new Nodo();
        nuevo->p.codigo = code;
        cout << "Ingrese cantidad vendida del producto: ";
        cin >> nuevo->p.cantVendida;
        insertarNodo(inicio, nuevo);
        cout << "Ingresa codigo del producto [-1 para finalizar]: ";
        cin >> code;
    }
    cout << "Se finalizo la carga de productos." << endl;
}

Nodo * unirListas(Nodo *& l1, Nodo *& l2){
    Nodo * inicio = nullptr;
    Nodo * ultimo = nullptr;
    while(l1 != nullptr && l2 != nullptr){
        Nodo * menor;
        if(l1->p.codigo <= l2->p.codigo){
            menor = l1;
            l1 = l1->sig;   // Avanzo l1
        }
        else{
            menor = l2;
            l2 = l2->sig;   // Caso contrario avanzo l2
        }
        menor->sig = nullptr;   // Limpio el puntero
        if(inicio == nullptr){
            inicio = menor;     // Primer nodo del resultado
            ultimo = menor;
        }
        else{
            ultimo->sig = menor;    // Lo engancho al final
            ultimo = menor;     // Actualizo ultimo
        }
    }
    // En caso de que alguna lista tenga nodos restantes
    if(l1 != nullptr){
        if(inicio == nullptr) inicio = l1;
        else ultimo->sig = l1;
    }
    else if(l2 != nullptr){
        if(inicio == nullptr) inicio = l2;
        else ultimo->sig = l2;
    }
    // Vacio las listas originales
    l1 = nullptr;
    l2 = nullptr;
    return inicio;
}

void imprimirLista(Nodo * inicio){
    while(inicio != nullptr){
        cout << "\nCodigo de producto: " << inicio->p.codigo << endl;
        cout  << "Cantidad vendida: " << inicio->p.cantVendida << endl;
        inicio = inicio->sig;
    }
}

int main(){
    Nodo * sucursal1 = nullptr;
    Nodo * sucursal2 = nullptr;
    cout << "Sucursal 1:----------" << endl;
    cargarProducto(sucursal1);
    cout << "\nSucursal 2:----------" << endl;
    cargarProducto(sucursal2);
    if(sucursal1 == nullptr && sucursal2 == nullptr){
        cout << "\nAmbas listas vacias." << endl;
    }
    else{
        Nodo * listaFinal = unirListas(sucursal1, sucursal2);
        cout << "\nAmbas listas ordenadas:";
        imprimirLista(listaFinal);
    }
    return 0;
}