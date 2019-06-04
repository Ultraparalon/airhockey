#ifndef MULISDL_HPP
#define MULISDL_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <list>
#include "Input.hpp"
#include "Drawable.hpp"

class MuliSdl
{
	int request;
	SDL_DisplayMode displayMode;
	SDL_Window *win;
	SDL_Renderer *ren;
	Input input;

	std::vector<SDL_Texture *> textures;


public:
	MuliSdl();
	~MuliSdl();

	unsigned int getEvents() const {return input.getEvents();};
	unsigned int getCoordinates() const {return input.getCoordinates();};

	void refresh() {input.refresh(); };
	void render(const std::list<Drawable *> &);
	
};

#endif