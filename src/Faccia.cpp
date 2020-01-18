#include "../header/Faccia.hpp"

void Faccia::ruotaOrario(ColoreRGB &n, ColoreRGB &e, ColoreRGB &s, ColoreRGB &w)
{
    ColoreRGB temp = n;
    n = w;
    w = s;
    s = e;
    e = temp;
}
void Faccia::ruota_anti(ColoreRGB &n, ColoreRGB &e, ColoreRGB &s, ColoreRGB &w)
{
    ColoreRGB temp = n;
    n = e;
    e = s;
    s = w;
    w = temp;
}

//costruttore
Faccia::Faccia(void)
{
    //costruttore vuoto
}
Faccia::Faccia(ColoreRGB colore, char name, Faccia &nord, Faccia &est, Faccia &sud, Faccia &ovest)
{
    this->name = name;
    //puntatori alle altre facce
    this->faceNord = &nord;
    this->faceSud = &est;
    this->faceEst = &sud;
    this->faceOvest = &ovest;
    //coloro la tessera centrale
    this->colore = colore;
    //coloro le tessere
    this->Reset();
}

//resetta la faccia del suo colore
void Faccia::Reset(void)
{
    //colori delle tessere
    /* [NW][N ][NE]
    *  [w ][ C][E ]
    *  [SW][S ][SE] */
    this->t_Nord = this->colore;     //su ^
    this->t_Est = this->colore;      //destra -->
    this->t_Sud = this->colore;      //giù v
    this->t_West = this->colore;     //sinistra <--, ovest, orange, arancio
    this->t_NE = this->colore;       //nord est
    this->t_NW = this->colore;       //nord ovest
    this->t_SE = this->colore;       //sud est
    this->t_SW = this->colore;       //sud ovest
}
//muovi lei e le vicine
void Faccia::move(void)
{
    //ruota in senso orario i miei vertici
    ruotaOrario(t_Nord, t_Est, t_Sud, t_West);
    //ruota in senso orario i miei spigoli
    ruotaOrario(t_NW, t_NE, t_SE, t_SW);
    //ruota in senso orario i vertici e gli spigoli delle facce
}
void Faccia::move_anti(void)
{
    //ruota in senso antiorario i miei vertici
    ruota_anti(t_Nord, t_Est, t_Sud, t_West);
    //ruota in senso antiorario i miei spigoli
    ruota_anti(t_NW, t_NE, t_SE, t_SW);
    //ruota in senso antiorario i vertici e gli spigoli delle facce
}

//disegna 2D con il Nord rivolto verso... NSWO
void Faccia::drawN(sf::RenderWindow &window, float x, float y, float lato)
{ //TO DO
}
void Faccia::drawS(sf::RenderWindow &window, float x, float y, float lato)
{ //TO DO
}
void Faccia::drawW(sf::RenderWindow &window, float x, float y, float lato)
{ //TO DO
}
void Faccia::drawO(sf::RenderWindow &window, float x, float y, float lato)
{ //TO DO
}

//get colori tessere, (in caso il chiamante voglia fare il disegno 3D)
ColoreRGB Faccia::getCentro(void)
{ //TO DO
}
ColoreRGB Faccia::getNord(void)
{ //TO DO
}
ColoreRGB Faccia::getEst(void)
{ //TO DO
}
ColoreRGB Faccia::getSud(void)
{ //TO DO
}
ColoreRGB Faccia::getOvest(void)
{ //TO DO
}
ColoreRGB Faccia::getNE(void)
{ //TO DO
}
ColoreRGB Faccia::getNW(void)
{ //TO DO
}
ColoreRGB Faccia::getSE(void)
{ //TO DO
}
ColoreRGB Faccia::getSW(void)
{ //TO DO
}

//PROTECTED?
//vorrei che solo altre facce potessero modificarmi facendo la move
//possibile?
void setNord(ColoreRGB colore)
{ //TO DO
}
void setEst(ColoreRGB colore)
{ //TO DO
}
void setSud(ColoreRGB colore)
{ //TO DO
}
void setOvest(ColoreRGB colore)
{ //TO DO
}
void setNE(ColoreRGB colore)
{ //TO DO
}
void setNW(ColoreRGB colore)
{ //TO DO
}
void setSE(ColoreRGB colore)
{ //TO DO
}
void setSW(ColoreRGB colore)
{ //TO DO
}