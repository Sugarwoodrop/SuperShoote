#include "ButtonExit.h"

Exit::ButtonExit::ButtonExit(std::string Name)
{

	setName(Name);
};
void Exit::ButtonExit::onClick() const
{
	exit(0);
};
