#include "../header/Gioco.hpp"

float WIDTH = 800.f, HEIGHT = 600.f;

void impostazioniGioco(void)
{
	cout << "\nINIZIA IL GIOCO!\n";
}

int Gioco(void)
{
	//chiedi all'utente se vuole modificare le preimpostazioni
	impostazioniGioco();

	//seme per i numeri casuali
	srand(time(NULL));

	//vettore di sottoclassi di cScreen per gestire le visuali
	std::vector<cScreen *> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "SFML nonGravitar");

	//Preparazione delle visuali
	visualeMenu vM;
	Screens.push_back(&vM);
	//indirizzo visuale menu nel vettore 0
	visualeCubo vC;
	Screens.push_back(&vC);
	//indirizzo visuale cubo nel vettore 1

	//se questi indirizzi vengono modificati bisogna modificare anche VISUALE_... di utils.hpp

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}
