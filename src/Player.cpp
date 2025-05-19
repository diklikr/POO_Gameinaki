#include "Player.h"
#include "Attacker.h"
#include <iostream>
#include "Weapon.h"

using namespace LoW;




	void Player::update()
	{
		if (IsKeyDown(KEY_A))
		{
			position.x -= speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_D))
		{
			position.x += speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_W))
		{
			position.y -= speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S))
		{
			position.y += speed * GetFrameTime();
		}
	}

	void Player::Fire()
	{

	}

	Attacker* Player::SetWeapon(Attacker* newWeapon)
	{
		if (newWeapon)
		{
			weapon = newWeapon;
			Weapon* w = dynamic_cast<Weapon*>(weapon);
			if (w)
				std::cout << "Cambiando Arma a " << w->name << std::endl;

			return weapon;
		}
		return nullptr;
	}
