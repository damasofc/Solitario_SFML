#ifndef TABLANORMAL_H
#define TABLANORMAL_H
#include "tabla.h"
#include <SFML/Graphics.hpp>


class TablaNormal : public Tabla
{
public:
    TablaNormal(int maxCartas);
    sf::RectangleShape* label;
    int cantMaxCartas;
    int cantCartasOcultas;
    int cantCartasVisibles;

    void ordenarCartasLabel();
    bool isTablaLlena();
};

#endif // TABLANORMAL_H
