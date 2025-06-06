#include <iostream>
#include <vector>
#include "View.h"
#include "Label.h" 
#include "button.h"
#include "image.h"
#pragma once

class UIsystem
{
public:
	static UIsystem& getInstance()
	{
		if (!instance)
		{
			instance = new UIsystem();

		}
		return *instance;
	}

	void test()
	{
		std::cout << "Hola soy El singleton de UI" << std::endl;
	}

	static void Test()
	{
		getInstance().test();
	}
	Label* createLabel(const char* text, int x, int y, int fontSize = 30);

	button* UIsystem::createbutton(const char* text, int x, int y, int w, int h, int fontsize = 30);
	
	image* UIsystem::createimage(int x, int y, Texture img);

	void draw();
	static void Draw()
	{
		getInstance().draw();
	}

	void update();
	static void Update()
	{
		getInstance().update();
	}

	std::vector<View*> views;

private:
	static UIsystem* instance;
	UIsystem() = default;
	UIsystem(const UIsystem&) = delete;
	UIsystem& operator=(const UIsystem&) = delete;

};

