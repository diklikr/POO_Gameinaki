#pragma once
#include "GameObject.h"

using namespace LoW;

class enemigo : public GameObject
{
public:

	enemigo(Vector2 pos, std::string _name, Texture tex) :
		GameObject(pos, _name, tex)
	{

	}
};