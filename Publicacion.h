#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include <string.h>
using namespace std;
class Publicacion
{
protected:
    int codigo;
    string titulo;
    int anioPublicacion;
public:
    Publicacion(int c, string t,int ap)
    {
        this -> codigo=c;
        this -> titulo=t;
        this -> anioPublicacion=ap;
    }
    void setCodigo(int c)
    {
        this->codigo=c;
    }
    int getCodigo(){
    return this->codigo;
    }
    void setTitulo(string t)
    {
        this->titulo=t;
    }
    string getTitulo(){
    return this->titulo;
    }
        void setAnioPublicacion(int ap)
    {
        this->anioPublicacion=ap;
    }
    int getAnioPublicacion(){
    return this->anioPublicacion;
    }
    virtual int getTipoPublicacion()=0;

};


#endif // PUBLICACION_H_INCLUDED
