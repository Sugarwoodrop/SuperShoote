#pragma once
#include <iostream>
#include "Const.h"

namespace BUTTON {
	class Button
	{
	private:
		std::string name;
	public:
		virtual ~Button() = default;
		void virtual onClick() const = 0;

		void setName(std::string Name);
		std::string getName();
	};
}

