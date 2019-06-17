//all game logic is here
//

#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <list>
#include "Drawable.hpp"
#include "Player.hpp"
#include "Bot.hpp"
#include "Puck.hpp"
#include "Table.hpp"
#include "EventKeeper.hpp"

class Logic
{
	int sound;

	Table table;
	Player player;
	Bot bot;
	Puck puck;
	Drawable p_score;
	Drawable b_score;

	std::list<Drawable const * const> drawObj;

public:
	Logic();
	~Logic();

	const std::list<Drawable const * const> & getDrawable();
	int getSound();

	void	process(const EventKeeper &);
	void	score();

};

#endif
