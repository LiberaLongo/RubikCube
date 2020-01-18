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
{ //TO DO
}
Faccia::Faccia(ColoreRGB colore, char name, Faccia &nord, Faccia &est, Faccia &sud, Faccia &ovest)
{ //TO DO
}

//resetta la faccia del suo colore
void Faccia::Reset(void)
{ //TO DO
}
//muovi lei e le vicine
void Faccia::move(void)
{
/*
    //vertici o angoli
    ruotaOrario(faccia[0][0], faccia[2][0], faccia[2][2], faccia[0][2]);
    //spigoli o lati
    ruotaOrario(faccia[1][0], faccia[2][1], faccia[1][2], faccia[0][1]);
*/
}
void Faccia::move_anti(void)
{ //TO DO
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