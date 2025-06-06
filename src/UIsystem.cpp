#include "UIsystem.h"

UIsystem* UIsystem::instance = nullptr;

Label* UIsystem::createLabel(const char* text, int x, int y, int fontSize)
{
	Label* label = new Label();
	label->text = text;
	label->rect.x = x;
	label->rect.y = y;
	label->fontSize = fontSize;
	views.push_back(label);
	return label;
}

button* UIsystem::createbutton(const char* text, int x, int y, int w, int h, int fontsize)
{
	button* butt = new button();
	butt->text = text;
	butt->rect.width = w;
	butt->rect.height = h;
	butt->rect.x = x;
	butt->rect.y = y;
	butt->fontSize = fontsize;
	views.push_back(butt);
	return butt;
}

image* UIsystem::createimage(int x, int y, Texture img)
{
	image* image1 = new image();
	image1->rect.x = x;
	image1->rect.y = y;
	image1->img = img;
	views.push_back(image1);
	return image1;
}

void UIsystem::draw()
{
	 
	for (View* view : views)
	{
		if (view->visible)
			view->draw();
	}
}

void UIsystem::update()
{

	for (View* view : views)
	{
		if (view->visible)
			view->update();
	}
}