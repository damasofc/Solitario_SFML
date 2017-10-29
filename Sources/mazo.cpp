#include "../Headers/mazo.h"

Mazo::Mazo()
{
    cartas = new list<Carta*>();
    cartasMostradas = new list<Carta*>();
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
}
bool Mazo::isMazoClicked(sf::Vector2f vec)
{
    sf::FloatRect card = sf::FloatRect(950,30,90,100);
    if(card.contains(vec))
        return true;
    return false;
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
}
