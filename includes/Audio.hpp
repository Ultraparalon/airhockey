#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class Audio
{
	Mix_Chunk * kick;

public:
	Audio();
	~Audio();

	void play(int);
	
};

#endif