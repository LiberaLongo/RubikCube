#include "../header/Cubo.hpp"

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
void Cubo::drawFaccia(sf::RenderWindow &window, ColoreRGB faccia[DIM][DIM], float x, float y)
{
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
        {
            //coordinate
            float xi = x + i * this->size;
            float yj = y + j * this->size;
            //quadrato
            sf::RectangleShape tessera(sf::Vector2f(this->size, this->size));
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

//PUBLIC
Cubo::Cubo(void)
{
    //dimensione del cubo
    this->size = min(WIDTH / 12, HEIGHT / 9);
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
    //TO DO
}
void Cubo::Right(void)
{
    facciaOrario(this->R);
    //TO DO
}
void Cubo::Up(void)
{
    facciaOrario(this->U);
    //TO DO
}
void Cubo::Back(void)
{
    facciaOrario(this->B);
    //TO DO
}
void Cubo::Left(void)
{
    facciaOrario(this->L);
    //TO DO
}
void Cubo::Down(void)
{
    facciaOrario(this->D);
    //TO DO
}
//ruota in senso antiorario
void Cubo::Front_anti(void)
{
    faccia_anti(this->F);
    //TO DO
}
void Cubo::Right_anti(void)
{
    faccia_anti(this->R);
    //TO DO
}
void Cubo::Up_anti(void)
{
    faccia_anti(this->U);
    //TO DO
}
void Cubo::Back_anti(void)
{
    faccia_anti(this->B);
    //TO DO
}
void Cubo::Left_anti(void)
{
    faccia_anti(this->L);
    //TO DO
}
void Cubo::Down_anti(void)
{
    faccia_anti(this->D);
    //TO DO
}
//disegna
void Cubo::draw2D(sf::RenderWindow &window)
{
    //coordinate
    float x = 0.f;
    float y = 0.f;
    //lunghezza del lato
    float lato = this->size * DIM;
    drawFaccia(window, this->F, x + 1 * lato, y + 2 * lato);
    drawFaccia(window, this->R, x + 2 * lato, y + 1 * lato);
    drawFaccia(window, this->U, x + 3 * lato, y + 1 * lato);
    drawFaccia(window, this->B, x + 1 * lato, y + 0 * lato);
    drawFaccia(window, this->L, x + 0 * lato, y + 1 * lato);
    drawFaccia(window, this->D, x + 1 * lato, y + 1 * lato);
}
void Cubo::draw3D(sf::RenderWindow &window)
{
    //TO DO
}