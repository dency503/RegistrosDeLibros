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
    cout << "MENU DE OPCIONES\n";
    cout << "1. Agregar publicacion\n";
    cout << "2. Mostrar lista de publicaciones\n";
    cout << "3. Hacer prestamo de libro\n";
    cout << "4. Devolver Libro\n";
    cout << "5. Salir\n";
    cout << "Digite una opcion: ";
    cin >> op;
    return op;
}
Publicacion *agregarPublicacion()
{
    int tipo;
    int cod;
    string t;
    int ap;
    int nr;
    Publicacion *pub;
    cout << "Escriba 1 para revista o 2 para un libro\n";
    cout << "Digite el tipo de publicacion: ";
    cin >> tipo;
    cout << "Digite el codigo de la publicacion: ";
    cin >> cod;
    cout << "Digite el titulo de la publicacion: ";
    cin >> t;
    cout << "Digite el anio de la publicacion: ";
    cin >> ap;
    if (tipo == 1)
    {
        /// Revista
        cout << "Digite el numero de la revista: ";
        cin >> nr;
        pub = new Revista(cod, t, ap, nr);
    }
    else
    {
        /// Libro
        pub = new Libro(cod, t, ap);
    }
    return pub;
}
void mostrarPublicaciones(Publicacion *lt[], int c)
{
    if (c == 0)
    {
        cout << "La lista de publicaciones esta vacia\n";
    }
    else
    {
        cout << "Tipo\tCodigo\tTitulo\tA\n";
        for (int i = 0; i < c; i++)
        {
            if (lt[i]->getAnioPublicacion() == 1)
                ;
            else

                cout << ((lt[i]->getTipoPublicacion() == 1) ? "Revista" : "Libro") << "\t";
            cout << lt[i]->getCodigo() << "\t";
            cout << lt[i]->getTitulo() << "\t";
            cout << lt[i]->getAnioPublicacion() << "\n";
        }
    }
}
/*Libro *buscarLibro(Publicacion *lst[], int c, int cod)
{
    bool encontrado = false;
    int cont = 0;
    Libro *lb = NULL;
    while (cont < c && !encontrado)
    {
        if (lst[cont]->getTipoPublicacion() == 2)
        {
            if (lst[cont]->getCodigo() == cod)
            {
                lb = (Libro *)lst[cont];
                encontrado = true;
            }
            else
            {
                cont++;
            }


    return lb;
}}}*/

Libro *buscarLibro(Publicacion*lst[],int cCli,int id)
{
    bool encontrado= false;
    Libro *lb ;
    int cont =0;
    while (cont<cCli && !encontrado){
            if(lst[cont]->getCodigo() ==  id){
                encontrado = true;
                lb = (Libro *)lst[cont];

            }else{
            cont++;}

    }return lb;

}


void hacerPrestamo(Publicacion *lst[], int c)
{
    int cod;
    if (c == 0)
    {
        cout << "La lista de publicaciones esta vacia\n";
    }
    else
    {
        cout << "Digite el codigo del libro a prestar: ";
        cin >> cod;
        Libro *lb = buscarLibro(lst, c, cod);

        if (lb)
        {
            cout << "Se encontro el libro\n";
            if (lb->getTipoPublicacion() == 1 ){
               cout<<"No se puede prestar una revista\n";
            }else{

            /// Se encontro el libro
            if (lb->prestado() )
            {
                cout << "No se puede hacer el prestamo,porque el libro esta prestado\n";
            }
            else
            {
                cout << "El libro se presto satisfactoriamente\n";
                lb->prestar();

            }
        }}
        else
        {
            cout << "El libro no esta en la lista\n";
        }
    }
}
void hacerDevolucion(Publicacion *lst[], int c)
{
    int cod;
    if (c == 0)
    {
        cout << "La lista de publicaciones esta vacia\n";
    }
    else
    {
        cout << "Digite el codigo del libro a devolver: ";
        cin >> cod;
        Libro *lb = buscarLibro(lst, c, cod);
        if (lb != NULL)
        {
            /// Se encontro el libro
            if (lb->prestado())
            {
                cout << "El proceso de devolucion se hizo correctamente\n";
                lb->devolver();
            }
            else
            {
                cout << "El libro no se puede devolver, porque el libro no ha sido prestado\n";
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
            ///Saliendo....
            system("cls");
            cout << "Saliendo del programa\n";
            break;
        default:
            //El usuario ha selecionado opcion incorreta o ingreso un tipo de valor donde no encaja
            system("cls");
            cout << "Error, opcion no definida\n";
            break;
        }
        system("pause");
    } while (opc != 5);
    return 0;
}
