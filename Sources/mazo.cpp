#include "../Headers/mazo.h"

Mazo::Mazo()
{
    cartas = new lista<Carta*>();
    cartasMostradas = new lista<Carta*>();
    this->cantCartas = cartas->size();
}

void Mazo::setPositionMazo(int x, int y)
{
    for(int i = 0; i < this->cartas->size(); i++)
    {
        this->cartas->get(i)->setPosition(x,y);
    }
    for(int i = 0; i < this->cartasMostradas->size(); i++)
    {
        this->cartasMostradas->get(i)->setPosition(x-150,y);
    }
    this->posX = x;
    this->posY = y;
    this->cantCartas = cartas->size();
}
bool Mazo::isMazoClicked(sf::Vector2f vec)
{
    sf::FloatRect card = sf::FloatRect(950,30,90,120);
    if(card.contains(vec))
        return true;
    return false;
}
void Mazo::ordenarCartasMostradas()
{
    int posX = 800;
    int posY = 30;
    for(int i = 0; i < this->cartasMostradas->size(); i++)
    {
        this->cartasMostradas->get(i)->setPos(posX,posY);
    }
}
void Mazo::putShowCardsInMazo()
{
        for(int i = this->cartasMostradas->size()-1; i >=0; i--)
        {
            Carta* carta = this->cartasMostradas->get(i);
            carta->hide();
            carta->setPosition(this->posX,this->posY);
            this->cartas->push_back(carta);
            this->cartasMostradas->remove(carta);
        }
}
void Mazo::showCartaMazo()
{
    if(this->cartas->size() >= 1)
    {
        Carta* carta = this->cartas->front();
        this->cartasMostradas->push_back(carta);
        carta->show();
        this->cartas->remove(carta);
        for(int i = 0; i < this->cartasMostradas->size(); i++)
        {
            Carta* car = this->cartasMostradas->get(i);
            car->setPosition(800,30);
        }
        
    }
    this->cantCartas = cartas->size();
}
void Mazo::hi()
{
    
}
