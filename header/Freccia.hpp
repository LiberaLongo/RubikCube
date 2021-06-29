#ifndef FRECCIA_HPP
#define FRECCIA_HPP

#include "./utils.hpp"
#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"

extern float WIDTH, HEIGHT;

class Freccia : public DisegnabileI {
private:
	Punto inizio = Punto(0, 0);
	Punto fine = Punto(100, 0);
	float size = 5.f;
	float offset = 1.f;
	string testo = "";
	ColoreRGB color = ColoreRGB(50, 50, 50);
public:
	//costruttore vuoto
	Freccia();
	//costruttore usato
	Freccia(string testo, Punto p1, Punto p2);
	//costruttore completo
	Freccia(string testo, Punto p1, Punto p2, float size, ColoreRGB colore);
	//distruttore
	virtual  ~Freccia(void) {};

	//setters
	void setInizio(Punto p1);
	void setFine(Punto p2);
	void setTesto(string testo);
	void setSize(float size);
	//getters
	Punto getInizio();
	Punto getFine();
	string getTesto();
	float getSize();

	//disegna
	void draw(sf::RenderWindow &window);
};
#endif //FRECCIA_HPP
