#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <list>
#include "Drawable.hpp"
#include "Player.hpp"
#include "Puck.hpp"

class Logic
{
	std::list<Drawable *> drawObj;
	Drawable table;
	Player player;
	Drawable bot;
	Puck puck;

public:
	Logic();
	~Logic() {};

	void	process(unsigned int, unsigned int);

	const std::list<Drawable *> & getDrawable();
};

#endif

//bot atributes
//speed

//puck atributes
//power //max power 16-24
//distance
//destanation //y, x
