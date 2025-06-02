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