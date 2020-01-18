#include "./CuboMatricale.hpp"

//PRIVATE
//funzioni ausiliarie

//che crea una faccia di un colore
void Cubo::creaFaccia(ColoreRGB faccia[DIM][DIM], ColoreRGB colore)
{
    //per ogni cella inserisci il colore
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            faccia[i][j] = colore;
}
//che ruotano 4 colori tra loro
void Cubo::ruotaOrario(ColoreRGB &t, ColoreRGB &x, ColoreRGB &y, ColoreRGB &z)
{
    /*[t][x] --> [z][t]
      [z][y]     [y][x]*/
    ColoreRGB temp = t;
    t = z;
    z = y;
    y = x;
    x = temp;
}
void Cubo::ruota_anti(ColoreRGB &t, ColoreRGB &x, ColoreRGB &y, ColoreRGB &z)
{
    /*[t][x] --> [x][y]
      [z][y]     [t][z]*/
    ColoreRGB temp = t;
    t = x;
    x = y;
    y = z;
    z = temp;
}
//che ruota una intera faccia (senza modificare le facce vicine)
void Cubo::facciaOrario(ColoreRGB faccia[DIM][DIM])
{
    //vertici o angoli
    ruotaOrario(faccia[0][0], faccia[2][0], faccia[2][2], faccia[0][2]);
    //spigoli o lati
    ruotaOrario(faccia[1][0], faccia[2][1], faccia[1][2], faccia[0][1]);
}
void Cubo::faccia_anti(ColoreRGB faccia[DIM][DIM])
{
    //vertici o angoli
    ruota_anti(faccia[0][0], faccia[2][0], faccia[2][2], faccia[0][2]);
    //spigoli o lati
    ruota_anti(faccia[1][0], faccia[2][1], faccia[1][2], faccia[0][1]);
}
//disegna
void Cubo::drawFaccia(sf::RenderWindow &window, ColoreRGB faccia[DIM][DIM], float x, float y, float size)
{
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
        {
            //coordinate
            float xi = x + i * size;
            float yj = y + j * size;
            //quadrato
            sf::RectangleShape tessera(sf::Vector2f(size, size));
            //posizione
            tessera.setPosition(xi, yj);
            //colore
            tessera.setFillColor(faccia[i][j].getColorLib());
            //setta un bordo di 1 all'interno del quadrato
            tessera.setOutlineThickness(-1);
            //disegno
            window.draw(tessera);
        }
}

