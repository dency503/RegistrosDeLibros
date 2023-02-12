#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include "Publicacion.h"
#include "Prestar.h"
class Libro: public Publicacion, public Prestable
{
private:
    bool estadoPrestamo;
public:
    Libro(int c, string t, int ap):Publicacion(c,t,ap)
    {
        this->estadoPrestamo = false;
    }
    void prestar()
    {
        this->estadoPrestamo=true;
    }
    void devolver()
    {
        this->estadoPrestamo=false;
    }
    bool prestado()
    {
        return this->estadoPrestamo;
    }
    int getTipoPublicacion()
    {
        return 2;
    }
};


#endif // LIBRO_H_INCLUDED
