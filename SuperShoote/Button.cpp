#include "Button.h"
void BUTTON::Button::setName(std::string Name)
{
	this->name = Name;
	name += Const::ButtonIndent;
}
std::string BUTTON::Button::getName()
{
	return name;
}
;