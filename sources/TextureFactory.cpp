#include "TextureFactory.hpp"
#include <iostream>

TextureFactory::TextureFactory()
{
	TTF_Init();

	color = {0x0f, 0x0f, 0x0f, 0x7f};

	defFont = TTF_OpenFont("resources/fonts/test.ttf", 48);
	if (!defFont)
	{
		std::cout << TTF_GetError() << std::endl;
		exit(1);
	}
}

TextureFactory::~TextureFactory()
{
	if (defFont != nullptr)
		TTF_CloseFont(defFont);

	for (std::vector<SDL_Texture *>::iterator it = textures.begin();
		it != textures.end(); it++)
	{
		SDL_DestroyTexture(*it);
	}
}

static SDL_Texture * loadtxr(SDL_Renderer * ren, std::string path)
{
	SDL_Texture * ret = IMG_LoadTexture(ren, path.c_str());
	if (ret == nullptr)
	{
		std::cout << "Couldn't load texture from: " << path << std::endl;
		exit(1);
	}
	return ret;
}

void	TextureFactory::init(SDL_Renderer * rhs)
{
	ren = rhs;

	textures.push_back(loadtxr(ren, "resources/textures/table.png"));
	textures.push_back(loadtxr(ren, "resources/textures/player.png"));
	textures.push_back(loadtxr(ren, "resources/textures/enemy.png"));
	textures.push_back(loadtxr(ren, "resources/textures/puck.png"));
	textures.push_back(loadtxr(ren, "resources/textures/background.jpg"));
}

Texture * TextureFactory::createTexture(Drawable * rhs)
{
	SDL_Texture * texture;
	SDL_Rect rect;

	if (rhs->getTexture() == STRING)
	{
		SDL_Surface *surf = TTF_RenderText_Solid(defFont,
			rhs->getName().c_str(), color);
		texture = SDL_CreateTextureFromSurface(ren, surf);
		SDL_FreeSurface(surf);
	}
	else
	{
		texture = textures[rhs->getTexture()];		
	}

	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

	rect.y = rhs->getPosY() - rect.h / 2;
	rect.x = rhs->getPosX() - rect.w / 2;

	return new Texture(texture, rect);
}

Texture * TextureFactory::createTexture(int rhs)
{
	SDL_Texture * texture;
	SDL_Rect rect;

	texture = textures[rhs];

	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	rect.y = 0;
	rect.x = 0;

	return new Texture(texture, rect);
}
