#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL.h>
#include <iostream>

class Input
{
	unsigned int events;
	unsigned int coordinates;
	SDL_Event event;

public:
	Input() : events(0), coordinates(0) {}
	~Input() {}

	unsigned int getEvents() const;
	unsigned int getCoordinates() const;

	void refresh();
	
};

#endif