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
    int menu = 0;
    
    //testi per comprendere che visuali sono

    //testi e fonts  
    int charSize = 20;
    sf::Font Font;
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    //settings dei testi
    sf::Text testoUp, testoMosse, testoDown, testoCutted;
    testoUp.setFont(Font);
    testoUp.setCharacterSize(charSize);
    testoUp.setString("Up");
    testoMosse.setFont(Font);
    testoMosse.setCharacterSize(charSize);
    testoMosse.setString("Mosse");
    testoDown.setFont(Font);
    testoDown.setCharacterSize(charSize);
    testoDown.setString("Upside down");
    testoCutted.setFont(Font);
    testoCutted.setCharacterSize(charSize);
    testoCutted.setString("Cutted");
    //setting delle posizioni dei cubi (da modificare per ottenere le posizioni dei testi)
    float sizeCubo = 50.f;
    Punto A = Punto(350, 135); //draw2D
    Punto B = Punto(150, 160); //draw3D_FRU
    Punto C = Punto(225, 440); //draw3D_BLD_cutted
    Punto D = Punto(750, 410); //draw_upsidedown
    Punto E = Punto(700, 500); //draw_upsidedown_cutted
    Punto F = Punto(640, 400); //FRU e freccie
    Punto punti[6] = {A, B, C, D, E, F};
    //posizioni dei testi desunte dai punti
    testoUp.setPosition({B.getX() - sizeCubo*3, B.getY() - (sizeCubo*3 - 10.f)});
    testoCutted.setPosition({C.getX() - (sizeCubo*3 + 20.f), C.getY() + sizeCubo*2});
    testoDown.setPosition({E.getX() - sizeCubo, E.getY() + sizeCubo});
    testoMosse.setPosition({F.getX() - (sizeCubo + 25.f) , F.getY() - sizeCubo});
    
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
        cubo.draw(App, mossa, sizeCubo, punti);
        
        //i testi di spiegazione delle visuali del cubo:
        App.draw(testoUp);
        App.draw(testoDown);
        App.draw(testoMosse);
        App.draw(testoCutted);
        
        //fine del frame corrente
        App.display();
    }
    //non dovrebbe mai raggiungere questo punto
    return EXIT;
}
