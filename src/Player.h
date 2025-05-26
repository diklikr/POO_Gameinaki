#pragma once
#include "GameObject.h"
#include <iostream>
#include "Attacker.h"
#include "Weapon.h"
#include "Sidekick.h"


namespace LoW
{
	enum EAnimDirection
	{
		ANIM_DOWN,
		ANIM_UP,
		ANIM_LEFT,
		ANIM_RIGHT
	};

	struct SAnimData
	{
		int currentFrame;
		int maxFrames;
		int frameCounter;
		int frameSpeed = 10;
		float spriteWidth;
		float spriteHeight;
		EAnimDirection direction;
	};

	class Player :
		public GameObject, public Attacker
	{
	private: 
		SAnimData animData;

		Attacker* weapon;

	public:
		float speed = 10.0f;

		Player(Vector2 pos, std::string _name) :
			weapon(nullptr) 
		{
			texture = LoadTexture("boy.png")
			animData.spriteHeight = 80;
			animData.spriteWidth = 64;
			animData.frameCounter = 0;
			animData.currentFrame = 0;
			animData.maxFrames = 4;
			animData.frameSpeed = 5;
			name = _name;
			position = pos;
			animData.direction = ANIM_DOWN;
		}

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
}

