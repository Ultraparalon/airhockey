//reads input changes
//sends all key that are downed
//and mouse coordinates

#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL.h>
#include <iostream>
#include "EventKeeper.hpp"

enum eState
{
	OFF,
	ON
};

class Input
{
	SDL_Event event;

public:
	Input();
	~Input();

	void refresh(EventKeeper &);
	
};

#endif