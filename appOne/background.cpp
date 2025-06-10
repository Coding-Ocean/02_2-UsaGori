#include "libOne.h"
#include "background.h"

void backgroundLoading(int* img)
{
    *img = loadImage("assets\\back.png");
}

void backgroundDraw(int img)
{
    clear();
    rectMode(CORNER);
    image(img, 0, 0);
}
