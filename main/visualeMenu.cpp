#include "../header/visualeMenu.hpp"

extern float WIDTH, HEIGHT;

visualeMenu::visualeMenu(void)
{
}

int visualeMenu::Run(sf::RenderWindow &App)
{
    float dist = HEIGHT / 6;
    int charSize = HEIGHT / 10;
    float x = WIDTH / 4;
    float y = HEIGHT / 3;
    //colore del testo
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);

    sf::Event event;
    bool Running = true;
    sf::Font Font;
    sf::Text testo;
    int menu = 0;

    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }

    testo.setFont(Font);
    testo.setCharacterSize(charSize);
    testo.setString("RubikCube");
    testo.setPosition({x, y - dist});
#ifndef NON_FUNZIONA_FILL_COLOR
    testo.setFillColor(coloreTesto.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
    testo.setColor(coloreTesto.getColorLib());
#endif
    //bottoni
    Button buttonPlay = Button(x, y, "Play");
    Button buttonExit = Button(x, y + dist, "Exit");

    //un punto adibito a mouse click
    Punto mouseClick;
    while (Running)
    {
        //verifica gli eventi
        while (App.pollEvent(event))
        {
            switch (event.type)
            {
            //finestra chiusa
            case sf::Event::Closed:
                return EXIT;
                break;
            //mouse
            case sf::Event::MouseButtonPressed:
                mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                //verifico se è stato premuto un bottone
                if (buttonExit.checkMouse(mouseClick))
                {
                    //fine dei giochi, si torna a lavoro...
                    return EXIT;
                }
                else if (buttonPlay.checkMouse(mouseClick))
                {
                    //giochiamo!
                    return VISUALE_CUBO;
                }
                break;
            //tastiera
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                //tasto Esc
                case sf::Keyboard::Escape:
                    return EXIT;
                    break;
                //freccie su giù
                case sf::Keyboard::Up:
                    if(menu > 0)
                        menu--;
                    else
                        menu = 1;
                    break;
                case sf::Keyboard::Down:
                    if(menu < 1)
                        menu++;
                    else
                        menu = 0;
                    break;
                //tasto enter
                case sf::Keyboard::Return:
                    switch(menu)
                    {
                    case 0:
                        return VISUALE_CUBO; 
                        break;
                    case 1:
                        return EXIT;
                        break;
                    default:
                        cout << "menuError" << endl;
                        break;
                    }
                default:
                    break;
                }
            default:
                break;
            }
        }
        switch (menu)
        {
        case 0:
            //prima linea focalizzata
            buttonPlay.setChecked(true);
            //terza
            buttonExit.setChecked(false);
            break;
        case 1:
            //prima
            buttonPlay.setChecked(false);
            //terza
            buttonExit.setChecked(true);
            break;
        default:
            cout << "menuError" << endl;
            break;
        }

        //pulisco lo schermo
        App.clear();
        
        //disegno
        App.draw(testo);
        buttonPlay.draw(App);
        buttonExit.draw(App);
        //mostro
        App.display();
    }

    //non dovrebbe mai raggiungere questo
    return EXIT;
}
