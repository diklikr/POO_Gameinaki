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
			background = LoadTexture("world1.png");
			collisionMask = LoadImage("world1_mask.png");
			ImageFormat(&collisionMask, PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);

		}

		void Draw()
		{
			DrawTexture(background, 0, 0, WHITE);
		}

		bool CheckCollision(Vector2 point)
		{
			int index = (point.y * collisionMask.width + point.x);
		   
			char* imgdata = (char*)collisionMask.data;

			std::cout << "valor en pixel: " << point.x << "," << point.y << "," << (int)imgdata[index] << std::endl;

			return (imgdata[index] != 0);
		}

	};

}