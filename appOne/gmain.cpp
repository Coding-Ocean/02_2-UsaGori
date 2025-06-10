#include "libOne.h"
#include "CHARA.h"
#include "BULLET.h"
#include "rabit.h"
#include "gori.h"
#include "ninjin.h"
#include "unko.h"
#include "title.h"
#include "background.h"

//全データを管理する構造体型
struct DATA 
{
    //----------------------------------------
    //ステート制御用データ
    int TITLE = 0;
    int PLAY = 1;
    int RESULT = 2;
    int state = TITLE;
    //RESULTの時、キー入力を無効化するフレーム数
    int frameCnt;
    //----------------------------------------
    //キャラクタデータ
    struct CHARA rabit;
    struct CHARA gori;
    struct BULLET ninjin;
    struct BULLET unko;
    int titleImg;
    int backImg;
};

void loading(struct DATA* d) 
{
    rabitLoading(&d->rabit);
    goriLoading(&d->gori);
    ninjinLoading(&d->ninjin);
    unkoLoading(&d->unko);
    titleLoading(&d->titleImg);
    backgroundLoading(&d->backImg);
}

void title(struct DATA* d)
{
    //描画
    titleDraw(d->titleImg);
    //ステート切り替え
    if (isTrigger(KEY_SPACE))
    {
        rabitInit(&d->rabit);
        goriInit(&d->gori);
        ninjinInit(&d->ninjin);
        unkoInit(&d->unko);
        d->state = d->PLAY;
    }
}

void play(struct DATA* d)
{
    //更新
    rabitMove(&d->rabit);
    goriMove(&d->gori);
    ninjinLaunchAndMove(&d->ninjin, &d->rabit);
    unkoLaunchAndMove(&d->unko, &d->gori);
    //当たり判定
    rabitCollision(&d->rabit, &d->unko);
    goriCollision(&d->gori, &d->ninjin);
    //描画
    backgroundDraw(d->backImg);
    rabitDraw(&d->rabit);
    goriDraw(&d->gori);
    ninjinDraw(&d->ninjin);
    unkoDraw(&d->unko);
    //ステート切り替え
    if (d->rabit.hp <= 0 || d->gori.hp <= 0)
    {
        rabitResultInit(&d->rabit);
        goriResultInit(&d->gori);
        d->frameCnt = 90;
        d->state = d->RESULT;
    }
}

void result(struct DATA* d)
{
    //更新
    ninjinMove(&d->ninjin);
    unkoMove(&d->unko);
    //描画
    backgroundDraw(d->backImg);
    rabitDraw(&d->rabit);
    goriDraw(&d->gori);
    ninjinDraw(&d->ninjin);
    unkoDraw(&d->unko);
    //ステート切り替え
    if (d->frameCnt > 0) 
    {
        d->frameCnt--;
    }
    else 
    {
        fill(255);
        text("Spaceでタイトルに戻ります", 25, height);
        if (isTrigger(KEY_SPACE)) 
        {
            d->state = d->TITLE;
        }
    }
}

void gmain()
{
    window(300, 480);
    //全データ
    struct DATA d;
    //全画像読み込み
    loading(&d);
    while (notQuit) 
    {
        //ゲームステート制御
        if      (d.state == d.TITLE ) { title(&d); }
        else if (d.state == d.PLAY  ) { play(&d); }
        else if (d.state == d.RESULT) { result(&d); }
    }
}
