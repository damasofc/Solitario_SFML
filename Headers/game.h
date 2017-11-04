#ifndef GAME_H
#define GAME_H

#include "tablanormal.h"
#include <SFML/Graphics.hpp>
#include "mazo.h"
#include "lista.h"
#include "as.h"
#include <map>
#include "tabla.h"

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
    void createAllLabels(lista<TablaNormal*> tablas);
    void drawLabel(sf::RectangleShape* label);
    void drawAllLabels();
    void loadAllCards();
    void drawAllCards();
    void orderCards();
    //PRUEBA 
    void moverCartaMazo(Tabla *tbFrom,Tabla *tbTo,Carta* carta);
    //PRUEBA FIN
    void moverVarias(Tabla* tabla,Tabla* tbTo, Carta* carta);
    void sort(lista<Carta*> *cartas,int size);
    void swap(Carta* c1,Carta* c2);
    bool evaluarMovimiento(Tabla *tbTo,Carta* carta);
    Carta* getCardClicked(sf::Vector2f vec);
    Tabla* getTableClicked(sf::Vector2f vec);
    bool gano(lista<As*> ases);
    void gameLoop();
    
    
    
    
    //VARIABLES
    bool moving;
    sf::Vector2f oldPos;
    

    lista<As*> ases;
    lista<Carta*>* cartas;
    lista<TablaNormal*> tablas;
    Mazo *mazo;
    lista<sf::RectangleShape*> labelsAs;
    const float HEIGHT = 850;
    const float WIDTH = 1100;
    sf::RenderWindow window;
};

#endif // MANAGERTABLAS_H
