#include <iostream>
using namespace std;

int main(){
    char *x = new char;
    char *z = x;

    //A
    *x = 'M';

    //B
    cout << *x << endl;

    //C
    *z = 'P';

    //D
    cout << *z << " " << *x << endl;
    /*---- Imprime la P en ambos ya que *z apunta al mismo espacio que x ----*/

    //E
    delete x;
    //cout << *z;
    /*---- Si quiero mostrar el valor del puntero va a mostrar
    contenido basura porque apunta a una dirección que ya fue liberada ----*/

    //F
    x = new char;

    //G
    cout << "Ingrese un caracter: ";
    cin >> *x;

    //H
    if(*x == '*'){
        cout << "asterisco" << endl;
    }

    return 0;
}