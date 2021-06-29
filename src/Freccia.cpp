#include "../header/Freccia.hpp"

//costruttore vuoto
Freccia::Freccia() {
}
//costruttore usato
Freccia::Freccia(string testo, Punto p1, Punto p2) {
	this->inizio = p1;
	this->fine = p2;
	this->testo = testo;
}
//costruttore completo
Freccia::Freccia(string testo, Punto p1, Punto p2, float size, ColoreRGB colore) {
	this->inizio = p1;
	this->fine = p2;
	this->size = size;
	this->testo = testo;
	ColoreRGB color = colore;
}

//setters
void Freccia::setInizio(Punto p1) { this->inizio = p1; }
void Freccia::setFine(Punto p2) { this->fine = p2; }
void Freccia::setTesto(string testo) { this->testo = testo; }
void Freccia::setSize(float size) { this->size = size; }
//getters
Punto Freccia::getInizio() { return this->inizio; }
Punto Freccia::getFine() { return this->fine; }
string Freccia::getTesto() { return this->testo; }
float Freccia::getSize() { return this->size; }

//disegna
void Freccia::draw(sf::RenderWindow &window) {
	//non so pk una linea deve essere così complicata...
	/*sf::Vertex line[] =
	{
	    sf::Vertex(this->inizio.getPuntoLib()),
	    sf::Vertex(this->fine.getPuntoLib())
	};
	window.draw(line, 2, sf::Lines);*/
	sf::ConvexShape arrow;
	arrow.setPointCount(4);
	//TODO: offset dovrebbe essere perpendicolare
	arrow.setPoint(0, sf::Vector2f(
		  this->inizio.getX() - this->offset
		, this->inizio.getY() - this->offset
		));
	arrow.setPoint(1, sf::Vector2f(
		  this->inizio.getX() + this->offset
		, this->inizio.getY() + this->offset
		));
	arrow.setPoint(2, sf::Vector2f(
		  this->fine.getX() + this->offset
		, this->fine.getY() + this->offset
		));
	arrow.setPoint(3, sf::Vector2f(
		  this->fine.getX() - this->offset
		, this->fine.getY() - this->offset
		));
	arrow.setFillColor(this->color.getColorLib());
	//draw
	window.draw(arrow);
	sf::CircleShape triangle(this->size, 6);
	triangle.setPosition(this->fine.getX() - this->size, this->fine.getY() - this->size);
	triangle.setFillColor(this->color.getColorLib());
	//draw
	window.draw(triangle);
	//font e testo
	sf::Font font;
	sf::Text text;
	//carico il font
	if (!font.loadFromFile("verdanab.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return;
	}
	//punto medio per il testo
	float medio_x = (this->inizio.getX() + this->fine.getX()) / 2 + this->offset ;
	float medio_y = (this->inizio.getY() + this->fine.getY()) / 2 + this->offset;
	Punto medio = Punto(medio_x, medio_y);
	//setto il buttonText
	text.setFont(font);
	text.setCharacterSize(this->size*2);
	text.setString(this->testo);
	text.setPosition(medio.getPuntoLib());
	text.setFillColor(this->color.getColorLib());
	//draw
	window.draw(text);
}

