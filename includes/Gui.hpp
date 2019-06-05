#ifndef GUI_HPP
#define GUI_HPP

#include <SDL.h>
#include <iostream>
#include <list>
#include "Drawable.hpp"
#include "TextureFactory.hpp"

class Gui
{
	int request;
	SDL_DisplayMode displayMode;
	SDL_Window *win;
	SDL_Renderer *ren;

	TextureFactory tFactory;

public:
	Gui();
	~Gui();

	void drawObj(const std::list<Drawable *> &);
	void render();
	
};

#endif