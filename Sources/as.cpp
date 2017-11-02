#include "../Headers/as.h"

As::As()
{
    label = new sf::RectangleShape();
    cartas = new lista<Carta*>();
}
void As::ordenarCartasLabel()
{
    if(this->cartas->size() <= 0)
        return;
    int posX = this->label->getPosition().x;
    int posY = this->label->getPosition().y;
    for(int i = 0; i < this->cartas->size(); i++)
    {
        Carta* carta = this->cartas->get(i);
        carta->setPos(posX,posY);
    }
        
}
void As::setPositionAs(int x, int y)
{
    for(int i = 0; i < this->cartas->size(); i++)
    {
        this->cartas->get(i)->setPosition(x,y);
    }
    this->posX = x;
    this->posY = y;
    this->cantCartas = cartas->size();
    this->label->setPosition(x,y);
}

bool As::isAsClicked(sf::Vector2f vec)
{
    sf::FloatRect card = sf::FloatRect(this->posX,this->posY,90,100);
    if(card.contains(vec))
        return true;
    return false;
}
void As::hi()
{
    cout<<"Hola";
}