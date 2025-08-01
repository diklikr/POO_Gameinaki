#include "Player.h"
#include "World.h"


using namespace LoW;




void Player::update()
{

	Vector2 newpos;
	newpos = position;
	if (IsKeyDown(KEY_A))
	{
		newpos.x -= speed * GetFrameTime();
		animData.direction = ANIM_LEFT;
	}
	if (IsKeyDown(KEY_D))
	{
		newpos.x += speed * GetFrameTime();
		animData.direction = ANIM_RIGHT;
	}
	if (IsKeyDown(KEY_W))
	{
		newpos.y -= speed * GetFrameTime();
		animData.direction = ANIM_UP;
	}
	if (IsKeyDown(KEY_S))
	{
		newpos.y += speed * GetFrameTime();
		animData.direction = ANIM_DOWN;
    }
	if (!World::getInstance().CheckCollision(newpos))
	{
		position = newpos;
	}

		animData.frameCounter++;
		
		if (animData.frameCounter > animData.frameSpeed)
		{
			animData.frameCounter = 0;
			animData.currentFrame++;

			if (animData.currentFrame >= animData.maxFrames)
				animData.currentFrame = 0;

			/*std::cout << "Frame: " << animData.currentFrame << std::endl;*/
		}

		
		if (weapon)
		{
			Weapon* w = dynamic_cast<Weapon*>(weapon);
			w->position = Vector2Add(position, w->offset);
				
		}
		for (GameObject* obj : GameObject::gameObjects)
		{
			Weapon* w = dynamic_cast<Weapon*>(obj);
			if (w && w->owner == nullptr &&
				CheckCollisionRecs({ position.x, position.y, animData.spriteWidth, animData.spriteHeight },
					{ w->position.x, w->position.y, 64, 64 }))
			{
				//std::cout << "Colision con arma: " << w->name << std::endl;
				shouldPromptForWeapon = true;

				if (IsKeyPressed(KEY_F))
				{
					SetWeapon(w);
					shouldPromptForWeapon = false;
				}

				break;
			}
			else
				shouldPromptForWeapon = false;
		}
	}


	void Player::draw()
	{
		Rectangle r = { animData.spriteWidth * animData.currentFrame ,
						animData.spriteHeight * animData.direction,
						animData.spriteWidth,
						animData.spriteHeight };
		DrawTextureRec(texture, r, position, WHITE);
		//DrawTexture(texture, position.x, position.y, WHITE);

		if (shouldPromptForWeapon)
			DrawText(weaponPrompt, 20, GetScreenHeight() - 40, 20, YELLOW);
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
			{
				w->owner = this;
				std::cout << "Cambiando Arma a " << w->name << std::endl;
			}

			return weapon;
		}
		return nullptr;
	}

	void Player::SetSidekick(Sidekick* newSidekick, int index)
	{
		if (index >= 0 && index < 3)
		{
			newSidekick->owner = this;
			sidekicks[index] = newSidekick;
		}
		else
		{
			std::cout << "Indice de sidekick invalido" << std::endl;
		}
	}