#ifndef AS_H
#define AS_H
#include "tabla.h"
#include <SFML/Graphics.hpp>


class As : public Tabla
{
public:
    As();
    sf::RectangleShape* label;
    int posX;
    int posY;
    void setPositionAs(int x, int y);
    bool isAsClicked(sf::Vector2f vec);
    void hi();
    void ordenarCartasLabel();
};

#endif 

