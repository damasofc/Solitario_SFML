#include "../Headers/carta.h"

Carta::Carta(Figura fig,Tipo ti,Color col, string srcImage)
{
    this->fig = fig;
    this->tip = ti;
    this->col = col;
    this->srcImg = srcImage;
    this->isVisible = false;
    this->imgDefault = "/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/atras_carta.png";
    texture.loadFromFile(imgDefault.c_str());
    this->setTexture(this->texture);
    this->setScale(0.18,0.18);
}

void Carta::setPos(int x, int y)
{
    this->setPosition(x,y);
}

void Carta::show()
{
    this->texture.loadFromFile(srcImg.c_str());
    this->setTexture(this->texture);
}

bool Carta::isClick(sf::Vector2i vec)
{
    sf::FloatRect card = this->getLocalBounds();
    sf::FloatRect mouse = sf::FloatRect(vec.x,vec.y,1,1);
    if(mouse.intersects(card))
        return true;
    return false;
}


