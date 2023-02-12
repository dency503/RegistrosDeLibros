#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Publicacion.h"
#include "Prestar.h"
#include "Revista.h"
#include "Libro.h"
#define TAM 5

int menu()
{
    int op;
    cout << "Menu:" << endl;
    cout << "1. Registrar publicacion" << endl;
    cout << "2. Mostrar publicaciones" << endl;
    cout << "3. Hacer prestamo" << endl;
    cout << "4. Devolver libro" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";

    cin >> op;
    return op;
}
Publicacion *agregarPublicacion()
{
    int tipo, codigo;
    string titulo;
    int anioPublicacion;

    Publicacion *pub;
    cout << "Escriba 1 para revista o 2 para un libro: ";
    cin >> tipo;
    cout << "Codigo:";
    cin >> codigo;
    cout << "Titulo: ";
    cin >> titulo;
    cout << "Digite el anio de la publicacion: ";
    cin >> anioPublicacion;
    if (tipo == 1)
    {

        /// Revista
        int numeroRevista;
        cout << "Digite el numero de la revista: ";
        cin >> numeroRevista;
        pub = new Revista(codigo, titulo, anioPublicacion, numeroRevista);
    }
    else if (tipo == 2)
    {
        /// Libro
        pub = new Libro(codigo, titulo, anioPublicacion);
    }
    else
    {
        cout << "Opcion no valida." << endl;
    }
    return pub;
}
void mostrarPublicaciones(Publicacion *publicaciones[], int contador)
{
    if (contador == 0)
    {
        cout << "La lista de publicaciones esta vacia\n";
    }
    else
    {

        for (int i = 0; i < contador; i++)
        {
            cout << "ID: " << i << endl;
            cout << "Codigo: " << publicaciones[i]->getCodigo() << endl;
            cout << "Titulo: " << publicaciones[i]->getTitulo() << endl;
            cout << "Anio: " << publicaciones[i]->getAnioPublicacion() << endl;
            cout << "Tipo: " << ((publicaciones[i]->getTipoPublicacion() == 1) ? "Revista" : "Libro");

            cout << "\n====================================\n"
                 << endl;
        }
    }
}

Libro *buscarLibro(Publicacion *lstPublicacion[], int contador, int codigo)
{
    bool encontrado = false;
    int cont = 0;
    while (cont < contador && !encontrado)
    {
        if (lstPublicacion[cont]->getCodigo() == codigo)
        {
            encontrado = true;

            /*dynamic_cast se utiliza principalmente en programacion orientada a objetos para hacer conversion segura de tipos en sistemas con herencia. Por ejemplo,
             supongamos que tenemos una clase base "Publicacion" y una clase derivada "Libro". Si tenemos un puntero a "Publicacion" que realmente apunta a un objeto de tipo "Libro",
              podemos hacer una conversion segura a "Libro" usando dynamic_cast.
            De esta manera, podemos aprovechar las caracter�sticas y metodos especificos de la clase "Libro" sin correr el riesgo de acceder a un objeto de un tipo equivocado.*/

            if (Libro *lb = dynamic_cast<Libro *>(lstPublicacion[cont]))
            {
                return lb;
            }
        }
        else
        {
            cont++;
        }
    }
    return nullptr;
}

void hacerPrestamo(Publicacion *lstPublicacion[], int contador)
{
    int codigo;
    if (contador == 0)
    {
        cout << "La lista de publicaciones esta vacia\n";
    }
    else
    {
        cout << "Digite el codigo del libro a prestar: ";
        cin >> codigo;
        Libro *lb = buscarLibro(lstPublicacion, contador, codigo);

        if (lb)
        {
            if (lb->prestado())
            {
                cout << "Lo sentimos, el libro con codigo " << codigo << " no esta disponible para prestamo." << endl;
            }
            else
            {
                lb->prestar();
                cout << "El libro con codigo " << codigo << " ha sido prestado exitosamente." << endl;
            }
        }
        else
        {
            cout << "Lo sentimos, el libro con codigo " << codigo << " no se encuentra en la lista." << endl;
        }
    }
}
void hacerDevolucion(Publicacion *lstPublicaciones[], int contador)
{
    int codigo;
    if (contador == 0)
    {
        cout << "La lista de publicaciones esta vacia\n";
    }
    else
    {
        cout << "Ingrese Codigo del libro a devolver: ";
        cin >> codigo;
        Libro *lb = buscarLibro(lstPublicaciones, contador, codigo);
        if (lb != nullptr)
        {
            /// Se encontro el libro
            if (lb->prestado())
            {

                lb->devolver();
                cout << "Libro devuelto exitosamente." << endl;
            }
            else
            {
                cout << "Libro ya se encuentra disponible." << endl;
            }
        }
        else
        {
            cout << "El libro no esta en la lista\n";
        }
    }
}

int main()
{
    int opc;
    Publicacion *lista[TAM];
    int cont = 0;
    do
    {
        system("cls");
        opc = menu();
        switch (opc)
        {
        case 1:
            /// captura de publicaciones
            system("cls");
            if (cont < TAM)
            {
                lista[cont] = agregarPublicacion();
                cont++;
            }
            else
            {
                cout << "La lista de publicaciones esta llena\n";
            }
            break;
        case 2:
            /// Mostrar publicaciones
            system("cls");
            mostrarPublicaciones(lista, cont);
            break;
        case 3:
            /// Hacer prestamos
            system("cls");
            hacerPrestamo(lista, cont);
            break;
        case 4:
            /// Devolver
            system("cls");
            hacerDevolucion(lista, cont);
            break;
        case 5:
            /// Saliendo....
            system("cls");
            cout << "Adios!!\n";
            break;
        default:
            /// El usuario ha selecionado opcion incorreta o ingreso un tipo de valor donde no encaja con la variable
            system("cls");
            cout << "Opcion no valida." << endl;
            break;
        }
        system("pause");
    } while (opc != 5);
    return 0;
}
