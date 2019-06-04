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
	
	win = SDL_CreateWindow("Test", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		error("SDL_CreateWindow Error: ");
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		error("SDL_CreateRenderer Error: ");
	}
	SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);

	TTF_Init();
	defFont = TTF_OpenFont("resources/fonts/defFont.ttf", 48);

	textures.push_back(IMG_LoadTexture(ren, "resources/textures/table.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/player.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/enemy.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/puck.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/background.jpg"));
}

Gui::~Gui()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	TTF_CloseFont(defFont);
	//destoy textures
}

void	Gui::drawObj(const std::list<Drawable *> & rhs)
{
	SDL_Rect rect;

	SDL_RenderCopy(ren, textures.back(), NULL, NULL);
	for (std::list<Drawable *>::const_iterator it = rhs.begin(); it != rhs.end(); it++)
	{
		if ((*it)->getTexture() == STRING)
		{
			continue;
		}
		SDL_QueryTexture(textures[(*it)->getTexture()],
			NULL, NULL, &rect.w, &rect.h);
		rect.y = (*it)->getPosY() - rect.h / 2;
		rect.x = (*it)->getPosX() - rect.w / 2;
		SDL_RenderCopy(ren, textures[(*it)->getTexture()], NULL, &rect);
	}
}

void	Gui::render()
{
	SDL_RenderPresent(ren);
}
