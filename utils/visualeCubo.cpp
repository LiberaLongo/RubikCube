#include "../header/visualeCubo.hpp"

extern float WIDTH, HEIGHT;

//pubbliche
visualeCubo::visualeCubo(void)
{
}

int visualeCubo::Run(sf::RenderWindow &App)
{
    Cubo cubo = Cubo();
    //comincia la trattazione della finestra
    bool Running = true;
    sf::Event event;

    //bottoni
    int mossa = -1;
    float x_or = WIDTH / 2, y_or = 0.f;
    float sizeB = min(WIDTH / 4, HEIGHT / 3) / 4;
    float x_anti = WIDTH *3/4, y_anti = 0.f;
    //bottoni senso orario
    Button buttonFront = Button(x_or + 1 * sizeB, y_or + 2 * sizeB, "F", sizeB);
    Button buttonRight = Button(x_or + 2 * sizeB, y_or + 1 * sizeB, "R", sizeB);
    Button buttonUp = Button(x_or + 3 * sizeB, y_or + 1 * sizeB, "U", sizeB);
    Button buttonBack = Button(x_or + 1 * sizeB, y_or + 0 * sizeB, "B", sizeB);
    Button buttonLeft = Button(x_or + 0 * sizeB, y_or + 1 * sizeB, "L", sizeB);
    Button buttonDown = Button(x_or + 1 * sizeB, y_or + 1 * sizeB, "D", sizeB);
    //bottoni senso antiorario
    Button buttonFront_anti = Button(x_anti + 1 * sizeB, y_anti + 2 * sizeB, "F'", sizeB);
    Button buttonRight_anti = Button(x_anti + 2 * sizeB, y_anti + 1 * sizeB, "R'", sizeB);
    Button buttonUp_anti = Button(x_anti + 3 * sizeB, y_anti + 1 * sizeB, "U'", sizeB);
    Button buttonBack_anti = Button(x_anti + 1 * sizeB, y_anti + 0 * sizeB, "B'", sizeB);
    Button buttonLeft_anti = Button(x_anti + 0 * sizeB, y_anti + 1 * sizeB, "L'", sizeB);
    Button buttonDown_anti = Button(x_anti + 1 * sizeB, y_anti + 1 * sizeB, "D'", sizeB);
    
    //vettore di bottoni
    Button arrayButton[] = {buttonFront, buttonRight, buttonUp, buttonBack, buttonLeft, buttonDown,
        buttonFront_anti, buttonRight_anti, buttonUp_anti, buttonBack_anti, buttonLeft_anti, buttonDown_anti};
    int array_dim = sizeof(arrayButton)/sizeof(arrayButton[0]);
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
                    cubo.Front();
                    break;
                case 1:
                    cubo.Right();
                    break;
                case 2:
                    cubo.Up();
                    break;
                case 3:
                    cubo.Back();
                    break;
                case 4:
                    cubo.Left();
                    break;
                case 5:
                    cubo.Down();
                    break;                
                case 6+0:
                    cubo.Front_anti();
                    break;
                case 6+1:
                    cubo.Right_anti();
                    break;
                case 6+2:
                    cubo.Up_anti();
                    break;
                case 6+3:
                    cubo.Back_anti();
                    break;
                case 6+4:
                    cubo.Left_anti();
                    break;
                case 6+5:
                    cubo.Down_anti();
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
        if(mossa != -1)
            arrayButton[mossa].setChecked(true);
        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);
        //disegna qui...
        for (int i = 0; i < array_dim; i++)
        {
            arrayButton[i].draw(App);
        }
        cubo.draw2D(App);
        //fine del frame corrente
        App.display();
    }
    //non dovrebbe mai raggiungere questo punto
    return EXIT;
}
