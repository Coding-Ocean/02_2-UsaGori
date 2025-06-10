#pragma once
//ウサギとゴリラ用構造体型
struct CHARA 
{
    //各画像番号
    int normalImg;
    int damageImg;
    int loseImg;
    int winImg;
    //現在の画像番号
    int img;
    //位置
    float px;
    float py;
    //移動方向ベクトル
    float vx;
    float vy;
    //弾発射オフセット位置
    float bulletOfsY;//pyにこの値を加算した値を発射位置とする
    //体力
    int hp;
    //ＨＰゲージ表示オフセット位置
    float hpGaugeOfsY;
    //当たり判定用、半分の幅と高さ
    float halfW;
    float halfH;
};
