#include "Logic.hpp"

Logic::Logic()
{
	table = Drawable(500, 250, TABLE);
	bot = Drawable(10, 20, ENEMY);
}

void	Logic::process(unsigned int events, unsigned int coords)
{
	player.move(((coords >> 16) & 0xffff), (coords & 0xffff));
	puck.collision(&player);
	puck.move();
	//check collisions
	//more closer points, more power of kick

	//player movement

	//puck movement

	//bot movement
}

const std::list<Drawable *> & Logic::getDrawable()
{
	drawObj.clear();
	drawObj.push_back(&table);
	drawObj.push_back(&player);
	drawObj.push_back(&bot);
	drawObj.push_back(&puck);
	return drawObj;
}