void Cubo::drawTessera3D(sf::RenderWindow &window, float x, float y, float angolo, ColoreRGB colore, float lato)
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
    this->Reset();
}
//resetta
void Cubo::Reset(void)
{
    //colori delle facce
    ColoreRGB rosso = ColoreRGB(LUMUS_MAXIMA, 0, 0);
    ColoreRGB blu = ColoreRGB(0, 0, LUMUS_MAXIMA);
    ColoreRGB viola = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);
    ColoreRGB arancio = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA / 2, 0);
    ColoreRGB verde = ColoreRGB(0, LUMUS_MAXIMA, 0);
    ColoreRGB giallo = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
    //inizializza le facce
    creaFaccia(this->F, rosso);
    creaFaccia(this->R, blu);
    creaFaccia(this->U, viola);
    creaFaccia(this->B, arancio);
    creaFaccia(this->L, verde);
    creaFaccia(this->D, giallo);
}
//ruota in senso Orario
void Cubo::Front(void)
{
    facciaOrario(this->F);
    ruotaOrario(this->U[0][2], this->R[0][2], this->D[0][2], this->L[0][2]);
    ruotaOrario(this->U[1][2], this->R[1][2], this->D[1][2], this->L[1][2]);
    ruotaOrario(this->U[2][2], this->R[2][2], this->D[2][2], this->L[2][2]);
}
void Cubo::Right(void)
{
    facciaOrario(this->R);
    ruotaOrario(this->U[2][0], this->B[2][0], this->D[0][2], this->F[2][0]);
    ruotaOrario(this->U[2][1], this->B[2][1], this->D[0][1], this->F[2][1]);
    ruotaOrario(this->U[2][2], this->B[2][2], this->D[0][0], this->F[2][2]);
}
void Cubo::Up(void)
{
    facciaOrario(this->U);
    ruotaOrario(this->F[0][0], this->L[2][0], this->B[2][2], this->R[0][2]);
    ruotaOrario(this->F[1][0], this->L[2][1], this->B[1][2], this->R[0][1]);
    ruotaOrario(this->F[2][0], this->L[2][2], this->B[0][2], this->R[0][0]);
}
void Cubo::Back(void)
{
    facciaOrario(this->B);
    ruotaOrario(this->U[0][0], this->L[0][0], this->D[0][0], this->R[0][0]);
    ruotaOrario(this->U[1][0], this->L[1][0], this->D[1][0], this->R[1][0]);
    ruotaOrario(this->U[2][0], this->L[2][0], this->D[2][0], this->R[2][0]);
}
void Cubo::Left(void)
{
    facciaOrario(this->L);
    ruotaOrario(this->U[0][0], this->F[0][0], this->D[2][2], this->B[0][0]);
    ruotaOrario(this->U[0][1], this->F[0][1], this->D[2][1], this->B[0][1]);
    ruotaOrario(this->U[0][2], this->F[0][2], this->D[2][0], this->B[0][2]);
}
void Cubo::Down(void)
{
    facciaOrario(this->D);
    ruotaOrario(this->F[0][2], this->R[2][2], this->B[2][0], this->L[0][0]);
    ruotaOrario(this->F[1][2], this->R[2][1], this->B[1][0], this->L[0][1]);
    ruotaOrario(this->F[2][2], this->R[2][0], this->B[0][0], this->L[0][2]);
}
//ruota in senso antiorario
void Cubo::Front_anti(void)
{
    faccia_anti(this->F);
    ruota_anti(this->U[0][2], this->R[0][2], this->D[0][2], this->L[0][2]);
    ruota_anti(this->U[1][2], this->R[1][2], this->D[1][2], this->L[1][2]);
    ruota_anti(this->U[2][2], this->R[2][2], this->D[2][2], this->L[2][2]);
}
void Cubo::Right_anti(void)
{
    faccia_anti(this->R);
    ruota_anti(this->U[2][0], this->B[2][0], this->D[0][2], this->F[2][0]);
    ruota_anti(this->U[2][1], this->B[2][1], this->D[0][1], this->F[2][1]);
    ruota_anti(this->U[2][2], this->B[2][2], this->D[0][0], this->F[2][2]);
}
void Cubo::Up_anti(void)
{
    faccia_anti(this->U);
    ruota_anti(this->F[0][0], this->L[2][0], this->B[2][2], this->R[0][2]);
    ruota_anti(this->F[1][0], this->L[2][1], this->B[1][2], this->R[0][1]);
    ruota_anti(this->F[2][0], this->L[2][2], this->B[0][2], this->R[0][0]);
}
void Cubo::Back_anti(void)
{
    faccia_anti(this->B);
    ruota_anti(this->U[0][0], this->L[0][0], this->D[0][0], this->R[0][0]);
    ruota_anti(this->U[1][0], this->L[1][0], this->D[1][0], this->R[1][0]);
    ruota_anti(this->U[2][0], this->L[2][0], this->D[2][0], this->R[2][0]);
}
void Cubo::Left_anti(void)
{
    faccia_anti(this->L);
    ruota_anti(this->U[0][0], this->F[0][0], this->D[2][2], this->B[0][0]);
    ruota_anti(this->U[0][1], this->F[0][1], this->D[2][1], this->B[0][1]);
    ruota_anti(this->U[0][2], this->F[0][2], this->D[2][0], this->B[0][2]);
}
void Cubo::Down_anti(void)
{
    faccia_anti(this->D);
    ruota_anti(this->F[0][2], this->R[2][2], this->B[2][0], this->L[0][0]);
    ruota_anti(this->F[1][2], this->R[2][1], this->B[1][0], this->L[0][1]);
    ruota_anti(this->F[2][2], this->R[2][0], this->B[0][0], this->L[0][2]);
}
//disegna
void Cubo::draw2D(sf::RenderWindow &window, float x, float y, float size)
{
    //lunghezza del lato
    float lato = size * DIM;
    drawFaccia(window, this->F, x + 1 * lato, y + 2 * lato, size);
    drawFaccia(window, this->R, x + 2 * lato, y + 1 * lato, size);
    drawFaccia(window, this->U, x + 1 * lato, y + 1 * lato, size);
    drawFaccia(window, this->B, x + 1 * lato, y + 0 * lato, size);
    drawFaccia(window, this->L, x + 0 * lato, y + 1 * lato, size);
    drawFaccia(window, this->D, x + 3 * lato, y + 1 * lato, size);
}
void Cubo::draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size)
{
    float altezza = size * sqrt(3) / 2;
    //FRONT
    drawTessera3D(window, x - altezza * 2, y - size, FRONT, F[0][0], size);
    drawTessera3D(window, x - altezza * 2, y, FRONT, F[0][1], size);
    drawTessera3D(window, x - altezza * 2, y + size, FRONT, F[0][2], size);
    drawTessera3D(window, x - altezza, y - size / 2, FRONT, F[1][0], size);
    drawTessera3D(window, x - altezza, y + size / 2, FRONT, F[1][1], size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, FRONT, F[1][2], size);
    drawTessera3D(window, x, y, FRONT, F[2][0], size);
    drawTessera3D(window, x, y + size, FRONT, F[2][1], size);
    drawTessera3D(window, x, y + size * 2, FRONT, F[2][2], size);
    //RIGHT
    drawTessera3D(window, x + altezza * 2, y - size, RIGHT, R[0][0], size);
    drawTessera3D(window, x + altezza, y - size / 2, RIGHT, R[0][1], size);
    drawTessera3D(window, x, y, RIGHT, R[0][2], size);
    drawTessera3D(window, x + altezza * 2, y, RIGHT, R[1][0], size);
    drawTessera3D(window, x + altezza, y + size / 2, RIGHT, R[1][1], size);
    drawTessera3D(window, x, y + size, RIGHT, R[1][2], size);
    drawTessera3D(window, x + altezza * 2, y + size, RIGHT, R[2][0], size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, RIGHT, R[2][1], size);
    drawTessera3D(window, x, y + size * 2, RIGHT, R[2][2], size);
    //UP
    drawTessera3D(window, x, y - size * 2, UP, U[0][0], size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, UP, U[0][1], size);
    drawTessera3D(window, x - altezza * 2, y - size, UP, U[0][2], size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, UP, U[1][0], size);
    drawTessera3D(window, x, y - size, UP, U[1][1], size);
    drawTessera3D(window, x - altezza, y - size / 2, UP, U[1][2], size);
    drawTessera3D(window, x + altezza * 2, y - size, UP, U[2][0], size);
    drawTessera3D(window, x + altezza, y - size / 2, UP, U[2][1], size);
    drawTessera3D(window, x, y, UP, U[2][2], size);
}

