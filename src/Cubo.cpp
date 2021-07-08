#include "../header/Cubo.hpp"
#include <cstdlib>
#include <ctime>

void drawTessera3D(sf::RenderWindow &window, float x, float y, float angolo, ColoreRGB colore, sf::Color bordo, float lato)
{
    //l'altezza del triangolo equilatero che forma "metà" tessera 3D
    float mezzoLato = lato / 2;
    float altezza = lato * sqrt(3) / 2;
    // create an empty shape
    sf::ConvexShape convex;
    // resize it to 5 points
    convex.setPointCount(4);
    // define the points
    convex.setPoint(0, sf::Vector2f(0.f, -lato));
    convex.setPoint(1, sf::Vector2f(+altezza, -mezzoLato));
    convex.setPoint(2, sf::Vector2f(0.f, 0.f));
    convex.setPoint(3, sf::Vector2f(-altezza, -mezzoLato));

    //colore
    convex.setFillColor(colore.getColorLib());
    //setta un bordo di 1 all'interno del quadrato
    convex.setOutlineThickness(-1);
    //di colore del bordo
    convex.setOutlineColor(bordo);
    //orienta
    convex.setRotation(angolo);
    convex.setPosition(x, y);
    //disegna
    window.draw(convex);
}

//PUBLIC
Cubo::Cubo(void)
{
    //facce
    this->F = Faccia(ColoreRGB::Rosso);
    this->R = Faccia(ColoreRGB::Blu);
    this->U = Faccia(ColoreRGB::Viola);
    this->B = Faccia(ColoreRGB::Arancio);
    this->L = Faccia(ColoreRGB::Verde);
    this->D = Faccia(ColoreRGB::Giallo);
    //facce
    this->Reset();
}

Cubo::Cubo(ColoreRGB front, ColoreRGB right, ColoreRGB up, ColoreRGB back, ColoreRGB left, ColoreRGB down)
{
    //facce
    this->F = Faccia(front);
    this->R = Faccia(right);
    this->U = Faccia(up);
    this->B = Faccia(back);
    this->L = Faccia(left);
    this->D = Faccia(down);
    //facce
    this->Reset();
}

