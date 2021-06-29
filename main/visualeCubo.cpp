#include "../header/visualeCubo.hpp"

extern float WIDTH, HEIGHT;

extern Cubo cubo;

//pubbliche
visualeCubo::visualeCubo(void)
{
}

int visualeCubo::Run(sf::RenderWindow &App)
{
    //comincia la trattazione della finestra
    bool Running = true;
    sf::Event event;

    //selettore della mossa
    int mossa = -1;

    //coordinate per i bottoni
    float sizeB = min(WIDTH / 4, HEIGHT / 3) / 4;
    float x_or = sizeB * 13 / 2, y_or = 0.f;
    float x_anti = x_or + sizeB * 4, y_anti = 0.f;

    //bottone per reset
    Button buttonReset = Button(x_or + sizeB, y_or + sizeB * 19 / 2 + 20.f, "Reset", sizeB * 9 / 2, sizeB * 3 / 2);
    Button buttonRandomize = Button (575.f, 110.f + sizeB, "Random", sizeB*4, sizeB);

    //bottoni per le mosse
    //bottoni senso orario
    Button buttonFront = Button(x_or + 1 * sizeB, y_or + 1 * sizeB, "F", sizeB);
    Button buttonRight = Button(x_or + 2 * sizeB, y_or + 1 * sizeB, "R", sizeB);
    Button buttonUp = Button(x_or + 1 * sizeB, y_or + 0 * sizeB, "U", sizeB);
    Button buttonBack = Button(x_or + 3 * sizeB, y_or + 1 * sizeB, "B", sizeB);
    Button buttonLeft = Button(x_or + 0 * sizeB, y_or + 1 * sizeB, "L", sizeB);
    Button buttonDown = Button(x_or + 1 * sizeB, y_or + 2 * sizeB, "D", sizeB);
    //bottoni senso antiorario
    Button buttonFront_anti = Button(x_anti + 1 * sizeB, y_anti + 1 * sizeB, "F'", sizeB);
    Button buttonRight_anti = Button(x_anti + 2 * sizeB, y_anti + 1 * sizeB, "R'", sizeB);
    Button buttonUp_anti = Button(x_anti + 1 * sizeB, y_anti + 0 * sizeB, "U'", sizeB);
    Button buttonBack_anti = Button(x_anti + 3 * sizeB, y_anti + 1 * sizeB, "B'", sizeB);
    Button buttonLeft_anti = Button(x_anti + 0 * sizeB, y_anti + 1 * sizeB, "L'", sizeB);
    Button buttonDown_anti = Button(x_anti + 1 * sizeB, y_anti + 2 * sizeB, "D'", sizeB);
    //vettore di bottoni
    Button arrayButton[] = {buttonFront, buttonRight, buttonUp, buttonBack, buttonLeft, buttonDown,
                            buttonFront_anti, buttonRight_anti, buttonUp_anti, buttonBack_anti, buttonLeft_anti, buttonDown_anti};
    int array_dim = sizeof(arrayButton) / sizeof(arrayButton[0]);

    //cout << "x = " << buttonUp_anti.getX() << " y = " << buttonDown_anti.getY() ;

    //un punto adibito a mouse click
    Punto mouseClick;
    bool haCliccato;
    cout << endl;
    //esegui il programma finchè la finestra è aperta
    while (Running)
    {
        haCliccato = false;
        //controlla se qualche evento viene scatenato prima del prossimo loop
        while (App.pollEvent(event))
        {
            switch (event.type)
            {
            //se la finestra è stata chiusa
            case sf::Event::Closed:
                return EXIT;
                break;

            //mouse
            case sf::Event::MouseButtonPressed:
                mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                if (buttonReset.checkMouse(mouseClick))
                {
	            cout << "\nReset: \t";			
                    cubo.Reset();
                    haCliccato = true;
                    mossa = -1;
                } else if(buttonRandomize.checkMouse(mouseClick)) {
		    //20 mosse random
		    cubo.Random(20);
		} else 
                    //controlla quale bottone è stato premuto
                    for (int i = 0; i < array_dim; i++)
                    {
                        if (arrayButton[i].checkMouse(mouseClick))
                        {
                            haCliccato = true;
                            mossa = i;
                            break; //esci dal ciclo for
                        }
                    }
            //tastiera
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                //tasto Esc
                case sf::Keyboard::Escape :
		    cout << endl;
                    return VISUALE_MENU;
                    break;
		//tasti FRUBLD
		case sf::Keyboard::F :
		    haCliccato = true;
		    mossa = 0;
		    break;
		case sf::Keyboard::R :
		    haCliccato = true;
		    mossa = 1;
		    break;
		case sf::Keyboard::U :
		    haCliccato = true;
		    mossa = 2;
		    break;
		case sf::Keyboard::B :
		    haCliccato = true;
		    mossa = 3;
		    break;
		case sf::Keyboard::L :
		    haCliccato = true;
		    mossa = 4;
		    break;
		case sf::Keyboard::D :
		    haCliccato = true;
		    mossa = 5;
		    break;
		/*case sf::Keyboard:: :
		    haCliccato = true;
		    mossa = ;
		    break;*/
                default:
                    break;
                }
            default:
                break;
            }
            if (haCliccato)
            {
		cubo.MOSSA(mossa);
		haCliccato = false;
            }
        }

        for (int i = 0; i < array_dim; i++)
        {
            arrayButton[i].setChecked(false);
        }
        buttonReset.setChecked(false);
        if (mossa != -1)
            arrayButton[mossa].setChecked(true);
        else{
            buttonReset.setChecked(true);
	    buttonRandomize.setChecked(true);
	}

        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);
        //disegna qui...
        for (int i = 0; i < array_dim; i++)
        {
            arrayButton[i].draw(App);
        }
        buttonReset.draw(App);
	buttonRandomize.draw(App);
	//cubo.setCanvas(0.f, 0.f, sizeB, 10.f); //lato = sizeB * 3 
        cubo.draw(App);
	//disegno la freccia (solo la freccia) della mossa che ho fatto)
	cubo.drawFreccia(App, mossa);
        //fine del frame corrente
        App.display();
    }
    //non dovrebbe mai raggiungere questo punto
    return EXIT;
}
