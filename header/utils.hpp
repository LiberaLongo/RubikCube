//header cose utili in tutto il codice ausiliarie
#ifndef UTILS_HPP
#define UTILS_HPP

//input e ouput
#include <iostream>
using namespace std;

//definizione per usare M_PI e M_E di cmath
#define _USE_MATH_DEFINES
#include <cmath>
//M_PI pigreco e M_E numero di eulero

//define per il codice, a volte non funziona fillColor di sf::Text
//di default dovrebbe essere non dichiarata, da modificare altrimenti
//#define NON_FUNZIONA_FILL_COLOR

//per i colori
#define LUMUS_MAXIMA 255 //LUMUS_MAXIMA, citazione Harry Potter, (luminosità RGB)

//macro per gestire opportunamente le visuali
#define EXIT -1
enum visuale
{
    VISUALE_MENU,
    VISUALE_CUBO
};

float angoloLibreria(float angolo);

#endif //UTILS_HPP
