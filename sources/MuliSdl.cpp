#include "MuliSdl.hpp"

void	MuliSdl::playSound(int rhs)
{
	audio.play(rhs);
}

void	MuliSdl::drawObj(const std::list<Drawable *> & rhs)
{
	gui.drawObj(rhs);
}

// void	MuliSdl::drawStr(const std::list<std::string> & rhs)
// {
// 	gui.drawStr(rhs);
// }

void	MuliSdl::render()
{
	gui.render();
}
