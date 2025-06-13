#include "button.h"




void button::update()
{
	if (CheckCollisionPointRec(GetMousePosition(), rect))
	{
		std::cout << "collision" << std::endl;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
		{
			enemigo* zombo = new enemigo({(float) GetRandomValue(1,800),(float)GetRandomValue(1,800)}, "Zombo1", LoadTexture("zombo.jpg"));
			GameObject::gameObjects.push_back(zombo);
			std::cout << "creando enemigo" << std::endl;
		}
	}
}

void button::draw()
{
	DrawRectangle(rect.x, rect.y, rect.width, rect.height, RAYWHITE);
	DrawText(text, rect.x, rect.y, fontSize, BLACK);
}