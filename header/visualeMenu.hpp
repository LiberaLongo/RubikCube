#ifndef VISUALE_MENU_HPP
#define VISUALE_MENU_HPP

#include <iostream>

#include "cScreen.hpp"

#include "./Button.hpp"

class visualeMenu : public cScreen
{
private:
	bool playing = false;

public:
	visualeMenu(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_MENU_HPP