void Cubo::draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size)
{
    //visuale ottenuta "tagliando il cubo" come fosse una camera su thesims
    sf::CircleShape exagon(size * 3, 6);
    exagon.setPosition({x - size * 3, y - size * 3});
    exagon.setFillColor(sf::Color::Magenta);
    window.draw(exagon);
    //cutted
    float altezza = size * sqrt(3) / 2;
    //BACK -> destra
    drawTessera3D(window, x, y, DESTRA, B[0][0], size);
    drawTessera3D(window, x, y - size, DESTRA, B[0][1], size);
    drawTessera3D(window, x, y - size * 2, DESTRA, B[0][2], size);
    drawTessera3D(window, x + altezza, y + size / 2, DESTRA, B[1][0], size);
    drawTessera3D(window, x + altezza, y - size / 2, DESTRA, B[1][1], size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, DESTRA, B[1][2], size);
    drawTessera3D(window, x + altezza * 2, y + size, DESTRA, B[2][0], size);
    drawTessera3D(window, x + altezza * 2, y, DESTRA, B[2][1], size);
    drawTessera3D(window, x + altezza * 2, y - size, DESTRA, B[2][2], size);
    //LEFT -> sinistra
    drawTessera3D(window, x, y, SINISTRA, L[0][0], size);
    drawTessera3D(window, x - altezza, y + size / 2, SINISTRA, L[0][1], size);
    drawTessera3D(window, x - altezza * 2, y + size, SINISTRA, L[0][2], size);
    drawTessera3D(window, x, y - size, SINISTRA, L[1][0], size);
    drawTessera3D(window, x - altezza, y - size / 2, SINISTRA, L[1][1], size);
    drawTessera3D(window, x - altezza * 2, y, SINISTRA, L[1][2], size);
    drawTessera3D(window, x, y - size * 2, SINISTRA, L[2][0], size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, SINISTRA, L[2][1], size);
    drawTessera3D(window, x - altezza * 2, y - size, SINISTRA, L[2][2], size);
    //DOWN
    drawTessera3D(window, x + altezza * 2, y + size, SOTTO, D[0][0], size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, SOTTO, D[0][1], size);
    drawTessera3D(window, x, y + size * 2, SOTTO, D[0][2], size);
    drawTessera3D(window, x + altezza, y + size / 2, SOTTO, D[1][0], size);
    drawTessera3D(window, x, y + size, SOTTO, D[1][1], size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, SOTTO, D[1][2], size);
    drawTessera3D(window, x, y, SOTTO, D[2][0], size);
    drawTessera3D(window, x - altezza, y + size / 2, SOTTO, D[2][1], size);
    drawTessera3D(window, x - altezza * 2, y + size, SOTTO, D[2][2], size);
}

