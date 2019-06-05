#include "Audio.hpp"

static void	error(const std::string err)
{
	std::cout << err << SDL_GetError() << std::endl;
	exit(1);
}

Audio::Audio()
{
	if (SDL_Init(SDL_INIT_AUDIO)) //init
	{
		error("Can't init audio");
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1) //open audio channel
	{
		error("Cannot open audio");
	}

	kick = Mix_LoadWAV("resources/sounds/kick.wav"); // sound of drum kick
	if (kick == nullptr)
	{
		error("Couldn't load kick");
	}
}

Audio::~Audio()
{
	Mix_FreeChunk(kick); // destroy wav source
}

void	Audio::play(const int rhs)
{
	if (rhs)
	{
		Mix_PlayChannel(-1, kick, 0);
	}
}
