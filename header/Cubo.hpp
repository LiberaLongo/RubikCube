#ifndef CUBO_HPP
#define CUBO_HPP

#define DIM 3

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"

class Cubo : public DisegnabileI
{
    private:
        float size = 20.f;
        //facce
        ColoreRGB F[DIM][DIM];
        ColoreRGB R[DIM][DIM];
        ColoreRGB U[DIM][DIM];
        ColoreRGB L[DIM][DIM];
        ColoreRGB B[DIM][DIM];
        ColoreRGB D[DIM][DIM];
    private:
        //funzioni ausiliarie
        //che ruotano 4 colori tra loro
        /*[t][x]
          [z][y]
        */
        void ruotaOrario(ColoreRGB& t, ColoreRGB& x, ColoreRGB& y, ColoreRGB& z);
        void ruotaAntiorario(ColoreRGB& t, ColoreRGB& x, ColoreRGB& y, ColoreRGB& z);
        //che ruota una intera faccia (senza modificare le facce vicine)
        void facciaOrario(ColoreRGB faccia[DIM][DIM]);
        void facciaAntiorario(ColoreRGB faccia[DIM][DIM]);
    
    public:
        Cubo(void);
        virtual ~Cubo(void) {};
        //ruota in senso Orario
        void Front(void);
        void Right(void);
        void Up(void);
        void Back(void);
        void Left(void);
        void Down(void);
        //ruota in senso Antiorario
        void FrontAntiorario(void);
        void RightAntiorario(void);
        void UpAntiorario(void);
        void BackAntiorario(void);
        void LeftAntiorario(void);
        void DownAntiorario(void);
        //disegna
        void draw(sf::RenderWindow &window);
};

#endif //CUBO_HPP
