#include "MuliSdl.hpp"

void	MuliSdl::playSound(const int rhs)
{
	audio.play(rhs);
}

void	MuliSdl::drawObj(const std::list<Drawable const * const> & rhs)
{
	gui.drawObj(rhs);
}

void	MuliSdl::render()
{
	gui.render();
}
