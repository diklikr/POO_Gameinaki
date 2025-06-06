#include "image.h"

void image::update()
{
}
void image::draw()
{
	DrawTexture(img, rect.x, rect.y, WHITE);
}
