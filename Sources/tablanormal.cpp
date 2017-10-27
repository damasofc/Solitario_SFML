#include "../Headers/tablanormal.h"

TablaNormal::TablaNormal(int maxCartas)
{
    this->cantMaxCartas = maxCartas;
    label = new sf::RectangleShape();
    this->cantCartasOcultas = 0;
    cartas = new list<Carta*>();
}

void TablaNormal::ordenarCartasLabel()
{
    int posX = this->label->getPosition().x;
    int posY = this->label->getPosition().y;
    int cont = 0;
    for(list<Carta*>::iterator i = this->cartas->begin();i!=this->cartas->end();i++)
    {
        (*i)->setPos(posX,posY+cont);
        cont+=23;
    }
}
