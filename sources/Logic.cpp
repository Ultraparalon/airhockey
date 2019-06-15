#include "Logic.hpp"

Logic::Logic()
{
	table = Drawable(500, 250, TABLE);
	b_score = Drawable(250, 250, STRING, "0");
	p_score = Drawable(750, 250, STRING, "0");

	sound = 0;

	drawObj.push_back(&table);
	drawObj.push_back(&player);
	drawObj.push_back(&bot);
	drawObj.push_back(&puck);
	drawObj.push_back(&b_score);
	drawObj.push_back(&p_score);
}

void	Logic::process(const EventKeeper & ek)
{
	sound = 0;
	player.move(ek.getMouseY(), ek.getMouseX());
	bot.move(&puck);
	while (puck.collision(&player)) //check collisiion of puck with player
	{
		sound = 1;
	}
	while (puck.collision(&bot)) // and bot
	{
		sound = 1;
	}
	puck.move();

	score(); // detects score changes
}

void	Logic::score()
{
	if (puck.getPosY() < 0)
	{
		player.addPoint();
		p_score.setName(std::to_string(player.getScore()));
		puck = Puck(250, 250);
		bot.setPosY(150);
		bot.setPosX(150);
	}
	if (puck.getPosY() > 1000)
	{
		bot.addPoint();
		b_score.setName(std::to_string(bot.getScore()));
		puck = Puck(750, 250);
	}
}

//return container with objects to draw on screen
const std::list<Drawable const * const> & Logic::getDrawable()
{
	return drawObj;
}

//return signal to play sound
int	Logic::getSound()
{
	return sound;
}