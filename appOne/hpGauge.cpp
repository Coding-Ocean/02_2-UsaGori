#include "libOne.h"
#include "CHARA.h";
void hpGauge(struct CHARA* c) 
{
    strokeWeight(0);
    if (c->hp > 15) {
        fill(0, 255, 0);
    }
    else {
        fill(255, 0, 0);
    }
    rect(c->px, c->py + c->hpGaugeOfsY, c->hp, 5);
}