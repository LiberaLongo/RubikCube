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
        //disegna le varie visuali
        void draw2D(sf::RenderWindow &window, float x, float y, float size);
        //visualizza 3D le visuali usando vettori per colori (per rotazioni del cubo?)
	void draw_3D_FRU_vect(sf::RenderWindow &window, float x, float y, float size,
ColoreRGB front[DIM*DIM], ColoreRGB right[DIM*DIM], ColoreRGB up[DIM*DIM]);
        void draw_3D_BLD_vect(sf::RenderWindow &window, float x, float y, float size,
ColoreRGB back[DIM*DIM], ColoreRGB left[DIM*DIM], ColoreRGB down[DIM*DIM], sf::Color sfondo);
	//disegna 3D le visuali "normali"
        void draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size);
	void draw_upsidedown(sf::RenderWindow &window, float x, float y, float size);
	void draw_upsidedown_cutted(sf::RenderWindow &window, float x, float y, float size);
	//inusata ma già implementata prima
        void draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size);
	void draw_upsidedown_rotated(sf::RenderWindow &window, float x, float y, float size);
	//disegna freccia m % 6 (quindi solo una freccia in senso orario,
	//anche se la mossa è in senso antiorario... modifico dopo forse
	void drawFreccia(sf::RenderWindow &window, int m, float x, float y, float size);
        //disegna il cubo
        void draw(sf::RenderWindow &window, int m, float x, float y, float size, Punto punti[]);
        void draw(sf::RenderWindow &window, int m, float size, Punto punti[]);
};

#endif //CUBO_HPP
