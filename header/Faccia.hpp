#ifndef FACCIA_HPP
#define FACCIA_HPP

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"

#define DIM 3 //cubo di Rubik 3x3

extern float WIDTH, HEIGHT;

class Faccia : public DisegnabileI
{
private:
    //il nome ha importanza perchè se è FRLB so che se vado a ovest e poi a est
    //o viceversa torno sulla stessa faccia, ma se invece è U o D no!
    //e move deve sapere come orientarsi in mezzo alle facce del cubo
    char name;
    //puntatori alle altre facce
    Faccia *faceNord = nullptr;
    Faccia *faceSud = nullptr;
    Faccia *faceEst = nullptr;
    Faccia *faceOvest = nullptr;
    //colori delle tessere
    /* [NW][N ][NE]
    *  [w ][ C][E ]
    *  [SW][S ][SE] */
    ColoreRGB colore; //colore fisso della tessera centrale
    ColoreRGB t_Nord;     //su ^
    ColoreRGB t_Est;      //destra -->
    ColoreRGB t_Sud;      //giù v
    ColoreRGB t_West;     //sinistra <--, ovest, orange, arancio
    ColoreRGB t_NE;       //nord est
    ColoreRGB t_NW;       //nord ovest
    ColoreRGB t_SE;       //sud est
    ColoreRGB t_SW;       //sud ovest

private:
    void ruotaOrario(ColoreRGB &n, ColoreRGB &e, ColoreRGB &s, ColoreRGB &w);
    void ruota_anti(ColoreRGB &n, ColoreRGB &e, ColoreRGB &s, ColoreRGB &w);

public:
    //costruttore
    Faccia(void);
    Faccia(ColoreRGB colore, char name, Faccia &nord, Faccia &est, Faccia &sud, Faccia &ovest);
    virtual ~Faccia(void){};

    //resetta la faccia del suo colore
    void Reset(void);
    //muovi lei e le vicine
    void move(void);
    void move_anti(void);

    //disegna 2D con il Nord rivolto verso... NSWO
    void drawN(sf::RenderWindow &window, float x, float y, float lato);
    void drawS(sf::RenderWindow &window, float x, float y, float lato);
    void drawW(sf::RenderWindow &window, float x, float y, float lato);
    void drawO(sf::RenderWindow &window, float x, float y, float lato);

    //get colori tessere, (in caso il chiamante voglia fare il disegno 3D)
    ColoreRGB getCentro(void);
    ColoreRGB getNord(void);
    ColoreRGB getEst(void);
    ColoreRGB getSud(void);
    ColoreRGB getOvest(void);
    ColoreRGB getNE(void);
    ColoreRGB getNW(void);
    ColoreRGB getSE(void);
    ColoreRGB getSW(void);

protected:
    //vorrei che solo altre facce potessero modificarmi facendo la move
    //possibile?
    void setNord(ColoreRGB colore);
    void setEst(ColoreRGB colore);
    void setSud(ColoreRGB colore);
    void setOvest(ColoreRGB colore);
    void setNE(ColoreRGB colore);
    void setNW(ColoreRGB colore);
    void setSE(ColoreRGB colore);
    void setSW(ColoreRGB colore);
};
#endif //FACCIA_HPP