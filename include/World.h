#pragma once
#include "raylib.h"
#include <iostream>
#include <Player.h>
#include <fstream>

namespace LoW
{
#define TILE_SIZE 64
#define MAX_TILES 131
#define TILEMAPX 16
#define TILEMAPY 12
	class World
	{
	private: 
		static World* instance;
		World() = default;
		World(const World&) = delete;
		World& operator=(const World&) = delete;

	public:
	    size_t* tilemap;
		Texture background;
		Image collisionMask;
		Player* playerCharacter;
		unsigned char* collisionMaskdata;
		Texture tiles[MAX_TILES];
		/*float tileScale = TILE_SIZE / tiles[0].width;*/
		float tileScale = 4;

		static World& getInstance()
		{
			if (!instance) 
			{
				instance = new World();
				instance->World1();
			}
			return *instance;
		}

		static void SetPlayer(Player* player)
		{
			getInstance().playerCharacter = player;
		}

		void World1() 
		{
			char buffer[32];
			for (size_t i = 0; i < MAX_TILES; i++)
			{
				sprintf(buffer, "tinytown/Tiles/tile_%04zu.png", i);
				tiles[i] = LoadTexture(buffer);
			}
			tilemap = new size_t[TILEMAPX * TILEMAPY];

			std::string workingDir = GetWorkingDirectory();
			std::string filename = "/mapa1.txt";
			std::ifstream file(  workingDir + filename  );
			if (file.is_open())
			{
				std::cout << "archivo abierto" << std::endl;
				for (size_t y = 0; y < TILEMAPY; y++)
				{
					for (size_t x = 0; x < TILEMAPX; x++)
					{
						std::string value;
						std::getline(file, value, ',');
						std::cout << "leido: " << value << std::endl;
						tilemap[y * TILEMAPX + x] = std::stoi(value);
						//std::cout << "valor de tile: " << tilemap[y * TILEMAPX]
					} 
				}
			}
			//calcular escala para mostrar

			size_t n = sizeof(tilemap) / sizeof(tilemap[0]);
			if (n != (TILEMAPX * TILEMAPY))
			{
				puts("Error, el mapa no es x y");
				return;
			}
			/*background = LoadTexture("world1.jpg");
			collisionMask = LoadImage("world1_mask.png");
			ImageFormat(&collisionMask, PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);
			collisionMaskdata = (unsigned char*)collisionMask.data;*/
		}

		void Draw()
		{
			DrawTexture(background, 0, 0, WHITE);
			for (int i = 0; i < TILEMAPY; i++)
			{
				for (int j = 0; j < TILEMAPX; j++)
				{
					int offset = TILEMAPX * i + j;
					DrawTextureEx(tiles[tilemap[offset]], { j * TILE_SIZE - playerCharacter->cameraOffset.x,
						i * TILE_SIZE - playerCharacter->cameraOffset.y }, 0, tileScale, WHITE);
					//sprintf(buffer, "%i,%i: %i", j, i, offset);
					//DrawText(buffer, j * TILE_SIZE - cameraOffset.x, i * TILE_SIZE - cameraOffset.y,10, YELLOW);
				}
			}
		}

		bool CheckCollision(Vector2 point)
		{
			/*int index = (point.y * collisionMask.width + point.x);*/


			/*std::cout << "valor en pixel: " << point.x << "," << point.y << "," << std::hex << collisionMaskdata[index] << std::endl;*/

			return false; /*collisionMaskdata[index] != 0;*/
		}

	};
	

}