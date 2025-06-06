#pragma once
#include "View.h"


class image :
    public View
{
public:
    Texture img;

    void update() override;
    void draw() override;
};

