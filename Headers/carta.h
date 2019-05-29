#ifndef CARTA_H
#define CARTA_H


#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
enum Figura {DIAMANTE, CORAZON,ESPADA,TREBOL};
enum Tipo{KING,QUEEN,JACK,TEN,NINE,EIGHT,SEVEN,SIX,FIVE,FOUR,THREE,TWO,AS};
enum Color{RED,BLACK};

class Carta : public sf::Sprite
{
public:
    
    Carta(Figura fig,Tipo ti,Color col, string srcImage);
    Figura fig;
    Tipo tip;
    Color col;
    string srcImg;
    string imgDefault;
    bool isVisible;
    bool isClick(sf::Vector2f vec);
    sf::Texture texture;
    void setPos(int x, int y);
    void show();
    void hide();
    int clicks;


};
#endif

