#ifndef CUBO_HPP
#define CUBO_HPP

#define DIM 3

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"

extern float WIDTH, HEIGHT;

class Cubo : public DisegnabileI
{
    private:
        //facce
        ColoreRGB F[DIM][DIM];
        ColoreRGB R[DIM][DIM];
        ColoreRGB U[DIM][DIM];
        ColoreRGB B[DIM][DIM];
        ColoreRGB L[DIM][DIM];
        ColoreRGB D[DIM][DIM];
    private:
        //funzioni ausiliarie
        //che crea una faccia di un colore
        void creaFaccia(ColoreRGB faccia[DIM][DIM], ColoreRGB colore);
        //che ruotano 4 colori tra loro
        /*[t][x]
          [z][y]
        */
        void ruotaOrario(ColoreRGB& t, ColoreRGB& x, ColoreRGB& y, ColoreRGB& z);
        void ruota_anti(ColoreRGB& t, ColoreRGB& x, ColoreRGB& y, ColoreRGB& z);
        //che ruota una intera faccia (senza modificare le facce vicine)
        void facciaOrario(ColoreRGB faccia[DIM][DIM]);
        void faccia_anti(ColoreRGB faccia[DIM][DIM]);
        //disegna
        void drawFaccia(sf::RenderWindow &window, ColoreRGB faccia[DIM][DIM], float x, float y, float size);
    
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
        //disegna
        void draw2D(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size);
        void draw_3D_BLD(sf::RenderWindow &window, float x, float y, float size);
};

#endif //CUBO_HPP
