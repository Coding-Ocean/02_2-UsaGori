#include "libOne.h"
#include "title.h"

void titleLoading(int* img)
{
    *img = loadImage("assets\\title.png");
}

void titleDraw(int img)
{
    clear();
    rectMode(CORNER);
    image(img, 0, 0);
}
