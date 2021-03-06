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

void ruotaLatoOrario(ColoreRGB *nord[DIM], ColoreRGB *est[DIM], ColoreRGB *sud[DIM], ColoreRGB *ovest[DIM])
{
    for (int i = 0; i < DIM; i++)
        ruotaOrario(*nord[i], *est[i], *sud[i], *ovest[i]);
}
void ruotaLatoAntiorario(ColoreRGB *nord[DIM], ColoreRGB *est[DIM], ColoreRGB *sud[DIM], ColoreRGB *ovest[DIM])
{
    for (int i = 0; i < DIM; i++)
        ruota_anti(*nord[i], *est[i], *sud[i], *ovest[i]);
}

//PUBLIC
//costruttore
Faccia::Faccia(void)
{
    //costruttore vuoto
}
Faccia::Faccia(ColoreRGB colore)
{
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
//muovi lei ma non le vicine
void Faccia::move(void)
{
    //ruota in senso orario i miei vertici (Nord, Est, Sud, Ovest)
    ruotaOrario(tessere[0][1], tessere[1][2], tessere[2][1], tessere[1][0]);
    //ruota in senso orario i miei spigoli(NW, NE, SE, SW)
    ruotaOrario(tessere[0][0], tessere[0][2], tessere[2][2], tessere[2][0]);
}
void Faccia::move_anti(void)
{
    //ruota in senso antiorario i miei vertici (Nord, Est, Sud, Ovest)
    ruota_anti(tessere[0][1], tessere[1][2], tessere[2][1], tessere[1][0]);
    //ruota in senso antiorario i miei spigoli
    ruota_anti(tessere[0][0], tessere[0][2], tessere[2][2], tessere[2][0]);
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
//get colori tessere, (in caso il chiamante voglia fare il disegno 3D)
ColoreRGB* Faccia::getCentro(void)
{
    return &this->colore;
}
ColoreRGB* Faccia::getNord(void)
{
    return &this->tessere[0][1];
}
ColoreRGB* Faccia::getEst(void)
{
    return &this->tessere[1][2];
}
ColoreRGB* Faccia::getSud(void)
{
    return &this->tessere[2][1];
}
ColoreRGB* Faccia::getOvest(void)
{
    return &this->tessere[1][0];
}
ColoreRGB* Faccia::getNE(void)
{
    return &this->tessere[0][2];
}
ColoreRGB* Faccia::getNW(void)
{
    return &this->tessere[0][0];
}
ColoreRGB* Faccia::getSE(void)
{
    return &this->tessere[2][2];
}
ColoreRGB* Faccia::getSW(void)
{
    return &this->tessere[2][0];
}

//metto nel vettore i puntatori a tre faccie sullo stesso lato
void Faccia::getLatoNord(ColoreRGB *lato[DIM])
{
    lato[0] = this->getNW();
    lato[1] = this->getNord();
    lato[2] = this->getNE();
}
void Faccia::getLatoEst(ColoreRGB *lato[DIM])
{
    lato[0] = this->getNE();
    lato[1] = this->getEst();
    lato[2] = this->getSE();
}
void Faccia::getLatoSud(ColoreRGB *lato[DIM])
{
    lato[0] = this->getSE();
    lato[1] = this->getSud();
    lato[2] = this->getSW();
}
void Faccia::getLatoOvest(ColoreRGB *lato[DIM])
{
    lato[0] = this->getSW();
    lato[1] = this->getOvest();
    lato[2] = this->getNW();
}
void Faccia::getVettore(ColoreRGB vector[DIM*DIM], int rotazione) {	
	vector[(0 + rotazione * 2) % 8] = *this->getNW();
	vector[(1 + rotazione * 2) % 8] = *this->getNord();
	vector[(2 + rotazione * 2) % 8] = *this->getNE();
	vector[(3 + rotazione * 2) % 8] = *this->getEst();
	vector[(4 + rotazione * 2) % 8] = *this->getSE();
	vector[(5 + rotazione * 2) % 8] = *this->getSud();
	vector[(6 + rotazione * 2) % 8] = *this->getSW();
	vector[(7 + rotazione * 2) % 8] = *this->getOvest();
	vector[8] = *this->getCentro();
}
void Faccia::getVettoreAnti(ColoreRGB vector[DIM*DIM], int rotazione) {	
	vector[(0 + rotazione * 2) % 8] = *this->getNE();
	vector[(1 + rotazione * 2) % 8] = *this->getNord();
	vector[(2 + rotazione * 2) % 8] = *this->getNW();
	vector[(3 + rotazione * 2) % 8] = *this->getOvest();
	vector[(4 + rotazione * 2) % 8] = *this->getSW();
	vector[(5 + rotazione * 2) % 8] = *this->getSud();
	vector[(6 + rotazione * 2) % 8] = *this->getSE();
	vector[(7 + rotazione * 2) % 8] = *this->getEst();
	vector[8] = *this->getCentro();
}

