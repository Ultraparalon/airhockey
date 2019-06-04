#include "Logic.hpp"

Logic::Logic()
{
	table = Drawable(500, 250, TABLE);
	b_score = Drawable(250, 600, STRING, "0");
	p_score = Drawable(750, 600, STRING, "0");

	sound = 0;
}

void	Logic::process(unsigned int events, unsigned int coords)
{
	sound = 0;
	player.move(((coords >> 16) & 0xffff), (coords & 0xffff));
	bot.move(&puck);
	while (puck.collision(&player)) 
	{
		sound = 1;
	}
	while (puck.collision(&bot))
	{
		sound = 1;
	}
	puck.move();

	score();
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

const std::list<Drawable *> & Logic::getDrawable()
{
	drawObj.clear();
	drawObj.push_back(&table);
	drawObj.push_back(&player);
	drawObj.push_back(&bot);
	drawObj.push_back(&puck);
	drawObj.push_back(&b_score);
	drawObj.push_back(&p_score);
	return drawObj;
}

int	Logic::getSound()
{
	return sound;
}