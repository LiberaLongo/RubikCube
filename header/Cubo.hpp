#ifndef CUBO_HPP
#define CUBO_HPP

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"
#include "./Faccia.hpp"

//angoli di rotazione per avere le tessere della faccia giusta
#define FRONT   240
#define RIGHT   120
#define UP      0
#define BACK    300
#define LEFT    60
#define DOWN    180
#define DESTRA   LEFT
#define SINISTRA BACK
#define SOTTO    DOWN

extern float WIDTH, HEIGHT;

void drawTessera3D(sf::RenderWindow &window, float x, float y, float angolo, ColoreRGB colore, float lato);

class Cubo : public DisegnabileI
{
    private:
        //facce
        Faccia F = Faccia(ColoreRGB::Verde);
        Faccia R = Faccia(ColoreRGB::Rosso);
        Faccia U = Faccia(ColoreRGB::Viola);
        Faccia B = Faccia(ColoreRGB::Blu);
        Faccia L = Faccia(ColoreRGB::Arancio);
        Faccia D = Faccia(ColoreRGB::Giallo);
    
    public:
        Cubo(void);
        virtual ~Cubo(void) {};
        //resetta
        void Reset(void);
        //ruota in senso Orario
        void Front(int senso);
        void Right(int senso);
        void Up(int senso);
        void Back(int senso);
        void Left(int senso);
        void Down(int senso);
        //disegna le varie visuali
        void draw2D(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size);
        //disegna tutto
        void draw(sf::RenderWindow &window, float x, float y, float lato);
};

#endif //CUBO_HPP
