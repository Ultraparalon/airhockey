//all game logic is here
//

#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <list>
#include "Drawable.hpp"
#include "Player.hpp"
#include "Bot.hpp"
#include "Puck.hpp"

class Logic
{
	std::list<Drawable const * const> drawObj;
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

	const std::list<Drawable const * const> & getDrawable();
	int getSound();

	void	process(unsigned int, unsigned int);
	void	score();

};

#endif
