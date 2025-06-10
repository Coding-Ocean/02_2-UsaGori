#include "libOne.h"
#include "CHARA.h"
#include "hpGauge.h"
#include "collision.h"
#include "rabit.h"

void rabitLoading(CHARA* rabit)
{
    rabit->normalImg = loadImage("assets\\rabit0.png");
    rabit->damageImg = loadImage("assets\\rabit1.png");
    rabit->loseImg = loadImage("assets\\rabit2.png");
    rabit->winImg = loadImage("assets\\rabit3.png");
}

void rabitInit(CHARA* rabit)
{
    rabit->img = rabit->normalImg;
    rabit->px = 150.0f;
    rabit->py = 400.0f;
    rabit->vx = 4.0f;
    rabit->hp = 50;
    rabit->bulletOfsY = -70;
    rabit->hpGaugeOfsY = -60;
    rabit->halfW = 35;
    rabit->halfH = 55;
}

void rabitMove(CHARA* rabit)
{
    //ƒEƒTƒM‚ð“®‚©‚·
    if (isPress(KEY_A)) { rabit->px += -rabit->vx; }
    if (isPress(KEY_D)) { rabit->px += rabit->vx; }
    //ƒEƒTƒM‚ÌˆÚ“®”ÍˆÍ§ŒÀ
    if (rabit->px < rabit->halfW) {
        rabit->px = rabit->halfW;
    }
    if (rabit->px > width - rabit->halfW) {
        rabit->px = width - rabit->halfW;
    }

}

void rabitCollision(CHARA* rabit, BULLET* unko)
{
    if (collision(rabit, unko)) {
        rabit->img = rabit->damageImg;
        rabit->hp--;
    }
    else {
        rabit->img = rabit->normalImg;
    }
}

void rabitResultInit(CHARA* rabit)
{
    //Ÿ‚¿•‰‚¯‰æ‘œØ‚è‘Ö‚¦
    if (rabit->hp > 0) {
        rabit->img = rabit->winImg;
    }
    else {
        rabit->img = rabit->loseImg;
    }
}

void rabitDraw(CHARA* rabit)
{
    rectMode(CENTER);
    image(rabit->img, rabit->px, rabit->py);

    hpGauge(rabit);
}
