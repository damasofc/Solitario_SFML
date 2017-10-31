#include "../Headers/mazo.h"

Mazo::Mazo()
{
    cartas = new list<Carta*>();
    cartasMostradas = new list<Carta*>();
    this->cantCartas = cartas->size();
}

void Mazo::setPositionMazo(int x, int y)
{ 
    list<Carta*>::iterator it = this->cartas->begin();
    while(it!= this->cartas->end())
    {
        (*it)->setPosition(x,y);
        it++;
    }
    list<Carta*>::iterator i = this->cartasMostradas->begin();
    while(i!= this->cartasMostradas->end())
    {
        (*i)->setPosition(x-150,y);
        it++;
    }
    this->posX = x;
    this->posY = y;
    this->cantCartas = cartas->size();
}
bool Mazo::isMazoClicked(sf::Vector2f vec)
{
    sf::FloatRect card = sf::FloatRect(950,30,90,100);
    if(card.contains(vec))
        return true;
    return false;
}
void Mazo::ordenarCartasMostradas()
{
    int posX = 800;
    int posY = 30;
    for(list<Carta*>::iterator i = this->cartasMostradas->begin();i!=this->cartasMostradas->end();i++)
    {
        (*i)->setPos(posX,posY);
    }
}
void Mazo::putShowCardsInMazo()
{
        list<Carta*>::iterator it = this->cartasMostradas->end();
        it--;
        for(it;it!= this->cartasMostradas->begin();it--)
        {
            (*it)->hide();
            (*it)->setPosition(this->posX,this->posY);
            this->cartas->push_back(*it);
            this->cartasMostradas->remove(*it);
        }
}
void Mazo::showCartaMazo()
{
    if(this->cartas->size() >= 1)
    {
        list<Carta*>::iterator i = this->cartas->begin();
        this->cartasMostradas->push_back((*i));
        (*i)->show();
        this->cartas->remove((*i));
        list<Carta*>::iterator it = this->cartasMostradas->begin();
        while(it!= this->cartasMostradas->end())
        {
            (*it)->setPosition(800,30);
            it++;
        }

    }
    this->cantCartas = cartas->size();
}
