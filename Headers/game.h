#ifndef GAME_H
#define GAME_H

#include "tablanormal.h"
#include <SFML/Graphics.hpp>
#include "mazo.h"
#include <list>
#include <map>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <stdlib.h>
#include <time.h>


class Game
{
public:
    //METODOS
    Game();
    void repartirCartas();//este metodo es el que se ejecuta solo al incio
    void colocarCarta(TablaNormal *tb);//este metodo toma del mazo para colocar en la tabla que le dicen, solo se ejecutara al inicio
    void addCarta(Tabla *tbAdd,Carta *cr);
    void moverCarta(Tabla *tbFrom,Tabla *tbTo,Carta* carta);
    void sacarCarta(Tabla *tb,Carta *cr);
    sf::RectangleShape* crearLabel(int width, int height,int posX, int posY);
    void createAllLabels(list<TablaNormal*> tablas);
    void drawLabel(sf::RectangleShape* label);
    void drawAllLabels();
    void loadAllCards();
    void drawAllCards();
    void orderCards();
    //PRUEBA 
    void moverCartaMazo(Tabla *tbFrom,Tabla *tbTo,Carta* carta);
    //PRUEBA FIN
    void moverVarias(Tabla* tabla,Tabla* tbTo, Carta* carta);
    void sort(list<Carta*> *cartas,int size);
    Carta* obtener(int pos,list<Carta*> *ca);
    void swap(Carta* c1,Carta* c2);
    bool evaluarMovimiento(Tabla *tbTo,Carta* carta);
    Carta* getCardClicked(sf::Vector2f vec);
    Tabla* getTableClicked(sf::Vector2f vec);
    void gameLoop();
    
    
    
    
    //VARIABLES
    bool moving;
    sf::Vector2f oldPos;
    
    list<Carta*>* cartas;
    list <TablaNormal*> tablas;
    Mazo *mazo;
    list<sf::RectangleShape*> labelsAs;
    const float HEIGHT = 750;
    const float WIDTH = 1100;
    sf::RenderWindow window;
};

#endif // MANAGERTABLAS_H
