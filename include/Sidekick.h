#pragma once
#include "GameObject.h"

#include "raymath.h"
#include <iostream>
#include "GameObject.h"

namespace LoW
{
	class Sidekick :public GameObject
	{
	public:
		float speed = 100;
		GameObject* owner;

		Sidekick(Vector2 pos, std::string _name, Texture tex) :
			owner(nullptr),
			GameObject(pos, _name, tex) {

		}
		void update();

		void attack()
		{
			std::cout << name << "Atacando" << std::endl;
		}

		void flee()
		{
			std::cout << name << "Huye como cobarde" << std::endl;
		}
	};
}

