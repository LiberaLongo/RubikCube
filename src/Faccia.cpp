#include "../header/Faccia.hpp"

void ruotaOrario(ColoreRGB &n, ColoreRGB &e, ColoreRGB &s, ColoreRGB &w)
{
    ColoreRGB temp = n;
    n = w;
    w = s;
    s = e;
    e = temp;
}
void ruota_anti(ColoreRGB &n, ColoreRGB &e, ColoreRGB &s, ColoreRGB &w)
{
    ColoreRGB temp = n;
    n = e;
    e = s;
    s = w;
    w = temp;
}
void drawTessera2D(sf::RenderWindow &window, ColoreRGB colore, float x, float y, float size)
{
    //quadrato
    sf::RectangleShape tessera(sf::Vector2f(size, size));
    //posizione
    tessera.setPosition(x, y);
    //colore
    tessera.setFillColor(colore.getColorLib());
    //setta un bordo di 1 all'interno del quadrato
    tessera.setOutlineThickness(-1);
    //disegno
    window.draw(tessera);
}

//costruttore
Faccia::Faccia(void)
{
    //costruttore vuoto
}
Faccia::Faccia(ColoreRGB colore, char name, Faccia &nord, Faccia &est, Faccia &sud, Faccia &ovest)
{
    if (name == 'F' || name == 'R' || name == 'U' || name == 'B' || name == 'L' || name == 'D')
        this->name = name;
    else
        cout << "Errore nel nome della faccia " << name << endl;
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
    /* [NW][N ][NE]     [00][01][02]
    *  [w ][ C][E ] --> [10][11][12]
    *  [SW][S ][SE]     [20][21][22]*/
    //per ogni cella inserisci il colore
    for (int i = 0; i < DIM; i++)     //riga i
        for (int j = 0; j < DIM; j++) //colonna j
            tessere[i][j] = this->colore;
}
//muovi lei e le vicine
void Faccia::move(void)
{
    //ruota in senso orario i miei vertici (Nord, Est, Sud, Ovest)
    ruotaOrario(tessere[0][1], tessere[1][2], tessere[2][1], tessere[1][0]);
    //ruota in senso orario i miei spigoli(NW, NE, SE, SW)
    ruotaOrario(tessere[0][0], tessere[0][2], tessere[2][2], tessere[2][0]);
    //ruota in senso orario i vertici e gli spigoli delle facce adiacenti
}
void Faccia::move_anti(void)
{
    //ruota in senso antiorario i miei vertici (Nord, Est, Sud, Ovest)
    ruota_anti(tessere[0][1], tessere[1][2], tessere[2][1], tessere[1][0]);
    //ruota in senso antiorario i miei spigoli
    ruota_anti(tessere[0][0], tessere[0][2], tessere[2][2], tessere[2][0]);
    //ruota in senso antiorario i vertici e gli spigoli delle facce adiacenti
}

//disegna 2D con il Nord rivolto verso... NSWO
void Faccia::drawN(sf::RenderWindow &window, float x, float y, float size)
{
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
        {
            float xj = x + j * size;
            float yi = y + i * size;
            drawTessera2D(window, tessere[i][j], xj, yi, size);
        }
}
void Faccia::drawS(sf::RenderWindow &window, float x, float y, float size)
{
}
void Faccia::drawW(sf::RenderWindow &window, float x, float y, float size)
{
}
void Faccia::drawO(sf::RenderWindow &window, float x, float y, float size)
{
}

//get colori tessere, (in caso il chiamante voglia fare il disegno 3D)
ColoreRGB Faccia::getCentro(void)
{
    return this->colore;
}
ColoreRGB Faccia::getNord(void)
{
    return this->tessere[0][1];
}
ColoreRGB Faccia::getEst(void)
{
    return this->tessere[1][2];
}
ColoreRGB Faccia::getSud(void)
{
    return this->tessere[2][1];
}
ColoreRGB Faccia::getOvest(void)
{
    return this->tessere[1][0];
}
ColoreRGB Faccia::getNE(void)
{
    return this->tessere[0][2];
}
ColoreRGB Faccia::getNW(void)
{
    return this->tessere[0][0];
}
ColoreRGB Faccia::getSE(void)
{
    return this->tessere[2][2];
}
ColoreRGB Faccia::getSW(void)
{
    return this->tessere[2][0];
}

//PROTECTED?
//vorrei che solo altre facce potessero modificarmi facendo la move
//possibile?
void Faccia::setNord(ColoreRGB colore)
{
    this->tessere[0][1] = colore;
}
void Faccia::setEst(ColoreRGB colore)
{
    this->tessere[1][2] = colore;
}
void Faccia::setSud(ColoreRGB colore)
{
    this->tessere[2][1] = colore;
}
void Faccia::setOvest(ColoreRGB colore)
{
    this->tessere[1][0] = colore;
}
void Faccia::setNE(ColoreRGB colore)
{
    this->tessere[0][2] = colore;
}
void Faccia::setNW(ColoreRGB colore)
{
    this->tessere[0][0] = colore;
}
void Faccia::setSE(ColoreRGB colore)
{
    this->tessere[2][2] = colore;
}
void Faccia::setSW(ColoreRGB colore)
{
    this->tessere[2][0] = colore;
}