#ifndef MAZO_H
#define MAZO_H
#include "tabla.h"
#include "lista.h"


class Mazo : public Tabla
{
public:
    Mazo();
    lista <Carta*>* cartasMostradas;
    int posX;
    int posY;
    void setPositionMazo(int x, int y);
    void showCartaMazo();
    bool isMazoClicked(sf::Vector2f vec);
    void ordenarCartasMostradas();
    void putShowCardsInMazo();
};

#endif // MAZO_H
