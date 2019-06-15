#include "MuliSdl.hpp"

MuliSdl::MuliSdl() {};
MuliSdl::~MuliSdl() {};

void MuliSdl::refresh(EventKeeper & ek)
{
	input.refresh(ek);
}

void	MuliSdl::drawObj(const std::list<Drawable const * const> & rhs)
{
	gui.drawObj(rhs);
}

void	MuliSdl::playSound(const int rhs)
{
	audio.play(rhs);
}

void	MuliSdl::render()
{
	gui.render();
}
