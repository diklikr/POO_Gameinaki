#include "GameObject.h"

void GameObject::update()
{
}

void GameObject::draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);

	if (displayName)
	{
		DrawText(name.c_str(), position.x, position.y - 20, 10, YELLOW);
	}

}
