#pragma once
#include "Inclusion.h"

namespace Input
{
	void update();
	bool pressed(const Keyboard::Key &key);
	bool wait();
}