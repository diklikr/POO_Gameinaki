#pragma once
#include "GameObject.h"
#include <iostream>
class Player:
	public GameObject
{
public:
	float speed = 10.0f;

	Player(Vector2 pos, std::string _name, Texture tex) :
		GameObject(pos, _name, tex) {}

	void update() override;

	void attack()
		{
			std::cout << name << "Atacando" << std::endl;
		}
};

