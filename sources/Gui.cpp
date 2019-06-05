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

	// SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);

	tFactory.init(ren);
}

Gui::~Gui()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
}

void	Gui::drawObj(const std::list<Drawable *> & rhs)
{
	std::shared_ptr<Texture> t(tFactory.createTexture(BACK));

	SDL_RenderCopy(ren, t->getTexture(), NULL, NULL);

	for (std::list<Drawable *>::const_iterator it = rhs.begin(); it != rhs.end(); it++)
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
