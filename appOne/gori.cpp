#include "libOne.h"
#include "CHARA.h"
#include "hpGauge.h"
#include "collision.h"
#include "gori.h"

void goriLoading(CHARA* gori)
{
    gori->normalImg = loadImage("assets\\gorilla0.png");
    gori->damageImg = loadImage("assets\\gorilla1.png");
    gori->loseImg = loadImage("assets\\gorilla2.png");
    gori->winImg = loadImage("assets\\gorilla3.png");
}

void goriInit(CHARA* gori)
{
    gori->img = gori->normalImg;
    gori->px = 150.0f;
    gori->py = 70.0f;
    gori->vx = 4.0f;
    gori->bulletOfsY = 55;
    gori->hp = 100;
    gori->hpGaugeOfsY = -62;
    gori->halfW = 40;
    gori->halfH = 60;
}

void goriMove(CHARA* gori)
{
    gori->px += gori->vx;
    if (gori->px < gori->halfW ||
        gori->px > width - gori->halfW) {
        //ˆÚ“®•ûŒü”½“]
        gori->vx = -gori->vx;
    }
    if (isPress(KEY_R))gori->hp--;

}

void goriCollision(CHARA* gori, BULLET* ninjin)
{
    if (collision(gori, ninjin)) {
        gori->img = gori->damageImg;
        gori->hp--;
    }
    else {
        gori->img = gori->normalImg;
    }
}

void goriResultInit(CHARA* gori)
{
    //Ÿ‚¿•‰‚¯‰æ‘œØ‚è‘Ö‚¦
    if (gori->hp > 0) {
        gori->img = gori->winImg;
    }
    else {
        gori->img = gori->loseImg;
    }
}

void goriDraw(CHARA* gori)
{
    rectMode(CENTER);
    image(gori->img, gori->px, gori->py);

    hpGauge(gori);
}
