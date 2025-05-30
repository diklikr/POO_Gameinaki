#pragma once
class View
{
public:
	Rectangle rect;
	bool visible = true;

	View() : rect({ 0, 0, 100, 100}), visible(true) {}

	View(int x, int y, int w, int h) : visible(true)
	{
		rect = { (float)x, (float)y, (float)w, (float)h };
	}

	virtual void update() = 0;
	virtual void draw() = 0;

protected:

};

