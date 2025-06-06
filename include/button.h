#pragma once
#include "View.h"
#include "enemigo.h"
class button : 
	public View
{
public:
	const char* text = "Push to spawn";
	int fontSize = 30;

	void update() override;
	void draw() override;
};

