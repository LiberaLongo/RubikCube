#include "../header/Cubo.hpp"

void drawTessera3D(sf::RenderWindow &window, float x, float y, float angolo, ColoreRGB colore, float lato)
{
    //l'altezza del triangolo equilatero che forma "metà" tessera 3D
    float mezzoLato = lato / 2;
    float altezza = lato * sqrt(3) / 2;
    //non ho capito pk devo traslare...
    //x = x + altezza;
    // create an empty shape
    sf::ConvexShape convex;
    // resize it to 5 points
    convex.setPointCount(4);
    // define the points
    convex.setPoint(0, sf::Vector2f(0.f, -lato));
    convex.setPoint(1, sf::Vector2f(+altezza, -mezzoLato));
    convex.setPoint(2, sf::Vector2f(0.f, 0.f));
    convex.setPoint(3, sf::Vector2f(-altezza, -mezzoLato));

    //colore
    convex.setFillColor(colore.getColorLib());
    //orienta
    convex.setRotation(angolo);
    convex.setPosition(x, y);
    //setta un bordo di 1 all'interno del quadrato
    convex.setOutlineThickness(-1);
    //disegna
    window.draw(convex);
}

//PUBLIC
Cubo::Cubo(void)
{
    //facce
    Faccia F = Faccia(ColoreRGB::Verde, 'F', U, R, D, L);
    Faccia R = Faccia(ColoreRGB::Rosso, 'R', U, B, D, F);
    Faccia U = Faccia(ColoreRGB::Viola, 'U', B, R, F, L);
    Faccia B = Faccia(ColoreRGB::Blu, 'B', U, L, D, R);
    Faccia L = Faccia(ColoreRGB::Arancio, 'L', U, F, D, B);
    Faccia D = Faccia(ColoreRGB::Giallo, 'D', F, R, B, L);
    this->Reset();
}
//resetta
void Cubo::Reset(void)
{
    //FRUBLD
}
//ruota in senso Orario
void Cubo::Front(void)
{
    //FRUBLD
}
void Cubo::Right(void)
{
    //FRUBLD
}
void Cubo::Up(void)
{
    //FRUBLD
}
void Cubo::Back(void)
{
    //FRUBLD
}
void Cubo::Left(void)
{
    //FRUBLD
}
void Cubo::Down(void)
{
    //FRUBLD
}
//ruota in senso antiorario
void Cubo::Front_anti(void)
{
    //FRUBLD
}
void Cubo::Right_anti(void)
{
    //FRUBLD
}
void Cubo::Up_anti(void)
{
    //FRUBLD
}
void Cubo::Back_anti(void)
{
    //FRUBLD
}
void Cubo::Left_anti(void)
{
    //FRUBLD
}
void Cubo::Down_anti(void)
{
    //FRUBLD
}
//disegna
void Cubo::draw2D(sf::RenderWindow &window, float x, float y, float size)
{
    //FRUBLD
}
void Cubo::draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size)
{
    //FRUBLD
}

void Cubo::draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size)
{
    //FRUBLD
}

void Cubo::draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size)
{
    //FRUBLD
}

void Cubo::draw(sf::RenderWindow &window, float x, float y, float lato)
{
    float dist = 10.f, size = lato / 3;
    this->draw2D(window, WIDTH / 2 - dist * 3, HEIGHT / 3 - dist * 2, size * 2 / 3);
    this->draw_3D_FRU(window, x + lato * 3 / 2, y + dist + lato, size);
    this->draw_3D_BLD_rotated(window, x + WIDTH * 5 / 6, y + HEIGHT * 4 / 5, size / 2);
    this->draw_3D_BLD_cutted(window, x + lato, y + lato * 3 - dist, size);
}