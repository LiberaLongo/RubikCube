#include "../header/Cubo.hpp"

//private
//funzioni ausiliarie
//che ruotano 4 colori tra loro
/*[t][x]
  [z][y]
*/
void Cubo::ruotaOrario(ColoreRGB &t, ColoreRGB &x, ColoreRGB &y, ColoreRGB &z)
{
    //TO DO
}
void Cubo::ruotaAntiorario(ColoreRGB &t, ColoreRGB &x, ColoreRGB &y, ColoreRGB &z)
{
    //TO DO
}
//che ruota una intera faccia (senza modificare le facce vicine)
void Cubo::facciaOrario(ColoreRGB faccia[DIM][DIM]) {}
void Cubo::facciaAntiorario(ColoreRGB faccia[DIM][DIM]) {}

//public
Cubo::Cubo(void) {}
//ruota in senso Orario
void Cubo::Front(void) {}
void Cubo::Right(void) {}
void Cubo::Up(void) {}
void Cubo::Back(void) {}
void Cubo::Left(void) {}
void Cubo::Down(void) {}
//ruota in senso Antiorario
void Cubo::FrontAntiorario(void) {}
void Cubo::RightAntiorario(void) {}
void Cubo::UpAntiorario(void) {}
void Cubo::BackAntiorario(void) {}
void Cubo::LeftAntiorario(void) {}
void Cubo::DownAntiorario(void) {}
//disegna
void Cubo::draw(sf::RenderWindow &window) {}