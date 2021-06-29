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
    ColoreRGB *Up[DIM], *Right[DIM], *Down[DIM], *Left[DIM];
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
    ColoreRGB *Up[DIM], *Back[DIM], *Down[DIM], *Front[DIM];
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
    ColoreRGB *Back[DIM], *Right[DIM], *Front[DIM], *Left[DIM];
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
    ColoreRGB *Up[DIM], *Left[DIM], *Down[DIM], *Right[DIM];
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
    ColoreRGB *Up[DIM], *Front[DIM], *Down[DIM], *Back[DIM];
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
    ColoreRGB *Front[DIM], *Right[DIM], *Back[DIM], *Left[DIM];
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

//set canvas info per disegnare
void Cubo::setCanvas(float x, float y, float size, float dist) {
	this->x = x;
	this->y = y;
	this->size = size;
	this->dist = dist;
};
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
void Cubo::draw_3D_FRU(sf::RenderWindow &window, float x, float y, float size)
{
    //cout << "\n 3D_FRU: x = " << x << ", y = " << y << "size = " << size;
    sf::Color sfondo = sf::Color::White;
    float altezza = size * sqrt(3) / 2;
    //FRONT
    drawTessera3D(window, x - altezza * 2, y - size, FRONT, *F.getNW(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, FRONT, *F.getNord(), sfondo, size);
    drawTessera3D(window, x, y, FRONT, *F.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, FRONT, *F.getOvest(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, FRONT, *F.getCentro(), sfondo, size);
    drawTessera3D(window, x, y + size, FRONT, *F.getEst(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, FRONT, *F.getSE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, FRONT, *F.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, FRONT, *F.getSW(), sfondo, size);
    //RIGHT
    drawTessera3D(window, x, y, RIGHT, *R.getNW(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, RIGHT, *R.getNord(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, RIGHT, *R.getNE(), sfondo, size);
    drawTessera3D(window, x, y + size, RIGHT, *R.getOvest(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, RIGHT, *R.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, RIGHT, *R.getEst(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, RIGHT, *R.getSW(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, RIGHT, *R.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, RIGHT, *R.getSE(), sfondo, size);
    //UP
    drawTessera3D(window, x, y - size * 2, UP, *U.getNW(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, UP, *U.getNord(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, UP, *U.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, UP, *U.getOvest(), sfondo, size);
    drawTessera3D(window, x, y - size, UP, *U.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, UP, *U.getEst(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, UP, *U.getSW(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, UP, *U.getSud(), sfondo, size);
    drawTessera3D(window, x, y, UP, *U.getSE(), sfondo, size);
}

void Cubo::draw_3D_BLD_cutted(sf::RenderWindow &window, float x, float y, float size)
{
    //cout << "\n 3D_BLD_cutted: x = " << x << ", y = " << y << "size = " << size;
    sf::Color sfondo = sf::Color::Cyan;
    //visuale ottenuta "tagliando il cubo" come fosse una camera su thesims
    sf::CircleShape exagon(size * 3, 6);
    exagon.setPosition({x - size * 3, y - size * 3});
    exagon.setFillColor(sf::Color::Magenta);
    window.draw(exagon);
    //cutted
    float altezza = size * sqrt(3) / 2;
    //BACK -> destra
    drawTessera3D(window, x, y, DESTRA, *B.getSE(), sfondo, size);
    drawTessera3D(window, x, y - size, DESTRA, *B.getEst(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, DESTRA, *B.getNE(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, DESTRA, *B.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, DESTRA, *B.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, DESTRA, *B.getNord(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, DESTRA, *B.getSW(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, DESTRA, *B.getOvest(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, DESTRA, *B.getNW(), sfondo, size);
    //LEFT -> sinistra
    drawTessera3D(window, x - altezza * 2, y + size, SINISTRA, *L.getSE(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, SINISTRA, *L.getEst(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, SINISTRA, *L.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, SINISTRA, *L.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, SINISTRA, *L.getCentro(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, SINISTRA, *L.getNord(), sfondo, size);
    drawTessera3D(window, x, y, SINISTRA, *L.getSW(), sfondo, size);
    drawTessera3D(window, x, y - size, SINISTRA, *L.getOvest(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, SINISTRA, *L.getNW(), sfondo, size);
    //DOWN
    drawTessera3D(window, x - altezza * 2, y + size, SOTTO, *D.getNW(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, SOTTO, *D.getNord(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, SOTTO, *D.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, SOTTO, *D.getOvest(), sfondo, size);
    drawTessera3D(window, x, y + size, SOTTO, *D.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, SOTTO, *D.getEst(), sfondo, size);
    drawTessera3D(window, x, y, SOTTO, *D.getSW(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, SOTTO, *D.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y + size, SOTTO, *D.getSE(), sfondo, size);
}

void Cubo::draw_3D_BLD_rotated(sf::RenderWindow &window, float x, float y, float size)
{
    //cout << "\n 3D_BLD_rotated: x = " << x << ", y = " << y << "size = " << size;
    sf::Color sfondo = sf::Color::White;
    //visuale ottenuta ruotando il cubo
    float altezza = size * sqrt(3) / 2;
    //BACK
    drawTessera3D(window, x, y, BACK, *B.getSE(), sfondo, size);
    drawTessera3D(window, x, y - size, BACK, *B.getEst(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, BACK, *B.getNE(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, BACK, *B.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size / 2, BACK, *B.getCentro(), sfondo, size);
    drawTessera3D(window, x - altezza, y - size * 3 / 2, BACK, *B.getNord(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, BACK, *B.getSW(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y, BACK, *B.getOvest(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y - size, BACK, *B.getNW(), sfondo, size);
    //LEFT
    drawTessera3D(window, x + altezza * 2, y + size, LEFT, *L.getSE(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y, LEFT, *L.getEst(), sfondo, size);
    drawTessera3D(window, x + altezza * 2, y - size, LEFT, *L.getNE(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, LEFT, *L.getSud(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size / 2, LEFT, *L.getCentro(), sfondo, size);
    drawTessera3D(window, x + altezza, y - size * 3 / 2, LEFT, *L.getNord(), sfondo, size);
    drawTessera3D(window, x, y, LEFT, *L.getSW(), sfondo, size);
    drawTessera3D(window, x, y - size, LEFT, *L.getOvest(), sfondo, size);
    drawTessera3D(window, x, y - size * 2, LEFT, *L.getNW(), sfondo, size);
    //DOWN
    drawTessera3D(window, x + altezza * 2, y + size, DOWN, *D.getNW(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size * 3 / 2, DOWN, *D.getNord(), sfondo, size);
    drawTessera3D(window, x, y + size * 2, DOWN, *D.getNE(), sfondo, size);
    drawTessera3D(window, x + altezza, y + size / 2, DOWN, *D.getOvest(), sfondo, size);
    drawTessera3D(window, x, y + size, DOWN, *D.getCentro(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size * 3 / 2, DOWN, *D.getEst(), sfondo, size);
    drawTessera3D(window, x, y, DOWN, *D.getSW(), sfondo, size);
    drawTessera3D(window, x - altezza, y + size / 2, DOWN, *D.getSud(), sfondo, size);
    drawTessera3D(window, x - altezza * 2, y + size, DOWN, *D.getSE(), sfondo, size);
}

void Cubo::draw(sf::RenderWindow &window)
{
	this->draw2D(window, x+350.f, y+135.f, size * 2 / 3);
	this->draw_3D_FRU(window, x+150.f, y+160.f, size);
	this->draw_3D_BLD_cutted(window, x+225.f, y+440.f, size);
	this->draw_3D_BLD_rotated(window, x+720.f, y+500.f, size / 3);
}
void Cubo::drawFreccia(sf::RenderWindow &window, int m) {
	float x = this->x + 640.f;
	float y = this->y + 410.f;
	float size = this->size / 3; //this->size = 50, size = 16,6 con 6 periodico
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
	//un altro FRU più piccolo per le freccie
	this->draw_3D_FRU(window, x, y, size);
	freccia1.draw(window);
	freccia2.draw(window);
}
