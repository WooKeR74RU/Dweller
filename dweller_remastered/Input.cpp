#include "Input.h"

array<bool, Keyboard::KeyCount> press;
array<bool, Keyboard::KeyCount> prevKeyStatus;

void Input::update()
{
	for (int i = 0; i < Keyboard::KeyCount; i++)
	{
		if (prevKeyStatus[i] && !Keyboard::isKeyPressed(Keyboard::Key(i)))
			press[i] = 1;
		else
			press[i] = 0;
		prevKeyStatus[i] = Keyboard::isKeyPressed(Keyboard::Key(i));
	}
}

bool Input::pressed(const Keyboard::Key &key)
{
	return press[key];
}

array<Keyboard::Key, 9> controls = { Keyboard::Q, Keyboard::W, Keyboard::E, Keyboard::A,
Keyboard::S, Keyboard::D, Keyboard::Z, Keyboard::X, Keyboard::C };
bool Input::wait()
{
	for (int i = 0; i < controls.size(); i++)
	{
		if (pressed(controls[i]))
			return 0;
	}
	return 1;
}