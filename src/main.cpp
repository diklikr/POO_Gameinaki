#include <iostream>
#include <string>
#include "raylib.h"

#include "resource_dir.h"	
#include "GameObject.h"
#include "Player.h"
#include "Sidekick.h"
#include <vector>


//using namespace std;


int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	std::cout << "Inicializando sistema de juego" << std::endl;

	
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	std::vector<GameObject*> gameObjects;

	GameObject* myObj = new GameObject({ 200,200 }, "myObj", LoadTexture("pingu.png"));
	myObj->displayName = true;
	gameObjects.push_back(myObj);

	Player* playerCharacter = new Player({ 0,0 }, "Player1", LoadTexture("wabbit_alpha.png"));
	playerCharacter->speed = 200.0f;
	gameObjects.push_back(playerCharacter);

	Sidekick* sidekick = new Sidekick({ 500,0 }, "Sidekick1", LoadTexture("sidekick.png"));
	sidekick->speed = 199.0f;
	sidekick->owner = playerCharacter;
	sidekick->displayName = true;
	gameObjects.push_back(sidekick);

	Sidekick* sidekick2 = new Sidekick({ 500,0 }, "Sidekick2", LoadTexture("sidekick.png"));
	sidekick2->speed = 190.0f;
	sidekick2->owner = playerCharacter;
	sidekick2->displayName = true;
	gameObjects.push_back(sidekick2);

	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	for (GameObject* obj : gameObjects)
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

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		for (GameObject* obj : gameObjects)
		{
			obj->update();
		}

		myObj->update();
		playerCharacter->update();
		sidekick->update();
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(MAGENTA);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		/*DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, 30, RED);
		DrawCircle(GetScreenWidth() * 0.25f, GetScreenHeight() * 0.25f, 50, BLUE);*/
		for (GameObject* obj : gameObjects)
		{
			obj->draw();
		}
		// draw our texture to the screen
		for (size_t i = 0; i < 20; i++)
		{
			/*DrawTexture(wabbit, 20+(i), 200, WHITE);*/
		}
		myObj->draw();
		playerCharacter->draw();
		sidekick->draw();


		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
