#include <iostream>
#include <string>
using namespace std;

struct Producto{
    string descripcion;
    float precio;
};

struct Venta{
    Producto producto;
    int cantidad;
};

int main(){
    Venta *pVentas;     //Declaro un puntero al struct Venta
    pVentas = new Venta;    //Reservo memoria dinámica

    /*Ejemplo de acceso:
    pVentas->cantidad = 5;      Accedo con la flecha ->
    pVentas->producto.precio = 1000;    Flecha para acceder al struct y punto para el campo interno
    */

    cout << "Ingresa cantidad vendida: ";
    cin >> pVentas->cantidad;
    cout << "Descripción del producto: ";
    cin >> pVentas->producto.descripcion;
    cout << "Precio del producto: ";
    cin >> pVentas->producto.precio;

    pVentas->producto.precio *= 0.85;

    cout << "Descricpion del producto: " << pVentas->producto.descripcion << endl;
    cout << "Monto total: " << pVentas->producto.precio * pVentas->cantidad << endl;

    return 0;
}