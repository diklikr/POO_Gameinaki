#pragma once
#include "GameObject.h"
#include <iostream>
#include "Attacker.h"


using namespace LoW;

class Player :
	public GameObject, public Attacker
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

	void Fire();

	Attacker* SetWeapon(Attacker* newWeapon);

private: 
	Attacker* weapon;
};

