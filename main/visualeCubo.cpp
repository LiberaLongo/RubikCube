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
    //dimensione lato del cubo
    float lato = sizeB * 3;

    //bottone per reset
    Button buttonReset = Button(x_or + sizeB, y_or + sizeB * 19 / 2 + 20.f, "Reset", sizeB * 9 / 2, sizeB * 3 / 2);

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
    //un punto adibito a mouse click
    Punto mouseClick;
    bool haCliccato;

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
                    cubo.Reset();
                    haCliccato = true;
                    mossa = -1;
                }
                else
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
                case sf::Keyboard::Escape:
                    return VISUALE_MENU;
                    break;
                default:
                    break;
                }
            default:
                break;
            }
            if (haCliccato)
            {
                switch (mossa)
                {
                case 0:
                    cubo.Front(ORARIO);
                    break;
                case 1:
                    cubo.Right(ORARIO);
                    break;
                case 2:
                    cubo.Up(ORARIO);
                    break;
                case 3:
                    cubo.Back(ORARIO);
                    break;
                case 4:
                    cubo.Left(ORARIO);
                    break;
                case 5:
                    cubo.Down(ORARIO);
                    break;
                case 6 + 0:
                    cubo.Front(ANTIORARIO);
                    break;
                case 6 + 1:
                    cubo.Right(ANTIORARIO);
                    break;
                case 6 + 2:
                    cubo.Up(ANTIORARIO);
                    break;
                case 6 + 3:
                    cubo.Back(ANTIORARIO);
                    break;
                case 6 + 4:
                    cubo.Left(ANTIORARIO);
                    break;
                case 6 + 5:
                    cubo.Down(ANTIORARIO);
                    break;
                default:
                    break;
                }
            }
        }

        for (int i = 0; i < array_dim; i++)
        {
            arrayButton[i].setChecked(false);
        }
        buttonReset.setChecked(false);
        if (mossa != -1)
            arrayButton[mossa].setChecked(true);
        else
            buttonReset.setChecked(true);

        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);
        //disegna qui...
        for (int i = 0; i < array_dim; i++)
        {
            arrayButton[i].draw(App);
        }
        buttonReset.draw(App);
        cubo.draw(App, 0.f, 0.f, lato, 10.f);
        //fine del frame corrente
        App.display();
    }
    //non dovrebbe mai raggiungere questo punto
    return EXIT;
}
