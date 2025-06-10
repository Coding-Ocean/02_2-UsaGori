#include "libOne.h"
#include "BULLET.h"
#include "CHARA.h"
#include "hpGauge.h"
#include "collision.h"
#include "unko.h"

void unkoLoading(BULLET* unko)
{
    unko->img = loadImage("assets\\unko0.png");
}

void unkoInit(BULLET* unko)
{
    unko->px = 0.0f;
    unko->py = 0.0;
    unko->vy = 5.0f;
    unko->hp = 0;
    unko->halfW = 20;
    unko->halfH = 16;
}

void unkoLaunchAndMove(BULLET* unko, CHARA* gori)
{
    if (unko->hp == 0) {
        //発射位置
        unko->px = gori->px;
        unko->py = gori->py + gori->bulletOfsY;
        unko->hp = 1;
    }

    unkoMove(unko);
}

void unkoMove(BULLET* unko)
{
    if (unko->hp > 0) {
        unko->py += unko->vy;
        //ウィンドウの外に出た
        if (unko->py > height + unko->halfH) {
            unko->hp = 0;
        }
    }
}

void unkoDraw(BULLET* unko)
{
    rectMode(CENTER);
    if (unko->hp > 0) {
        image(unko->img, unko->px, unko->py);
    }
}
