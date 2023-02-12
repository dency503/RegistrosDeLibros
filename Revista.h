#ifndef REVISTA_H_INCLUDED
#define REVISTA_H_INCLUDED
#include"Publicacion.h"
class Revista: public Publicacion
{
private:
    int numeroRevista;

public:
    Revista(int c, string t, int ap, int nr ): Publicacion(c,t,ap)
    {
        this->numeroRevista =nr;
    }
    int getTipoPublicacion()
    {
        return 1;

    }

};



#endif // REVISTA_H_INCLUDED
