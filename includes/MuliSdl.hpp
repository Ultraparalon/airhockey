//multimedia object
//that contains video audio and input
//redirects signals and containers

#ifndef MULISDL_HPP
#define MULISDL_HPP

#include <list>
#include "Gui.hpp"
#include "Input.hpp"
#include "Audio.hpp"
#include "Drawable.hpp"
#include "EventKeeper.hpp"

class MuliSdl
{
	Gui gui;
	Input input;
	Audio audio;

public:
	MuliSdl();
	~MuliSdl();

	void refresh(EventKeeper &);
	void drawObj(const std::list<Drawable const * const> &);
	void playSound(const int);
	void render();
	
};

#endif