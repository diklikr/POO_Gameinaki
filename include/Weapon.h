#pragma once
#include "GameObject.h"
#include "Attacker.h"

namespace LoW
{
	class Player;
	class Weapon: public GameObject, public Attacker
	{
	public: 
		
		Player* owner;
		Vector2 offset;

		Weapon(Vector2 pos, std::string _name, Texture tex) :
			GameObject(pos, _name, tex)
		{
			owner = nullptr;
			offset = { 50.0f, 50.0f };
		}

		void Fire() override
		{
			std::cout << "Weapon fired!" << std::endl;
		}

		void update() override
		{
			
		}

		void draw() override
		{
			Rectangle r = { 0, 0, 64, 64 };
			DrawTextureRec(texture, r, position, WHITE);
		}
	};
}

