//visuale pianeta header
#ifndef VISUALE_PIANETA_HPP
#define VISUALE_PIANETA_HPP

#include <iostream>

#include "./cScreen.hpp"
#include "./Cubo.hpp"
#include "./Button.hpp"

class visualeCubo : public cScreen
{
private:
public:
	visualeCubo(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_PIANETA_HPP
