#ifndef REVISTA_H_INCLUDED
#define REVISTA_H_INCLUDED
#include "Publicacion.h"
class Revista : public Publicacion
{
private:
    int numeroRevista;

public:
    Revista(int codigo, string titulo, int aniopublicacion, int numeroRevista) : Publicacion(codigo, titulo, aniopublicacion)
    {
        this->numeroRevista = numeroRevista;
    }
    int getTipoPublicacion()
    {
        return 1;
    }
};

#endif // REVISTA_H_INCLUDED
