#ifndef EVENTKEEPER_HPP
#define EVENTKEEPER_HPP

class EventKeeper
{
	bool exit;

	bool lmb;
	bool rmb;
	int mouseY;
	int mouseX;

public:
	EventKeeper();
	~EventKeeper();

	void setExit(const bool);
	void setLMB(const bool);
	void setRMB(const bool);
	void setMouseY(const int);
	void setMouseX(const int);

	bool getExit() const;
	bool getLMB() const;
	bool getRMB() const;
	int getMouseY() const;
	int getMouseX() const;

};

#endif