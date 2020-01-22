#include "../header/Cubo.hpp"

void drawTessera3D(sf::RenderWindow &window, float x, float y, float angolo, ColoreRGB colore, sf::Color bordo, float lato)
{
    //l'altezza del triangolo equilatero che forma "metà" tessera 3D
    float mezzoLato = lato / 2;
    float altezza = lato * sqrt(3) / 2;
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
    //setta un bordo di 1 all'interno del quadrato
    convex.setOutlineThickness(-1);
    //di colore del bordo
    convex.setOutlineColor(bordo);
    //orienta
    convex.setRotation(angolo);
    convex.setPosition(x, y);
    //disegna
    window.draw(convex);
}

//PUBLIC
Cubo::Cubo(void)
{
    //facce
    this->F = Faccia(ColoreRGB::Verde);
    this->R = Faccia(ColoreRGB::Rosso);
    this->U = Faccia(ColoreRGB::Viola);
    this->B = Faccia(ColoreRGB::Blu);
    this->L = Faccia(ColoreRGB::Arancio);
    this->D = Faccia(ColoreRGB::Giallo);
    //facce
    this->Reset();
}

Cubo::Cubo(ColoreRGB front, ColoreRGB right, ColoreRGB up, ColoreRGB back, ColoreRGB left, ColoreRGB down)
{
    //facce
    this->F = Faccia(front);
    this->R = Faccia(right);
    this->U = Faccia(up);
    this->B = Faccia(back);
    this->L = Faccia(left);
    this->D = Faccia(down);
    //facce
    this->Reset();
}

//resetta
void Cubo::Reset(void)
{
    this->F.Reset();
    this->R.Reset();
    this->U.Reset();
    this->B.Reset();
    this->L.Reset();
    this->D.Reset();
}
//ruota in senso Orario
void Cubo::Front(int senso)
{
    ColoreRGB *Up[DIM], *Right[DIM], *Down[DIM], *Left[DIM];
    this->U.getLatoSud(Up);
    this->R.getLatoOvest(Right);
    this->D.getLatoNord(Down);
    this->L.getLatoEst(Left);
    switch (senso)
    {
    case ORARIO:
        this->F.move();
        ruotaLatoOrario(Up, Right, Down, Left);
        break;
    case ANTIORARIO:
        this->F.move_anti();
        ruotaLatoAntiorario(Up, Right, Down, Left);
        break;
    default:
        break;
    }
}
void Cubo::Right(int senso)
{
    ColoreRGB *Up[DIM], *Front[DIM], *Down[DIM], *Back[DIM];
    this->U.getLatoEst(Up);
    this->B.getLatoOvest(Back);
    this->D.getLatoEst(Down);
    this->F.getLatoEst(Front);
    switch (senso)
    {
    case ORARIO:
        this->R.move();
        ruotaLatoOrario(Up, Back, Down, Front);
        break;
    case ANTIORARIO:
        this->R.move_anti();
        ruotaLatoAntiorario(Up, Back, Down, Front);
        break;
    default:
        break;
    }
}
void Cubo::Up(int senso)
{
    ColoreRGB *Back[DIM], *Right[DIM], *Front[DIM], *Left[DIM];
    this->B.getLatoNord(Back);
    this->R.getLatoNord(Right);
    this->F.getLatoNord(Front);
    this->L.getLatoNord(Left);
    switch (senso)
    {
    case ORARIO:
        this->U.move();
        ruotaLatoOrario(Back, Right, Front, Left);
        break;
    case ANTIORARIO:
        this->U.move_anti();
        ruotaLatoAntiorario(Back, Right, Front, Left);
        break;
    default:
        break;
    }
}
void Cubo::Back(int senso)
{
    ColoreRGB *Up[DIM], *Left[DIM], *Down[DIM], *Right[DIM];
    this->U.getLatoNord(Up);
    this->L.getLatoOvest(Left);
    this->D.getLatoSud(Down);
    this->R.getLatoEst(Right);
    switch (senso)
    {
    case ORARIO:
        this->B.move();
        ruotaLatoOrario(Up, Left, Down, Right);
        break;
    case ANTIORARIO:
        this->B.move_anti();
        ruotaLatoAntiorario(Up, Left, Down, Right);
        break;
    default:
        break;
    }
}
void Cubo::Left(int senso)
{
    ColoreRGB *Up[DIM], *Front[DIM], *Down[DIM], *Back[DIM];
    this->U.getLatoOvest(Up);
    this->F.getLatoOvest(Front);
    this->D.getLatoOvest(Down);
    this->B.getLatoEst(Back);
    switch (senso)
    {
    case ORARIO:
        this->L.move();
        ruotaLatoOrario(Up, Front, Down, Back);
        break;
    case ANTIORARIO:
        this->L.move_anti();
        ruotaLatoAntiorario(Up, Front, Down, Back);
        break;
    default:
        break;
    }
}
void Cubo::Down(int senso)
{
    ColoreRGB *Back[DIM], *Right[DIM], *Front[DIM], *Left[DIM];
    this->B.getLatoSud(Back);
    this->R.getLatoSud(Right);
    this->F.getLatoSud(Front);
    this->L.getLatoSud(Left);
    switch (senso)
    {
    case ORARIO:
        this->D.move();
        ruotaLatoOrario(Back, Right, Front, Left);
        break;
    case ANTIORARIO:
        this->D.move_anti();
        ruotaLatoAntiorario(Back, Right, Front, Left);
        break;
    default:
        break;
    }
}

