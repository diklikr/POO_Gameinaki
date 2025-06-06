#include <iostream>
#include <string>
#include "raylib.h"

#include "View.h"
#include "UIsystem.h"
#include "resource_dir.h"	
#include "GameObject.h"
#include "Player.h"
#include "Sidekick.h"
#include <vector>
#include "button.h"


//using namespace std;
using namespace LoW;

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	std::cout << "Inicializando sistema de juego" << std::endl;

	
	InitWindow(1280, 800, "Juego Con Objetos");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	//std::vector<GameObject*> gameObjects;

	/*GameObject* myObj = new GameObject({ 200,200 }, "PINGU",*/ /*LoadTexture("pingu.png"));*/
	/*myObj->displayName = true;*/

	/*GameObject::gameObjects.push_back(myObj);*/

	Player* playerCharacter = new Player({ 100, 100}, "Player1");
	playerCharacter->speed = 200.0f;


	GameObject::gameObjects.push_back(static_cast<GameObject*>(playerCharacter));


	Weapon* w = new Weapon({ 200,200 }, "Sword", LoadTexture("sword.png"));
	//playerCharacter->SetWeapon(w);
	GameObject::gameObjects.push_back(w);

	Sidekick* sidekick = new Sidekick({ 500,0 }, "Sidekick1", LoadTexture("sidekick.png"));
	playerCharacter->SetSidekick(sidekick, 0);
	sidekick->speed = 199.0f;
	sidekick->owner = playerCharacter;
	sidekick->displayName = true;
	GameObject::gameObjects.push_back(sidekick);

	Sidekick* sidekick2 = new Sidekick({ 500,0 }, "Sidekick2", LoadTexture("sidekick.png"));
	playerCharacter->SetSidekick(sidekick2, 1);
	sidekick2->speed = 190.0f;
	sidekick2->owner = playerCharacter;
	sidekick2->displayName = true;
	GameObject::gameObjects.push_back(sidekick2);

	
	for (GameObject* obj : GameObject::gameObjects)
	{
		Player* p = dynamic_cast<Player*>(obj);
		if (p)
		{
			p->attack();
		}
		Sidekick* sk = dynamic_cast<Sidekick*>(obj);
		if (sk != nullptr)
		{
			sk->flee();
		}
	}

	UIsystem::getInstance().createbutton("Press to spawn", 300, 600, 240, 60, 30);

	Texture t = LoadTexture("pingu.png");
	UIsystem::getInstance().createimage(350, 350, t);


	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		for (GameObject* obj : GameObject::gameObjects)
		{
			obj->update();
		}
		

		/*myObj->update();*/
		playerCharacter->update();
		sidekick->update();
		
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(MAGENTA);

		// draw some text using the default font
		DrawText("Juego Con Pingu", 10, 10, 24, WHITE);

		
		for (GameObject* obj : GameObject::gameObjects)
		{
			obj->draw();
		}

		UIsystem::Draw();
		// draw our texture to the screen
		//for (size_t i = 0; i < 20; i++)
		//{
		//	/*DrawTexture(wabbit, 20+(i), 200, WHITE);*/
		//}
		/*myObj->draw();*/
		playerCharacter->draw();
		sidekick->draw();


		
		EndDrawing();
	}

	
	CloseWindow();
	return 0;
}
