#pragma once
//にんじんとうんこ用構造体型
struct BULLET 
{
    //画像番号
    int img;
    //位置
    float px;
    float py;
    //方向ベクトル
    float vx;
    float vy;
    //体力？（ウィンドウ内を飛んでいるかを意味する）
    int hp;
    //当たり判定用、半分の幅と高さ
    float halfW;
    float halfH;
};