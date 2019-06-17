#include "Gui.hpp"

static void	error(std::string err)
{
	std::cout << err << SDL_GetError() << std::endl;
	exit(1);
}

Gui::Gui()
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit(1);
	}
	request = SDL_GetDesktopDisplayMode(0, &displayMode);
	
	// fullscreen window
	// win = SDL_CreateWindow("Test", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
	
	win = SDL_CreateWindow("Test", 0, 0, 500, 1000, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		error("SDL_CreateWindow Error: ");
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		error("SDL_CreateRenderer Error: ");
	}

	// SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN); //fullscreen mode

	tFactory.init(ren); //init texture factory
}

Gui::~Gui()
{
	SDL_DestroyRenderer(ren); // destroy renderer & window
	SDL_DestroyWindow(win);
}

void	Gui::drawObj(const std::list<Drawable const * const> & rhs)
{
	// draw background
	std::shared_ptr<Texture> t(tFactory.createTexture(BACK));
	if (t != nullptr)
	{
		SDL_RenderCopy(ren, t->getTexture(), NULL, NULL);
	}

	// draw objects
	for (std::list<Drawable const * const>::const_iterator it = rhs.begin(); it != rhs.end(); it++)
	{
		t = std::shared_ptr<Texture>(tFactory.createTexture((*it)));
		if (t != nullptr)
		{
			SDL_RenderCopy(ren, t->getTexture(), NULL, t->getRect());
		}
	}
}

void	Gui::render()
{
	SDL_RenderPresent(ren);
}
