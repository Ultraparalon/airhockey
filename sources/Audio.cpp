#include "Audio.hpp"

static void	error(std::string err)
{
	std::cout << err << SDL_GetError() << std::endl;
	exit(1);
}

Audio::Audio()
{
	if (SDL_Init(SDL_INIT_AUDIO))
	{
		error("Can't init audio");
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1)
	{
		error("Cannot open audio");
	}

	kick = Mix_LoadWAV("resources/sounds/kick.wav");
	if (kick == nullptr)
	{
		error("Couldn't load kick");
	}
}

Audio::~Audio()
{
	Mix_FreeChunk(kick);
}

void	Audio::play(int rhs)
{
	if (rhs)
	{
		Mix_PlayChannel(-1, kick, 0);
	}
}
