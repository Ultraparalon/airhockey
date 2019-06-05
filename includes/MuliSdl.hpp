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

class MuliSdl
{
	Gui gui;
	Input input;
	Audio audio;

public:
	MuliSdl() {};
	~MuliSdl() {};

	unsigned int getEvents() const {return input.getEvents();};
	unsigned int getCoordinates() const {return input.getCoordinates();};

	void refresh() {input.refresh(); };
	void drawObj(const std::list<Drawable const * const> &);
	void render();
	void playSound(const int);
	
};

#endif