//resetta
void Cubo::Reset(void)
{
    this->F.Reset();
    this->R.Reset();
    this->U.Reset();
    this->B.Reset();
    this->L.Reset();
    this->D.Reset();
}
//fai una mossa
void Cubo::MOSSA(int m) {int senso;
	//capisco se è di senso orario (0-5) o antiorario (6-11)
	if(m < 6)
		senso = ORARIO;
	else
		senso = ANTIORARIO;
	//ora capisco la faccia utilizzando il resto della divisione per 6
	switch (m % 6) {
		case 0:
			cout << "F";
			this->Front(senso);
			break;
		case 1:
			cout << "R";
			this->Right(senso);
			break;
		case 2:
			cout << "U";
			this->Up(senso);
			break;
		case 3:
			cout << "B";
			this->Back(senso);
			break;
		case 4:
			cout << "L";
			this->Left(senso);
			break;
		case 5:
			cout << "D";
			this->Down(senso);
			break;
		default:
			break;
	}
	if(senso == ANTIORARIO) cout << "'";
	else cout << " ";
}
//randomizza
void Cubo::Random(int n) {
	cout << "\nRandomizzo: ";
	srand(time(NULL));
	for(int i = 0; i < n ; i++) {
		//genero una delle possibili 12 mosse
		int mossa = rand()%12;
		this->MOSSA(mossa);
	}
	cout << endl;
}
//ruota in senso Orario
void Cubo::Front(int senso)
{
    ColoreRGB * Up[DIM], * Right[DIM], * Down[DIM], * Left[DIM];
    this->U.getLatoSud(Up);
    this->R.getLatoOvest(Right);
    this->D.getLatoNord(Down);
    this->L.getLatoEst(Left);
    switch (senso)
    {
    case ORARIO:
        this->F.move();
        ruotaLatoOrario(Up, Right, Down, Left);
        break;
    case ANTIORARIO:
        this->F.move_anti();
        ruotaLatoAntiorario(Up, Right, Down, Left);
        break;
    default:
        break;
    }
}
void Cubo::Right(int senso)
{
    ColoreRGB * Up[DIM], * Back[DIM], * Down[DIM], * Front[DIM];
    this->U.getLatoEst(Up);
    this->B.getLatoOvest(Back);
    this->D.getLatoEst(Down);
    this->F.getLatoEst(Front);
    switch (senso)
    {
    case ORARIO:
        this->R.move();
        ruotaLatoOrario(Up, Back, Down, Front);
        break;
    case ANTIORARIO:
        this->R.move_anti();
        ruotaLatoAntiorario(Up, Back, Down, Front);
        break;
    default:
        break;
    }
}
void Cubo::Up(int senso)
{
    ColoreRGB * Back[DIM], * Right[DIM], * Front[DIM], * Left[DIM];
    this->B.getLatoNord(Back);
    this->R.getLatoNord(Right);
    this->F.getLatoNord(Front);
    this->L.getLatoNord(Left);
    switch (senso)
    {
    case ORARIO:
        this->U.move();
        ruotaLatoOrario(Back, Right, Front, Left);
        break;
    case ANTIORARIO:
        this->U.move_anti();
        ruotaLatoAntiorario(Back, Right, Front, Left);
        break;
    default:
        break;
    }
}
void Cubo::Back(int senso)
{
    ColoreRGB *Up[DIM], * Left[DIM], * Down[DIM], * Right[DIM];
    this->U.getLatoNord(Up);
    this->L.getLatoOvest(Left);
    this->D.getLatoSud(Down);
    this->R.getLatoEst(Right);
    switch (senso)
    {
    case ORARIO:
        this->B.move();
        ruotaLatoOrario(Up, Left, Down, Right);
        break;
    case ANTIORARIO:
        this->B.move_anti();
        ruotaLatoAntiorario(Up, Left, Down, Right);
        break;
    default:
        break;
    }
}
void Cubo::Left(int senso)
{
    ColoreRGB *Up[DIM], *Front[DIM], * Down[DIM], * Back[DIM];
    this->U.getLatoOvest(Up);
    this->F.getLatoOvest(Front);
    this->D.getLatoOvest(Down);
    this->B.getLatoEst(Back);
    switch (senso)
    {
    case ORARIO:
        this->L.move();
        ruotaLatoOrario(Up, Front, Down, Back);
        break;
    case ANTIORARIO:
        this->L.move_anti();
        ruotaLatoAntiorario(Up, Front, Down, Back);
        break;
    default:
        break;
    }
}
void Cubo::Down(int senso)
{
    ColoreRGB *Front[DIM], *Right[DIM], * Back[DIM], * Left[DIM];
    this->F.getLatoSud(Front);
    this->R.getLatoSud(Right);
    this->B.getLatoSud(Back);
    this->L.getLatoSud(Left);
    switch (senso)
    {
    case ORARIO:
        this->D.move();
        ruotaLatoOrario(Front, Right, Back, Left);
        break;
    case ANTIORARIO:
        this->D.move_anti();
        ruotaLatoAntiorario(Front, Right, Back, Left);
        break;
    default:
        break;
    }
}

