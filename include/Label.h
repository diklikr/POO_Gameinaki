#pragma once
#include "View.h"
class Label :
    public View
{
public:
    void update() override;

    void draw() override;
};

