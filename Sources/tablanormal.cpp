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
        //este if comprueba si la ultima carta, entonces se le
        //aplica el metodo show para que la muestre
        if((*i) == this->cartas->back())
        {
            (*i)->show();
        }
        (*i)->setPos(posX,posY+cont);
        cont+=23;
    }
    sf::Vector2f siz = this->label->getSize();
    if(this->cartas->size() >0)
        this->label->setSize(sf::Vector2f(siz.x,120+((this->cartas->size()-1)*23)));
}
bool TablaNormal::isTablaLlena()
{
    return (this->cantCartas >= this->cantMaxCartas)?true:false;
}
