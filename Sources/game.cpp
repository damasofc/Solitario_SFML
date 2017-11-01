#include "../Headers/game.h"

Game::Game()
{
    window.create(sf::VideoMode(WIDTH,HEIGHT),"Solitario | Damasofc",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    cartas = new lista<Carta*>();
    loadAllCards();
    sort(this->cartas,this->cartas->size());
    this->mazo = new Mazo();
    mazo->cartas = cartas;
    for (int i = 0; i < 7; i++) {
        this->tablas.push_back(new TablaNormal(i+1));
    }
    createAllLabels(this->tablas);
    repartirCartas();
    mazo->setPositionMazo(950,30);
    
}
void Game::swap(Carta* c1, Carta* c2)
{
    Carta temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
void Game::sort(lista<Carta*> *cartas, int size)
{
    lista<Carta*> *miList = new lista<Carta*>();
    srand ( time(NULL) );

    for (int i = size-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(cartas->get(i), cartas->get(j));
        cartas->get(i)->hide();
        cartas->get(j)->hide();
    }
    
}
bool Game::evaluarMovimiento(Tabla *tbTo,Carta* carta)
{
    if(tbTo->cartas->size() >=1)
    {
        Carta* last = tbTo->cartas->back();
        int tipLast = last->tip;
        if(last->col == carta->col)
            return false;
        if(!(carta->tip == tipLast+1))
            return false;
        return true;
    }
    else
    {
        if(carta->tip == KING)
            return true;
        return false;
    }
}
sf::RectangleShape* Game::crearLabel(int width,int height,int posX,int posY)
{
    sf::RectangleShape* label = new sf::RectangleShape(sf::Vector2f(width,height));
    label->setPosition(posX,posY);
    label->setOutlineThickness(2);
    label->setOutlineColor(sf::Color::Black);
    return label;
}
void Game::drawLabel(sf::RectangleShape* label)
{
    this->window.draw(*label);
}
void Game::createAllLabels(lista<TablaNormal*> tablas)
{
    int cont = 50;
    for(int i = 0; i < tablas.size(); i++)
    {
        TablaNormal* tabla = tablas.get(i);
        tabla->label = crearLabel(90,120,cont,250);
        cont+=150;
    }
    cont = 50;
    for(int i = 0; i < 4; i++)
    {
        labelsAs.push_back(crearLabel(90,120,cont,30));
        cont+=150;
    }
    
}
void Game::orderCards()
{
    for(int i = 0; i < tablas.size(); i++)
    {
        tablas.get(i)->ordenarCartasLabel();
    }
    this->mazo->ordenarCartasMostradas();
}
void Game::repartirCartas()
{
    for(int i = 0; i < tablas.size(); i++)
    {
        TablaNormal* tabla = tablas.get(i);
        for (int var = 0; var < tabla->cantMaxCartas; var++) {
            colocarCarta(tabla);
        }
        tabla->cartas->back()->show();
    }
    
}
void Game::drawAllLabels()
{
    for(int i = 0; i < tablas.size(); i++)
    {
        TablaNormal* tabla = tablas.get(i);
        drawLabel(tabla->label);
    }
    for(int i = 0; i < labelsAs.size(); i++)
    {
        sf::RectangleShape* shape = labelsAs.get(i);
        drawLabel(shape);
    }
}
void Game::drawAllCards()
{
    for(int i = 0; i < mazo->cartas->size(); i++)
    {
        Carta* carta = mazo->cartas->get(i);
        this->window.draw(*carta);
    }
    for(int i = 0; i < mazo->cartasMostradas->size(); i++)
    {
        Carta* carta = mazo->cartasMostradas->get(i);
        this->window.draw(*carta);
    }
    for(int i = 0; i < tablas.size(); i++)
    {
        TablaNormal* tabla = tablas.get(i);
        for(int m = 0; m < tabla->cartas->size(); m++)
        {
            Carta* carta = tabla->cartas->get(m);
            this->window.draw(*carta);
        }
    }

}
void Game::colocarCarta(TablaNormal *tab)
{
    if(!tab->isTablaLlena())
    {
        Carta *it = this->mazo->cartas->front();
        if(tab->cartas->size() == (tab->cantMaxCartas-1))
        {
            tab->cartas->push_front(it);
            this->mazo->cartas->pop_front();
            
        }
        else
        {
            tab->cartas->push_back(it);
            this->mazo->cartas->pop_front();
        }
        (*it).setPosition(tab->label->getPosition().x,tab->label->getPosition().y);

    }
}
void Game::addCarta(Tabla *tbAdd,Carta *cr)
{
    
    tbAdd->cartas->push_back(cr);
}
void Game::moverCarta(Tabla *tbFrom,Tabla *tbTo,Carta* carta)
{
    
    if(carta->isVisible)
    {

        addCarta(tbTo,carta);
        sacarCarta(tbFrom,carta);
    }
}
void Game::moverCartaMazo(Tabla *tbFrom,Tabla *tbTo,Carta* carta)
{
    if(carta->isVisible)
    {

        addCarta(tbTo,carta);
        this->mazo->cartasMostradas->remove(carta);
    }
}
void Game::sacarCarta(Tabla *tb,Carta *cr)
{

        
        tb->cartas->remove(cr);
}
Carta* Game::getCardClicked(sf::Vector2f vec)
{
    for(int i = 0; i < this->tablas.size(); i++)
    {
        TablaNormal* tabla = this->tablas.get(i);
        if(tabla->cartas->size() == 1)
        {
            if(tabla->cartas->front()->isClick(vec))
                return tabla->cartas->front();
        }
        for(int m = tabla->cartas->size() -1; m >= 0; m--)
        {
            Carta* carta = tabla->cartas->get(m);
            if(carta->isClick(vec) && carta->isVisible && carta == tabla->cartas->back())
            {
                return carta;
            }
            else if(carta->isClick(vec) && carta->isVisible)
                return carta; 
        }
        
    }
    if(mazo->cartasMostradas->size() >0)
    {

        for(int i = 0; i < mazo->cartasMostradas->size(); i++)
        {
            Carta* carta = mazo->cartasMostradas->get(i);
            if(carta->isClick(vec) && carta->isVisible)
            {
                return mazo->cartasMostradas->back();
            }
        }
        
    }
    return NULL;
}
Tabla* Game::getTableClicked(sf::Vector2f vec)
{
    for(int i = 0; i < this->tablas.size(); i++)
    {
        TablaNormal* tabla = this->tablas.get(i);
        sf::FloatRect table = tabla->label->getGlobalBounds();
        if(table.contains(vec))
            return tabla;
    }
    sf::FloatRect baraja = sf::FloatRect(800,30,90,100);
    if(baraja.contains(vec))
        return this->mazo;
    return NULL;
}
void Game::moverVarias(Tabla* tabla,Tabla* tbTo, Carta* carta)
{
    bool cont = false;
    for(int i = 0; i < tabla->cartas->size(); i++)
    {
        Carta* temp = tabla->cartas->get(i);
        if(temp == carta || cont)
        {
            moverCarta(tabla,tbTo,carta);
            cont = true;
        }
    }
}
void Game::gameLoop()
{
    
    Carta* clicked = NULL;
    Tabla* tbClicked = NULL;
    orderCards();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            sf::Vector2f mouseBounds;
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    mouseBounds = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (event.mouseButton.button == 0) {

                        clicked = getCardClicked(mouseBounds);
                        tbClicked = getTableClicked(mouseBounds);
                        //prueba
                        if(clicked!= NULL && tbClicked!= NULL)
                        {
                            moving = true;
                            oldPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                        }
                        else if( mazo->isMazoClicked(mouseBounds))
                        {
                            if(this->mazo->cartas->size() <= 0 && this->mazo->cartasMostradas->size() >= 1)
                            {
                                this->mazo->putShowCardsInMazo();
                            }
                            else
                            {

                                this->mazo->showCartaMazo();
                            }
                        }
                        
                        //fin prueba
                    }
                    break;
                case  sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == 0) {
                        Tabla* tb = getTableClicked(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                        moving = false;
                        if(tb != NULL)
                        {
                            if(tb != tbClicked && evaluarMovimiento(tb,clicked))
                            {
                                    if(tbClicked == mazo)
                                    {

                                        moverCartaMazo(tbClicked,tb,clicked);
                                    }
                                    else
                                    {

                                        moverCarta(tbClicked,tb,clicked);
                                    }
                            }
                        }
                        orderCards();
                        clicked = NULL;
                        tbClicked = NULL;
                    }
                    break;
                case sf::Event::MouseMoved:
                    if(!moving)
                        break;
                    const sf::Vector2f newPos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                    //TODO: ACA es donde me lanza un error
                    clicked->setPosition(newPos);
                    oldPos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                    break;
            }
        
        }
        
        window.clear(sf::Color::Green);
        drawAllLabels();
        drawAllCards();
        window.display();
    }
}
void Game::loadAllCards()
{
    //Numero 2
    cartas->push_back(new Carta(TREBOL,TWO,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/2_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,TWO,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/2_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,TWO,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/2_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,TWO,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/2_of_spades.png"));
    //Numero 3
    cartas->push_back(new Carta(TREBOL,THREE,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/3_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,THREE,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/3_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,THREE,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/3_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,THREE,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/3_of_spades.png"));
    //Numero 4
    cartas->push_back(new Carta(TREBOL,FOUR,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/4_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,FOUR,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/4_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,FOUR,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/4_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,FOUR,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/4_of_spades.png"));
    //Numero 5
    cartas->push_back(new Carta(TREBOL,FIVE,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/5_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,FIVE,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/5_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,FIVE,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/5_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,FIVE,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/5_of_spades.png"));
    //Numero 6
    cartas->push_back(new Carta(TREBOL,SIX,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/6_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,SIX,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/6_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,SIX,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/6_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,SIX,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/6_of_spades.png"));
    //NumERO7
    cartas->push_back(new Carta(TREBOL,SEVEN,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/7_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,SEVEN,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/7_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,SEVEN,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/7_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,SEVEN,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/7_of_spades.png"));
    //NumERO8
    cartas->push_back(new Carta(TREBOL,EIGHT,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/8_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,EIGHT,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/8_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,EIGHT,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/8_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,EIGHT,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/8_of_spades.png"));
    //NumERO9
    cartas->push_back(new Carta(TREBOL,NINE,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/9_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,NINE,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/9_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,NINE,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/9_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,NINE,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/9_of_spades.png"));
    //Nume->
    cartas->push_back(new Carta(TREBOL,TEN,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/10_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,TEN,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/10_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,TEN,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/10_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,TEN,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/10_of_spades.png"));
    //AS
    cartas->push_back(new Carta(TREBOL,AS,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/ace_of_clubs.png"));
    cartas->push_back(new Carta(DIAMANTE,AS,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/ace_of_diamonds.png"));
    cartas->push_back(new Carta(CORAZON,AS,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/ace_of_hearts.png"));
    cartas->push_back(new Carta(ESPADA,AS,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/ace_of_spades2.png"));
    //JACK
    cartas->push_back(new Carta(TREBOL,JACK,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/jack_of_clubs2.png"));
    cartas->push_back(new Carta(DIAMANTE,JACK,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/jack_of_diamonds2.png"));
    cartas->push_back(new Carta(CORAZON,JACK,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/jack_of_hearts2.png"));
    cartas->push_back(new Carta(ESPADA,JACK,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/jack_of_spades2.png"));
    //KING
    cartas->push_back(new Carta(TREBOL,KING,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/king_of_clubs2.png"));
    cartas->push_back(new Carta(DIAMANTE,KING,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/king_of_diamonds2.png"));
    cartas->push_back(new Carta(CORAZON,KING,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/king_of_hearts2.png"));
    cartas->push_back(new Carta(ESPADA,KING,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/king_of_spades2.png"));
    //QUEEN
    cartas->push_back(new Carta(TREBOL,QUEEN,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/queen_of_clubs2.png"));
    cartas->push_back(new Carta(DIAMANTE,QUEEN,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/queen_of_diamonds2.png"));
    cartas->push_back(new Carta(CORAZON,QUEEN,RED,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/queen_of_hearts2.png"));
    cartas->push_back(new Carta(ESPADA,QUEEN,BLACK,"/home/damasofc/QTProjects/Solitario_Proyecto/Imagenes/queen_of_spades2.png"));
}
