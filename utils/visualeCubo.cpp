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

    //testo
    float dist = HEIGHT / 8;
    int charSize = HEIGHT / 20;
    float x_testo = 10.f, y_testo = 0.f, dist_testo = WIDTH / 4;
    sf::Font Font;
    sf::Text testo;
    ColoreRGB coloreTesto = ColoreRGB(255, 255, 255);

    //inizializzo il testo
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }

    //un punto adibito a mouse click
    Punto mouseClick;

    //esegui il programma finchè la finestra è aperta
    while (Running)
    {
        //controlla se qualche evento viene scatenato prima del prossimo loop
        while (App.pollEvent(event))
        {
            switch (event.type)
            {
            //se la finestra è stata chiusa
            case sf::Event::Closed:
                return EXIT;
                break;
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
        }

        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);

        //disegna qui...
        cubo.draw(App);
        //fine del frame corrente
        App.display();
    }
    //non dovrebbe mai raggiungere questo punto
    return EXIT;
}