//disegna
void Cubo::draw2D(sf::RenderWindow &window, float x, float y, float size)
{
    //cout << "\n 2D: x = " << x << ", y = " << y << "size = " << size;
    //lunghezza del lato
    float lato = size * DIM;
    this->F.drawN(window, x + 1 * lato, y + 1 * lato, size);
    this->R.drawN(window, x + 2 * lato, y + 1 * lato, size);
    this->U.drawN(window, x + 1 * lato, y + 0 * lato, size);
    this->B.drawN(window, x + 3 * lato, y + 1 * lato, size);
    this->L.drawN(window, x + 0 * lato, y + 1 * lato, size);
    this->D.drawN(window, x + 1 * lato, y + 2 * lato, size);
}
void Cubo::draw_3D_FRU_vect(sf::RenderWindow &window, float x, float y, float size,
ColoreRGB front[DIM*DIM], ColoreRGB right[DIM*DIM], ColoreRGB up[DIM*DIM])
{
    //cout << "\n 3D_FRU: x = " << x << ", y = " << y << "size = " << size;
    sf::Color sfondo = sf::Color::White;
    float altezza = size * sqrt(3) / 2;
    //FRONT
    drawTessera3D(window, x - altezza * 2, y - size, FRONT, front[0], sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, FRONT, front[1], sfondo, size);
    drawTessera3D(window, x, y, FRONT, front[2], sfondo, size);
    drawTessera3D(window, x, y + size, FRONT, front[3], sfondo, size);
    drawTessera3D(window, x, y + size * 2, FRONT, front[4], sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, FRONT, front[5], sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, FRONT, front[6], sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, FRONT, front[7], sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, FRONT, front[8], sfondo, size);
    //RIGHT
    drawTessera3D(window, x, y, RIGHT, right[0], sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, RIGHT, right[1], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, RIGHT, right[2], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, RIGHT, right[3], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, RIGHT, right[4], sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, RIGHT, right[5], sfondo, size);
    drawTessera3D(window, x, y + size * 2, RIGHT, right[6], sfondo, size);
    drawTessera3D(window, x, y + size, RIGHT, right[7], sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, RIGHT, right[8], sfondo, size);
    //UP
    drawTessera3D(window, x, y - size * 2, UP, up[0], sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, UP, up[1], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, UP, up[2], sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, UP, up[3], sfondo, size);
    drawTessera3D(window, x, y, UP, up[4], sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, UP, up[5], sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, UP, up[6], sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, UP, up[7], sfondo, size);
    drawTessera3D(window, x, y - size, UP, up[8], sfondo, size);
}
void Cubo::draw_3D_BLD_vect(sf::RenderWindow &window, float x, float y, float size,
ColoreRGB back[DIM*DIM], ColoreRGB left[DIM*DIM], ColoreRGB down[DIM*DIM], sf::Color
 sfondo)
{
    //cout << "\n 3D_BLD_rotated: x = " << x << ", y = " << y << "size = " << size;
    //se i vettori di B,L,D sono ottenuti da getVettore() è la visuale ruotata.
    //per la visuale tagliata bisogna considerare quella ruotata e con i numeri delle faccie fare la "rotazione" attorno all'asse del disegno 3D.
    float altezza = size * sqrt(3) / 2;
    //BACK
    drawTessera3D(window, x - altezza * 2, y - size, BACK, back[0], sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, BACK, back[1], sfondo, size);
    drawTessera3D(window, x, y - size * 2, BACK, back[2], sfondo, size);
    drawTessera3D(window, x, y - size, BACK, back[3], sfondo, size);
    drawTessera3D(window, x, y, BACK, back[4], sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, BACK, back[5], sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, BACK, back[6], sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, BACK, back[7], sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, BACK, back[8], sfondo, size);
    //LEFT
    drawTessera3D(window, x, y - size * 2, LEFT, left[0], sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, LEFT, left[1], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, LEFT, left[2], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, LEFT, left[3], sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, LEFT, left[4], sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, LEFT, left[5], sfondo, size);
    drawTessera3D(window, x, y, LEFT, left[6], sfondo, size);
    drawTessera3D(window, x, y - size, LEFT, left[7], sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, LEFT, left[8], sfondo, size);
    //DOWN
    drawTessera3D(window, x + altezza * 2, y + size, DOWN, down[0], sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, DOWN, down[1], sfondo, size);
    drawTessera3D(window, x, y + size * 2, DOWN, down[2], sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, DOWN, down[3], sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, DOWN, down[4], sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, DOWN, down[5], sfondo, size);
    drawTessera3D(window, x, y, DOWN, down[6], sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, DOWN, down[7], sfondo, size);
    drawTessera3D(window, x, y + size, DOWN, down[8], sfondo, size);
}


