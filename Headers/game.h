#ifndef GAME_H
#define GAME_H

#include "tablanormal.h"
#include <SFML/Graphics.hpp>
#include "mazo.h"
#include <list>
#include <map>


#include <stdlib.h>
#include <time.h>


class Game
{
public:
    //METODOS
    Game();
    void repartirCartas();//este metodo es el que se ejecuta solo al incio
    void colocarCarta(TablaNormal *tb);//este metodo toma del mazo para colocar en la tabla que le dicen, solo se ejecutara al inicio
    bool isTablaLlena(TablaNormal *tb);
    void addCarta(Tabla *tbAdd,Carta *cr);
    void moverCarta(Tabla *tbFrom,Tabla *tbTo,Carta* carta);
    void sacarCarta(Tabla *tb,Carta *cr);
    sf::RectangleShape* crearLabel(int width, int height,int posX, int posY);
    void createAllLabels(list<TablaNormal*> tablas);
    void drawLabel(sf::RectangleShape* label);
    void drawAllLabels();
    void loadAllCards();
    void sortCards(list<Carta*> *cards);
    void drawAllCards();
    void orderCards();
    Carta* getCardClicked(sf::Vector2i vec);
    Tabla* getTableClicked(sf::Vector2i vec);
    void gameLoop();
    
    
    
    
    //VARIABLES
    bool moving;
    
    list<Carta*>* cartas;
    list <TablaNormal*> tablas;
    Mazo *mazo;
    const float HEIGHT = 750;
    const float WIDTH = 1100;
    sf::RenderWindow window;
};

#endif // MANAGERTABLAS_H
