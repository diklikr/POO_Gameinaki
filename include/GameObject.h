#pragma once
#include "raylib.h"
#include "string"
#include <iostream>
#include <vector>
//using namespace std;
namespace LoW
{
	class GameObject
	{

	public:
		Vector2 position;
		std::string name;

		Texture texture;
		bool displayName = false;

		static std::vector<GameObject*> gameObjects;

		GameObject() :
			position({ 0,0 }),
			name("GameObject"),
			texture({ 0 })
		{

		}

		GameObject(Vector2 pos, std::string _name, Texture tex) :
			position(pos), name(_name), texture(tex) {
		}

		virtual void update();

		virtual void draw();

	};
}