void Cubo::draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size) {
	ColoreRGB front[DIM*DIM], right[DIM*DIM], up[DIM*DIM];
	this->F.getVettore(front, 0);
	this->R.getVettore(right, 0);
	this->U.getVettore(up, 0);
	this->draw_3D_FRU_vect(window, x, y, size, front, right, up);
}
//inusata, ma già programmata
void Cubo::draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size) {
	sf::Color sfondo = sf::Color::White;
	ColoreRGB back[DIM*DIM], left[DIM*DIM], down[DIM*DIM];
	this->B.getVettore(back, 0);
	this->L.getVettore(left, 0);
	this->D.getVettore(down, 0);
	this->draw_3D_BLD_vect(window, x, y, size, back, left, down, sfondo);
}
void Cubo::draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size) {
	sf::Color sfondo = sf::Color::Cyan;
	//NB per la version cutted Back e left sono switchati
	//quindi i vettori hanno nomi giusti e leggono facce giuste ...
	ColoreRGB back[DIM*DIM], left[DIM*DIM], down[DIM*DIM];
	this->B.getVettoreAnti(back, 0);
	this->L.getVettoreAnti(left, 0);
	this->D.getVettoreAnti(down, 1);
	//... ma la drawn inverte back e left di posizione BLD->LBD
	this->draw_3D_BLD_vect(window, x, y, size, left, back, down, sfondo);
}
void Cubo::draw_upsidedown(sf::RenderWindow &window, float x, float y, float size) {
	//il cubo capovolto con Down verso up
	ColoreRGB front[DIM*DIM], right[DIM*DIM], up[DIM*DIM];
	this->L.getVettore(front, 2);
	this->B.getVettore(right, 2);
	this->D.getVettore(up, 3);
	this->draw_3D_FRU_vect(window, x, y, size, front, right, up);
}
void Cubo::draw_upsidedown_cutted(sf::RenderWindow &window, float x, float y, float size) {
	sf::Color sfondo = sf::Color::White;
	//NB per la version cutted Back e left sono switchati
	//quindi i vettori hanno nomi giusti e leggono facce giuste ...
	ColoreRGB back[DIM*DIM], left[DIM*DIM], down[DIM*DIM];
	this->F.getVettoreAnti(back, 2);
	this->R.getVettoreAnti(left, 2);
	this->U.getVettoreAnti(down, 0);
	this->draw_3D_BLD_vect(window, x, y, size, back, left, down, sfondo);
}
void Cubo::draw_upsidedown_rotated(sf::RenderWindow &window, float x, float y, float size) {
	sf::Color sfondo = sf::Color::White;
	//quindi i vettori hanno nomi giusti e leggono facce giuste ...
	ColoreRGB back[DIM*DIM], left[DIM*DIM], down[DIM*DIM];
	this->F.getVettoreAnti(back, 0);
	this->R.getVettoreAnti(left, 0);
	this->U.getVettoreAnti(down, 1);
	//... ma la drawn inverte back e left di posizione BLD->LBD
	this->draw_3D_BLD_vect(window, x, y, size, left, back, down, sfondo);
}
//disegno le eventuali freccie sulla visuale del cubo con x, y, size di mossa m
void Cubo::drawFreccia(sf::RenderWindow &window, int m, float x, float y, float size) {
	if(0 <= m && m <= 11) {
		//dim è metà del lato di una tessera
		float dim = size / 2;
	    	float alt = size * sqrt(3) /2;
		//freccia
		Freccia freccia1, freccia2;
		//punti sulla faccia UP
		Punto A = Punto(x		, y - dim * 5);
		Punto B = Punto(x + alt * 2	, y - dim * 3);
		Punto C = Punto(x		, y - dim * 1);
		Punto D = Punto(x - alt * 2	, B.getY()); //stessa y di B
		//punti sulla faccia Front
		Punto E = Punto(x - alt*5/2	, y - dim*3/2);
		Punto F = Punto(x - alt / 2	, y + dim / 2);
		Punto G = Punto(x - alt / 2	, y + dim*9/2); //non sono sicura di y
		Punto H = Punto(x - alt*5/2	, y + dim*5/2); // non sono sicura di y 
		//punti sulla faccia Right
		Punto I = Punto(x + alt / 2	, F.getY()); //stessa y di F
		Punto L = Punto(x + alt*5/2	, E.getY()); //stessa y di E
		Punto M = Punto(x + alt*5/2	, H.getY()); //stessa y di H
		Punto N = Punto(x + alt / 2	, G.getY()); //stessa y di G
		switch (m % 6) {
			case 0: //Front
				freccia1 = Freccia("F", D, C);
				freccia2 = Freccia("F", I, N);
				break;
			case 1: //Right
				freccia1 = Freccia("R", G, F);
				freccia2 = Freccia("R", C, B);
				break;
			case 2: //Up
				freccia1 = Freccia("U", L, I);
				freccia2 = Freccia("U", F, E);
				break;
			case 3: //Back
				freccia1 = Freccia("B", M, L);
				freccia2 = Freccia("B", B, A);
				break;
			case 4: //Left
				freccia1 = Freccia("L", A, D);
				freccia2 = Freccia("L", E, H);
				break;
			case 5: //Down
				freccia1 = Freccia("D", H, G);
				freccia2 = Freccia("D", N, M);
			default:
				break;
		}
		freccia1.draw(window);
		freccia2.draw(window);
	}
}
void Cubo::draw(sf::RenderWindow &window, int m, float x, float y, float size)
{
	this->draw2D(window, x+350.f, y+135.f, size * 2 / 3);
	this->draw_3D_FRU(window, x+150.f, y+160.f, size);
	this->draw_3D_BLD_cutted(window, x+225.f, y+440.f, size);
	this->draw_upsidedown(window, x+750.f, y+410.f, size / 3);
	this->draw_upsidedown_cutted(window, x+700.f, y+500.f, size / 3);
	//un altro FRU più piccolo per le freccie
	float x_f = x + 640.f;
	float y_f = y + 410.f;
	float s_f = size/3;
	this->draw_3D_FRU(window, x_f, y_f, s_f);
	//disegno la freccia (del FRU più piccolo) della mossa che ho fatto)
	this->drawFreccia(window, m, x_f, y_f, s_f); 
}
void Cubo::draw(sf::RenderWindow &window, int m) {
	this->draw(window, m, 0.f, 0.f, 50.f);
}
