#ifndef TABLA_H
#define TABLA_H

#include <list>

#include "carta.h"


class Tabla
{
public:
    Tabla();
    list<Carta*>* cartas;
    int cantCartas;
    
};

#endif // TABLA_H
