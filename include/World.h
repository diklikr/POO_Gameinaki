#pragma once
#include "raylib.h"
#include <iostream>

namespace LoW
{
	class World
	{
	private: 
		static World* instance;
		World() = default;
		World(const World&) = delete;
		World& operator=(const World&) = delete;

	public:
		Texture background;
		Image collisionMask;

		unsigned char* collisionMaskdata;

		static World& getInstance()
		{
			if (!instance) 
			{
				instance = new World();
				instance->World1();
			}
			return *instance;
		}

		void World1() 
		{
			background = LoadTexture("world1.jpg");
			collisionMask = LoadImage("world1_mask.png");
			ImageFormat(&collisionMask, PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);
			collisionMaskdata = (unsigned char*)collisionMask.data;

		}

		void Draw()
		{
			DrawTexture(background, 0, 0, WHITE);
		}

		bool CheckCollision(Vector2 point)
		{
			int index = (point.y * collisionMask.width + point.x);


			/*std::cout << "valor en pixel: " << point.x << "," << point.y << "," << std::hex << collisionMaskdata[index] << std::endl;*/

			return collisionMaskdata[index] != 0;
		}

	};

}