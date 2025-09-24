#include <iostream>
#include <string>
using namespace std;

struct Invitados{
    string nombre, apellido, sexo;
    int edad;
};

string mayuscula(string auxiliar){
    int cadena = auxiliar.length();

    for(int i = 0; i < cadena; i++){
        auxiliar[i] = toupper(auxiliar[i]);
    }
    return auxiliar;
}

void cargarInvitados(Invitados persona[], int & dl, const int maximo){
    string aux;

    cout << "Ingrese el nombre de la persona: ";
    getline(cin>>ws, aux);

    while(mayuscula(aux) != "ZZZ" && dl < maximo){
        persona[dl].nombre = aux;
        cout << "Apellido: ";
        getline(cin>>ws, persona[dl].apellido);
        cout << "Sexo (hombre/mujer): ";
        cin >> persona[dl].sexo;
        cout << "Edad: ";
        cin >> persona[dl].edad;
        dl++;

        cout << "Ingrese el nombre de la persona: ";
        cin >> aux;
    }
    cout << "\nSe finalizo la carga de invitados." << endl;
}

void listado(Invitados persona[], int dl){
    cout << "\nMujeres <= 20:" << endl;

    for(int i = 0; i < dl; i++){
        if(persona[i].edad <= 20 && persona[i].sexo == "mujer"){
            cout << endl;
            cout << "Nombre: " << persona[i].nombre << endl;
            cout << "Apellido: " << persona[i].apellido << endl;
            cout << "Edad: " << persona[i].edad << endl;
        }
    }
}

void borrar_persona(Invitados persona[], int & dl){
    string decision, nombre, apellido;

    cout << "\nDesea borrar a una persona? (s/n): ";
    cin >> decision;

    while(mayuscula(decision) != "N" && dl > 0){
        bool encontrado = false;

        cout << "Ingrese el nombre de la persona: ";
        getline(cin>>ws, nombre);
        cout << "Apellido: ";
        getline(cin>>ws, apellido);

        for(int i = 0; i < dl; i++){
            if(persona[i].nombre == nombre && persona[i].apellido == apellido){
                for(int j = i; j < dl-1; j++){
                    persona[j] = persona[j+1];
                }
                dl--;
                cout << "Se elimino la persona." << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            cout << "La persona no existe o ingreso mal los datos. Intente de nuevo." << endl;
        }

        cout << "\nDesea borrar a una persona? (s/n): ";
        cin >> decision;
    }
    cout << "\nFinalizado el borrado de personas." << endl;
}

void mostrar_invitados(Invitados persona[], int dl){
    cout << "\nListado final de personas:" << endl;
    
    for(int i = 0; i < dl; i++){
        cout << "Nombre: " << persona[i].nombre << endl;
        cout << "Apellido: " << persona[i].apellido << endl;
        cout << "Sexo: " << persona[i].sexo << endl;
        cout << "Edad: " << persona[i].edad << endl;
        cout << endl;
    }
}

int main(){
    const int max_personas = 8;
    Invitados persona[max_personas];
    int cant_invitados = 0;

    cargarInvitados(persona, cant_invitados, max_personas);
    listado(persona, cant_invitados);
    borrar_persona(persona, cant_invitados);
    mostrar_invitados(persona, cant_invitados);

    return 0;
}