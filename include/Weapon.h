#pragma once
#include "GameObject.h"

namespace LoW
{
	//class Player;
	class Weapon: public GameObject, public Attacker
	{
	public: 
		
		Player * owner;
		Vector2 offset;

		Weapon(Vector2 pos, std::string _name, Texture tex) :
			GameObject(pos, _name, tex)
		{
			offset = { 50.0f, 50.0f };
		}

		void Fire() override
		{
			std::cout << "Weapon fired!" << std::endl;
		}

		void update() override
		{
			
		}
	};
}

