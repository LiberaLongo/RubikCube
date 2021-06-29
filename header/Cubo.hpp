#ifndef CUBO_HPP
#define CUBO_HPP

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"
#include "./Faccia.hpp"
#include "./Freccia.hpp"

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

void drawTessera3D(sf::RenderWindow &window, float x, float y, float angolo, ColoreRGB colore, sf::Color bordo, float lato);

class Cubo : public DisegnabileI
{
    private:
        //facce
        Faccia F, R, U, B, L, D;
	//info per disegnare
	float x = 0.f, y = 0.f, dist = 10.f;
	float size = min(WIDTH / 4, HEIGHT / 3) / 4;

        //ruota in senso Orario
        void Front(int senso);
        void Right(int senso);
        void Up(int senso);
        void Back(int senso);
        void Left(int senso);
        void Down(int senso);

    
    public:
        Cubo(void);
        Cubo(ColoreRGB front, ColoreRGB right, ColoreRGB up
            , ColoreRGB back, ColoreRGB left, ColoreRGB down);
        virtual ~Cubo(void) {};
        //resetta
        void Reset(void);
	//fai una mossa, con 0 <= m <= 11
	void MOSSA(int m);
	//random
	void Random(int n);
	//set canvas info per disegnare
	void setCanvas(float x, float y, float size, float dist);
        //disegna le varie visuali
        void draw2D(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size);
        //disegna il cubo
        void draw(sf::RenderWindow &window);
	//disegna freccia m % 6 (quindi solo una freccia in senso orario,
	//anche se la mossa è in senso antiorario... modifico dopo forse
	void drawFreccia(sf::RenderWindow &window, int m);
};

#endif //CUBO_HPP
