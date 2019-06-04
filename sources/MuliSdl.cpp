#include "MuliSdl.hpp"

static void	error(std::string err)
{
	std::cout << err << SDL_GetError() << std::endl;
	exit(1);
}

MuliSdl::MuliSdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		error("SDL_Init Error: ");
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

	textures.push_back(IMG_LoadTexture(ren, "resources/textures/table.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/player.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/enemy.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/puck.png"));
	textures.push_back(IMG_LoadTexture(ren, "resources/textures/background.jpg"));
}

MuliSdl::~MuliSdl()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
}

void	MuliSdl::render(const std::list<Drawable *> & rhs)
{
	SDL_Rect rect;

	SDL_RenderCopy(ren, textures.back(), NULL, NULL);
	for (std::list<Drawable *>::const_iterator it = rhs.begin(); it != rhs.end(); it++)
	{
		SDL_QueryTexture(textures[(*it)->getTexture()],
			NULL, NULL, &rect.w, &rect.h);
		rect.y = (*it)->getPosY() - rect.h / 2;
		rect.x = (*it)->getPosX() - rect.w / 2;
		SDL_RenderCopy(ren, textures[(*it)->getTexture()], NULL, &rect);
	}
	// rect.y = 0;
	// rect.x = 0;
	// SDL_RenderCopy(ren, textures[0], NULL, &rect);
	// SDL_QueryTexture(textures[1], NULL, NULL, &rect.w, &rect.h);
	// rect.y = displayMode.h / 2 - rect.h / 2;
	// rect.x = displayMode.w / 2 - rect.w / 2;
	// SDL_RenderCopy(ren, textures[1], NULL, &rect);
	SDL_RenderPresent(ren);

}
