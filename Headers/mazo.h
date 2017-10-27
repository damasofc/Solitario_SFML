#ifndef MAZO_H
#define MAZO_H
#include "tabla.h"


class Mazo : public Tabla
{
public:
    Mazo();
    list <Carta*>* cartasMostradas;
    void setPositionMazo(int x, int y);
    void showCartaMazo(Carta* carta);
};

#endif // MAZO_H
