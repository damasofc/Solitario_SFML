#ifndef TABLA_H
#define TABLA_H

#include <list>
#include "lista.h"

#include "carta.h"


class Tabla
{
public:
    Tabla();
    lista<Carta*>* cartas;
    int cantCartas;
    
};

#endif // TABLA_H
