#include <iostream>
#include <string>
using namespace std ;

struct Producto{
    int codigo ;
    string descriocion ;
    double precio ;
    int stock ;
};

struct Nodo{
    Producto dato ;
    Nodo * siguiente ;
};

void InsertarNodo(Nodo *& Lista, Nodo * nodo){  //Se inserta al principio
    nodo->siguiente = Lista;
    Lista = nodo ;
}

void IncrementarPrecios(Nodo * Lista){
    int porcentaje ;
    cout << "Ingrese el porcentaje que desea aumentar: ";
    cin >> porcentaje;
    Nodo * aux = Lista ;
    while (aux != nullptr){
        porcentaje = porcentaje / aux->dato.precio * 100;
        aux->dato.precio += porcentaje ;
        aux = aux->siguiente ;
    }
}

Nodo * VerificarProducto(Nodo * Lista , int codigo){
    Nodo * aux = Lista ;
    while (aux != nullptr && aux->dato.codigo != codigo){
        aux = aux->siguiente ;
    }
    return  aux ;
}

void IncrementarStock(Nodo * Lista){
    int codigo ;
    int cantidad ;
    cout << "Ingrese el codgio de producto que desee incrementar: " << endl ;
    cin >> codigo ;
    Nodo * posicion = VerificarProducto(Lista,codigo);
    if (posicion != nullptr){
        cout << "Ingrese la cantidad que desea incrementar: " << endl;
        cin >> cantidad ;
        while (cantidad < 0){
            cout <<"Ingrese una cantidad valida!: " ;
            cin >> cantidad ;
        }
        posicion->dato.stock += cantidad ;
    }
    else{
        cout <<"HJP no se encuentra el producto, Juani Wachin!!" << endl ;
    }
}

void EliminarNodo(Nodo * & Lista, int codigo){
    Nodo * aux = Lista ;
    if (aux->dato.codigo == codigo){
        Lista = Lista->siguiente ;
        delete aux ;
    }
    else{
        while(aux->siguiente != nullptr && aux->siguiente->dato.codigo != codigo){
            aux = aux->siguiente ;
        }
        Nodo * temp = aux->siguiente ;
        aux->siguiente = aux->siguiente->siguiente ;
        delete temp;
    }
}

void EliminarProducto (Nodo * & Lista){
    int codigo ;
    cout <<"Ingrese el codigo que desee eliminar: " ;
    cin >> codigo ;
    Nodo * p = VerificarProducto(Lista,codigo) ;
    if (p != nullptr){
        EliminarNodo(Lista,codigo) ;
    }
    else{
        cout <<"El producto no se encuentra en la lista." << endl  ;
    }

}

void CargarLista(Nodo * & Lista){
    Producto p ;
    cout << "Ingrese  el codigo de un articulo [-1] para finalizar: " << endl  ;
    cin >> p.codigo ;
    while (p.codigo != -1){
        cout << "Ingrese la descripción: " << endl; // Se solicita todos los datos ;
        cin >>p.descriocion ; 
        cout << "Ingrese el precio: " << endl; // Se solicita todos los datos ;
        cin >>p.precio ; 
        cout << "Ingrese la cantidad del producto: " << endl; // Se solicita todos los datos ;
        cin >>p.stock ; 
        Nodo * nuevo = new Nodo();
        nuevo->dato = p ;
        InsertarNodo(Lista,nuevo) ;
        cout << "Ingrese el codigo de un articulo [-1] para finalizar: " << endl ; 
        cin >> p.codigo;
    }
}

int main (){
    Nodo * Lista = nullptr ;
    CargarLista(Lista);
    IncrementarPrecios(Lista);
    IncrementarStock (Lista) ;
}