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
        Faccia F = Faccia(ColoreRGB::Verde, 'F', U, R, D, L);
        Faccia R = Faccia(ColoreRGB::Rosso, 'R', U, B, D, F);
        Faccia U = Faccia(ColoreRGB::Viola, 'U', B, R, F, L);
        Faccia B = Faccia(ColoreRGB::Blu, 'B', U, L, D, R);
        Faccia L = Faccia(ColoreRGB::Arancio, 'L', U, F, D, B);
        Faccia D = Faccia(ColoreRGB::Giallo, 'D', F, R, B, L);
    
    public:
        Cubo(void);
        virtual ~Cubo(void) {};
        //resetta
        void Reset(void);
        //ruota in senso Orario
        void Front(void);
        void Right(void);
        void Up(void);
        void Back(void);
        void Left(void);
        void Down(void);
        //ruota in senso antiorario
        void Front_anti(void);
        void Right_anti(void);
        void Up_anti(void);
        void Back_anti(void);
        void Left_anti(void);
        void Down_anti(void);
        //disegna le varie visuali
        void draw2D(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size);
        //disegna tutto
        void draw(sf::RenderWindow &window, float x, float y, float lato);
};

#endif //CUBO_HPP
