#ifndef GUI_HPP
#define GUI_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <list>
#include "Drawable.hpp"

class Gui
{
	int request;
	SDL_DisplayMode displayMode;
	SDL_Window *win;
	SDL_Renderer *ren;

	TTF_Font * defFont;

	std::vector<SDL_Texture *> textures;

public:
	Gui();
	~Gui();

	void drawObj(const std::list<Drawable *> &);
	void drawStr(const std::list<std::string> &) {};
	void render();
	
};

#endif