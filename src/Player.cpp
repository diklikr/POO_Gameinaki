#include "Player.h"

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