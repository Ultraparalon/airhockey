#include "Input.hpp"

Input::Input() {};
Input::~Input() {};

static void keyaction(EventKeeper & ek,
	const unsigned short key, const bool state)
{
	switch (key)
	{
		case SDLK_ESCAPE:
			ek.setExit(state);
			break;
	}
}

static void mouseaction(EventKeeper & ek,
	const unsigned short button, const bool state)
{
	switch (button)
	{
		case SDL_BUTTON_LEFT:
			ek.setLMB(state);
			break;
		case SDL_BUTTON_RIGHT:
			ek.setRMB(state);
			break;
	}
}

void	Input::refresh(EventKeeper & ek)
{
	while (SDL_PollEvent(&event)) // read all input events
	{
		SDL_PumpEvents();

		switch (event.type)
		{
			case SDL_MOUSEMOTION: //mouse coords
				ek.setMouseY(event.motion.y);
				ek.setMouseX(event.motion.x);
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseaction(ek, event.button.button, ON);
				break;
			case SDL_MOUSEBUTTONUP:
				mouseaction(ek, event.button.button, OFF);
				break;
			case SDL_KEYDOWN:
				keyaction(ek, event.key.keysym.sym, ON);
				break;
			case SDL_KEYUP:
				keyaction(ek, event.key.keysym.sym, OFF);
				break;
			case SDL_QUIT:
				keyaction(ek, SDLK_ESCAPE, ON);
				break;
		}
	}
}
