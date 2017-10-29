#ifndef MAZO_H
#define MAZO_H
#include "tabla.h"


class Mazo : public Tabla
{
public:
    Mazo();
    list <Carta*>* cartasMostradas;
    void setPositionMazo(int x, int y);
    void showCartaMazo();
    bool isMazoClicked(sf::Vector2f vec);
};

#endif // MAZO_H
