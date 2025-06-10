#include "libOne.h"
#include "BULLET.h"
#include "CHARA.h"
#include "hpGauge.h"
#include "collision.h"
#include "ninjin.h"

void ninjinLoading(BULLET* ninjin)
{
    ninjin->img = loadImage("assets\\ninjin0.png");
}

void ninjinInit(BULLET* ninjin)
{
    ninjin->px = 0.0f;
    ninjin->py = 0.0f;
    ninjin->vy = -5.0f;
    ninjin->hp = 0;
    ninjin->halfW = 10;
    ninjin->halfH = 16;
}

void ninjinLaunchAndMove(BULLET* ninjin, CHARA* rabit)
{
    //ƒjƒ“ƒWƒ“‚ð”­ŽË‚·‚é
    if (ninjin->hp == 0 && isTrigger(KEY_SPACE)) {
        //”­ŽËˆÊ’u
        ninjin->px = rabit->px;
        ninjin->py = rabit->py + rabit->bulletOfsY;
        ninjin->hp = 1;
    }

    ninjinMove(ninjin);
}

void ninjinMove(BULLET* ninjin)
{
    if (ninjin->hp > 0) {
        ninjin->py += ninjin->vy;
        if (ninjin->py < -ninjin->halfH) {
            ninjin->hp = 0;
        }
    }
}

void ninjinDraw(BULLET* ninjin)
{
    rectMode(CENTER);
    if (ninjin->hp > 0) {
        image(ninjin->img, ninjin->px, ninjin->py);
    }
}