//disegna
void Cubo::draw2D(sf::RenderWindow &window, float x, float y, float size)
{
    //lunghezza del lato
    float lato = size * DIM;
    this->F.drawN(window, x + 1 * lato, y + 1 * lato, size);
    this->R.drawN(window, x + 2 * lato, y + 1 * lato, size);
    this->U.drawN(window, x + 1 * lato, y + 0 * lato, size);
    this->B.drawN(window, x + 3 * lato, y + 1 * lato, size);
    this->L.drawN(window, x + 0 * lato, y + 1 * lato, size);
    this->D.drawN(window, x + 1 * lato, y + 2 * lato, size);
}
void Cubo::draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size)
{
    sf::Color sfondo = sf::Color::White;
    float altezza = size * sqrt(3) / 2;
    //FRONT
    drawTessera3D(window, x - altezza * 2, y - size, FRONT, *F.getNW(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, FRONT, *F.getNord(), sfondo, size);
    drawTessera3D(window, x, y, FRONT, *F.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, FRONT, *F.getOvest(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, FRONT, *F.getCentro(), sfondo, size);
    drawTessera3D(window, x, y + size, FRONT, *F.getEst(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, FRONT, *F.getSE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, FRONT, *F.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, FRONT, *F.getSW(), sfondo, size);
    //RIGHT
    drawTessera3D(window, x, y, RIGHT, *R.getNW(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, RIGHT, *R.getNord(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, RIGHT, *R.getNE(), sfondo, size);
    drawTessera3D(window, x, y + size, RIGHT, *R.getOvest(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, RIGHT, *R.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, RIGHT, *R.getEst(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, RIGHT, *R.getSW(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, RIGHT, *R.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, RIGHT, *R.getSE(), sfondo, size);
    //UP
    drawTessera3D(window, x, y - size * 2, UP, *U.getNW(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, UP, *U.getNord(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, UP, *U.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, UP, *U.getOvest(), sfondo, size);
    drawTessera3D(window, x, y - size, UP, *U.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, UP, *U.getEst(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, UP, *U.getSW(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, UP, *U.getSud(), sfondo, size);
    drawTessera3D(window, x, y, UP, *U.getSE(), sfondo, size);
}

void Cubo::draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size)
{
    sf::Color sfondo = sf::Color::Cyan;
    //visuale ottenuta "tagliando il cubo" come fosse una camera su thesims
    sf::CircleShape exagon(size * 3, 6);
    exagon.setPosition({x - size * 3, y - size * 3});
    exagon.setFillColor(sf::Color::Magenta);
    window.draw(exagon);
    //cutted
    float altezza = size * sqrt(3) / 2;
    //BACK -> destra
    drawTessera3D(window, x, y, DESTRA, *B.getSE(), sfondo, size);
    drawTessera3D(window, x, y - size, DESTRA, *B.getEst(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, DESTRA, *B.getNE(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, DESTRA, *B.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, DESTRA, *B.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, DESTRA, *B.getNord(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, DESTRA, *B.getSW(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, DESTRA, *B.getOvest(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, DESTRA, *B.getNW(), sfondo, size);
    //LEFT -> sinistra
    drawTessera3D(window, x - altezza * 2, y + size, SINISTRA, *L.getSE(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, SINISTRA, *L.getEst(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, SINISTRA, *L.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, SINISTRA, *L.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, SINISTRA, *L.getCentro(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, SINISTRA, *L.getNord(), sfondo, size);
    drawTessera3D(window, x, y, SINISTRA, *L.getSW(), sfondo, size);
    drawTessera3D(window, x, y - size, SINISTRA, *L.getOvest(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, SINISTRA, *L.getNW(), sfondo, size);
    //DOWN
    drawTessera3D(window, x - altezza * 2, y + size, SOTTO, *D.getNW(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, SOTTO, *D.getNord(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, SOTTO, *D.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, SOTTO, *D.getOvest(), sfondo, size);
    drawTessera3D(window, x, y + size, SOTTO, *D.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, SOTTO, *D.getEst(), sfondo, size);
    drawTessera3D(window, x, y, SOTTO, *D.getSW(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, SOTTO, *D.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, SOTTO, *D.getSE(), sfondo, size);
}

void Cubo::draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size)
{
    sf::Color sfondo = sf::Color::White;
    //visuale ottenuta ruotando il cubo
    float altezza = size * sqrt(3) / 2;
    //BACK
    drawTessera3D(window, x, y, BACK, *B.getSE(), sfondo, size);
    drawTessera3D(window, x, y - size, BACK, *B.getEst(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, BACK, *B.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, BACK, *B.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, BACK, *B.getCentro(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, BACK, *B.getNord(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, BACK, *B.getSW(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, BACK, *B.getOvest(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, BACK, *B.getNW(), sfondo, size);
    //LEFT
    drawTessera3D(window, x + altezza * 2, y + size, LEFT, *L.getSE(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, LEFT, *L.getEst(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, LEFT, *L.getNE(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, LEFT, *L.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, LEFT, *L.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, LEFT, *L.getNord(), sfondo, size);
    drawTessera3D(window, x, y, LEFT, *L.getSW(), sfondo, size);
    drawTessera3D(window, x, y - size, LEFT, *L.getOvest(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, LEFT, *L.getNW(), sfondo, size);
    //DOWN
    drawTessera3D(window, x + altezza * 2, y + size, DOWN, *D.getNW(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, DOWN, *D.getNord(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, DOWN, *D.getNE(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, DOWN, *D.getOvest(), sfondo, size);
    drawTessera3D(window, x, y + size, DOWN, *D.getCentro(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, DOWN, *D.getEst(), sfondo, size);
    drawTessera3D(window, x, y, DOWN, *D.getSW(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, DOWN, *D.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, DOWN, *D.getSE(), sfondo, size);
}

void Cubo::draw(sf::RenderWindow &window, float x, float y, float lato)
{
    float dist = 10.f, size = lato / 3;
    this->draw2D(window, WIDTH / 2 - dist * 3, HEIGHT / 3 - dist * 2, size * 2 / 3);
    this->draw_3D_FRU(window, x + lato * 3 / 2, y + dist + lato, size);
    this->draw_3D_BLD_rotated(window, x + WIDTH * 5 / 6, y + HEIGHT * 4 / 5, size / 2);
    this->draw_3D_BLD_cutted(window, x + lato, y + lato * 3 - dist, size);
}