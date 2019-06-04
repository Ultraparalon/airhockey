#include "Input.hpp"

unsigned int Input::getEvents() const 		{	return events;		}
unsigned int Input::getCoordinates() const	{	return coordinates;	}

static unsigned int keyaction(const unsigned short key)
{
	switch (key)
	{
		case SDLK_ESCAPE:	return (1 << 9);
		default: return 0;
	}
}

static unsigned int mouseaction(const unsigned short button)
{
	switch (button)
	{
		case SDL_BUTTON_LEFT: return 1;
		case SDL_BUTTON_RIGHT: return (1 << 2);
		default: return 0;
	}
}

void	Input::refresh()
{
	while (SDL_PollEvent(&event))
	{
		SDL_PumpEvents();

		switch (event.type)
		{
			case SDL_MOUSEMOTION:
				coordinates = (event.motion.y << 16) + event.motion.x;
				break;
			case SDL_MOUSEBUTTONDOWN:
				events |= mouseaction(event.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				events &= ~(mouseaction(event.button.button));
				break;
			case SDL_KEYDOWN:
				events |= keyaction(event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				events &= ~(keyaction(event.key.keysym.sym));
				break;
			case SDL_QUIT:
				events |= (1 << 9);
				break;
		}
	}
}
