#include "../Headers/tablanormal.h"

TablaNormal::TablaNormal(int maxCartas)
{
    this->cantMaxCartas = maxCartas;
    label = new sf::RectangleShape();
    this->cantCartasOcultas = 0;
    cartas = new lista<Carta*>();
}

void TablaNormal::ordenarCartasLabel()
{
    int posX = this->label->getPosition().x;
    int posY = this->label->getPosition().y;
    int cont = 0;
    for(int i = 0; i < this->cartas->size(); i++)
    {
        Carta* carta = this->cartas->get(i);
        if(carta == this->cartas->back())
        {
            carta->show();
        }
        carta->setPos(posX,posY+cont);
        cont+=30;
    }
    sf::Vector2f siz = this->label->getSize();
    if(this->cartas->size() > 0)
        this->label->setSize(sf::Vector2f(siz.x,120+((this->cartas->size()-1)*30)));
}
bool TablaNormal::isTablaLlena()
{
    return (this->cantCartas >= this->cantMaxCartas)?true:false;
}
