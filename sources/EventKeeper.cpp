#include "EventKeeper.hpp"

EventKeeper::EventKeeper() : exit(false), lmb(false),
						rmb(false), mouseY(0), mouseX(0) {}
EventKeeper::~EventKeeper() {}

//Setters-------------------------------------
void EventKeeper::setExit(const bool rhs)
{
	exit = rhs;
}

void EventKeeper::setLMB(const bool rhs)
{
	lmb = rhs;
}

void EventKeeper::setRMB(const bool rhs)
{
	lmb = rhs;
}

void EventKeeper::setMouseY(const int rhs)
{
	mouseY = rhs;
}

void EventKeeper::setMouseX(const int rhs)
{
	mouseX = rhs;
}

//Getters--------------------------------------
bool EventKeeper::getExit() const
{
	return exit;
}

bool EventKeeper::getLMB() const
{
	return lmb;
}

bool EventKeeper::getRMB() const
{
	return rmb;
}

int EventKeeper::getMouseY() const
{
	return mouseY;
}

int EventKeeper::getMouseX() const
{
	return mouseX;
}
