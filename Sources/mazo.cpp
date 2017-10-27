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
}
void Mazo::showCartaMazo(Carta *carta)
{

}
