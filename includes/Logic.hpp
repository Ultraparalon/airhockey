#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <list>
#include "Drawable.hpp"
#include "Player.hpp"
#include "Bot.hpp"
#include "Puck.hpp"

class Logic
{
	std::list<Drawable *> drawObj;
	int sound;

	Drawable table;
	Player player;
	Bot bot;
	Puck puck;
	Drawable p_score;
	Drawable b_score;

public:
	Logic();
	~Logic() {};

	const std::list<Drawable *> & getDrawable();
	int getSound();

	void	process(unsigned int, unsigned int);
	void	score();

};

#endif