void Cubo::draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size)
{
    //visuale ottenuta ruotando il cubo
    float altezza = size * sqrt(3) / 2;
    //BACK
    drawTessera3D(window, x, y, BACK, B[0][0], size);
    drawTessera3D(window, x, y - size, BACK, B[0][1], size);
    drawTessera3D(window, x, y - size * 2, BACK, B[0][2], size);
    drawTessera3D(window, x - altezza, y + size / 2, BACK, B[1][0], size);
    drawTessera3D(window, x - altezza, y - size / 2, BACK, B[1][1], size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, BACK, B[1][2], size);
    drawTessera3D(window, x - altezza * 2, y + size, BACK, B[2][0], size);
    drawTessera3D(window, x - altezza * 2, y, BACK, B[2][1], size);
    drawTessera3D(window, x - altezza * 2, y - size, BACK, B[2][2], size);
    //LEFT
    drawTessera3D(window, x, y, LEFT, L[0][0], size);
    drawTessera3D(window, x + altezza, y + size / 2, LEFT, L[0][1], size);
    drawTessera3D(window, x + altezza * 2, y + size, LEFT, L[0][2], size);
    drawTessera3D(window, x, y - size, LEFT, L[1][0], size);
    drawTessera3D(window, x + altezza, y - size / 2, LEFT, L[1][1], size);
    drawTessera3D(window, x + altezza * 2, y, LEFT, L[1][2], size);
    drawTessera3D(window, x, y - size * 2, LEFT, L[2][0], size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, LEFT, L[2][1], size);
    drawTessera3D(window, x + altezza * 2, y - size, LEFT, L[2][2], size);
    //DOWN
    drawTessera3D(window, x - altezza * 2, y + size, DOWN, D[0][0], size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, DOWN, D[0][1], size);
    drawTessera3D(window, x, y + size * 2, DOWN, D[0][2], size);
    drawTessera3D(window, x - altezza, y + size / 2, DOWN, D[1][0], size);
    drawTessera3D(window, x, y + size, DOWN, D[1][1], size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, DOWN, D[1][2], size);
    drawTessera3D(window, x, y, DOWN, D[2][0], size);
    drawTessera3D(window, x + altezza, y + size / 2, DOWN, D[2][1], size);
    drawTessera3D(window, x + altezza * 2, y + size, DOWN, D[2][2], size);
}

void Cubo::draw(sf::RenderWindow &window, float x, float y, float lato)
{
    float dist = 10.f, size = lato / 3;
    this->draw2D(window, WIDTH / 2 - dist*3, HEIGHT /3 - dist*2, size * 2 / 3);
    this->draw_3D_FRU(window, x + lato * 3 / 2, y + dist + lato, size);
    this->draw_3D_BLD_rotated(window, x + WIDTH * 5/6, y + HEIGHT*4/5 , size / 2);
    this->draw_3D_BLD_cutted(window, x + lato , y + lato * 3 - dist, size);
}
