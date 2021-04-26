#include "libOne.h"
#include "gmain.h"

//�E�T�M�ƃS�����p�\���̌^
struct CHARA {
    //�e�摜�ԍ�
    int normalImg;
    int damageImg;
    int loseImg;
    int winImg;
    //���݂̉摜�ԍ�
    int img;
    //�ʒu
    float px;
    float py;
    //�ړ������x�N�g��
    float vx;
    float vy;
    //�̗�
    int hp;
    //�g�o�Q�[�W�p�摜�ԍ�
    int hpGaugeImg;
    //�g�o�Q�[�W�\���I�t�Z�b�g�ʒu
    float hpGaugeOfsY;
    //�����蔻��p�A�����̕��ƍ���
    float halfW;
    float halfH;
    //�e���˃I�t�Z�b�g�ʒu
    float bulletOfsY;
};
//�ɂ񂶂�Ƃ��񂱗p�\���̌^
struct BULLET {
    //�摜�ԍ�
    int img;
    //�ʒu
    float px;
    float py;
    //�����x�N�g��
    float vx;
    float vy;
    //�̗́H�i�E�B���h�E������ł��邩���Ӗ�����j
    int hp;
    //�����蔻��p�A�����̕��ƍ���
    float halfW;
    float halfH;
};
//�S�f�[�^���Ǘ�����\���̌^
struct DATA {
    //----------------------------------------
    //�L�����N�^�f�[�^
    struct CHARA rabit;
    struct CHARA gori;
    struct BULLET ninjin;
    struct BULLET unko;
    int titleImg;
    int backImg;
    //----------------------------------------
    //�X�e�[�g����p�f�[�^
    int TITLE = 0;
    int PLAY = 1;
    int RESULT = 2;
    int state = TITLE;
    //RESULT�̎��A�L�[���͂𖳌�������t���[����
    int frameRestrictInput = 90;
    int frameCnt = 0;
};

//�֐��̌Ăяo���\��
//title()
//  init()
//play()
//  collision()
//  draw()
//    hpGauge()
//result()
//  draw()
//    hpGauge();
void loadImages(struct DATA* d) {
    d->rabit.normalImg = loadImage("assets\\rabit0.png");
    d->rabit.damageImg = loadImage("assets\\rabit1.png");
    d->rabit.loseImg = loadImage("assets\\rabit2.png");
    d->rabit.winImg = loadImage("assets\\rabit3.png");
    d->rabit.hpGaugeImg = loadImage("assets\\bar.png");

    d->gori.normalImg = loadImage("assets\\gorilla0.png");
    d->gori.damageImg = loadImage("assets\\gorilla1.png");
    d->gori.loseImg = loadImage("assets\\gorilla2.png");
    d->gori.winImg = loadImage("assets\\gorilla3.png");
    d->gori.hpGaugeImg = d->rabit.hpGaugeImg;
    
    d->unko.img = loadImage("assets\\unko0.png");
    
    d->ninjin.img = loadImage("assets\\ninjin0.png");
    
    d->titleImg = loadImage("assets\\title.png");
    
    d->backImg = loadImage("assets\\back.png");
}
void title(struct DATA* d) {
    clear();
    rectMode(CORNER);
    imageColor(255, 255, 255);
    image(d->titleImg, 0, 0);
    if (isTrigger(KEY_SPACE)) {
        init(d);
        //�X�e�[�g�؂�ւ�
        d->state = d->PLAY;
    }
}
void init(struct DATA* d) {
    d->rabit.img = d->rabit.normalImg;
    d->rabit.px = 150.0f;
    d->rabit.py = 400.0f;
    d->rabit.vx = 4.0f;
    d->rabit.hp = 50;
    d->rabit.bulletOfsY = -70;
    d->rabit.hpGaugeOfsY = -60;

    d->gori.img = d->gori.normalImg;
    d->gori.px = 150.0f;
    d->gori.py = 70.0f;
    d->gori.vx = 4.0f;
    d->gori.hp = 100;
    d->gori.hpGaugeOfsY = -62;
    d->gori.bulletOfsY = 55;
    
    d->unko.px = 0.0f;
    d->unko.py = 0.0;
    d->unko.vy = 5.0f;
    d->unko.hp = 0;
    
    d->ninjin.px = 0.0f;
    d->ninjin.py = 0.0f;
    d->ninjin.vy = -5.0f;
    d->ninjin.hp = 0;
    
    //�����蔻��p�f�[�^
    d->rabit.halfW = 35;
    d->rabit.halfH = 55;
    d->gori.halfW = 40;
    d->gori.halfH = 60;
    d->unko.halfW = 20;
    d->unko.halfH = 16;
    d->ninjin.halfW = 10;
    d->ninjin.halfH = 16;
}
void play(struct DATA* d) {
    
    //�E�T�M�𓮂���
    if (isPress(KEY_A)) { d->rabit.px += -d->rabit.vx; }
    if (isPress(KEY_D)) { d->rabit.px += d->rabit.vx; }
    //�E�T�M�̈ړ��͈͐���
    if (d->rabit.px < d->rabit.halfW) { 
        d->rabit.px = d->rabit.halfW; 
    }
    if (d->rabit.px > width - d->rabit.halfW) {
        d->rabit.px = width - d->rabit.halfW;
    }
    
    //�j���W���𔭎˂���
    if (d->ninjin.hp == 0 && isTrigger(KEY_SPACE)) {
        //���ˈʒu
        d->ninjin.px = d->rabit.px;
        d->ninjin.py = d->rabit.py + d->rabit.bulletOfsY;
        d->ninjin.hp = 1;
    }
    //�j���W���𓮂���
    if (d->ninjin.hp > 0) {
        d->ninjin.py += d->ninjin.vy;
        //�E�B���h�E�̊O�ɏo��
        if (d->ninjin.py < -d->ninjin.halfH) {
            d->ninjin.hp = 0;
        }
    }

    //�S�����𓮂���
    d->gori.px += d->gori.vx;
    if (d->gori.px < d->gori.halfW ||
        d->gori.px > width - d->gori.halfW) { 
        //�ړ��������]
        d->gori.vx = -d->gori.vx; 
    }

    //�E���R����
    if (d->unko.hp == 0) {
        //���ˈʒu
        d->unko.px = d->gori.px;
        d->unko.py = d->gori.py + d->gori.bulletOfsY;
        d->unko.hp = 1;
    }
    //�E���R�𓮂���
    if (d->unko.hp > 0) {
        d->unko.py += d->unko.vy;
        //�E�B���h�E�̊O�ɏo��
        if (d->unko.py > height + d->unko.halfH) {
            d->unko.hp = 0;
        }
    }

    //�����蔻��E�E�T�M�Ƃ���
    if (collision(&d->rabit, &d->unko)) {
        d->rabit.img = d->rabit.damageImg;
        d->rabit.hp--;
    }
    else {
        d->rabit.img = d->rabit.normalImg;
    }
    //�����蔻��E�S�����Ƃɂ񂶂�
    if (collision(&d->gori, &d->ninjin)) {
        d->gori.img = d->gori.damageImg;
        d->gori.hp--;
    }
    else {
        d->gori.img = d->gori.normalImg;
    }

    //�`��
    draw(d);

    //����������
    if (d->rabit.hp <= 0 || d->gori.hp <= 0) {
        //���������摜�؂�ւ�
        if (d->gori.hp > 0) {//�S������������
            d->gori.img = d->gori.winImg;
            d->rabit.img = d->rabit.loseImg;
        }
        else {//���r�b�g��������
            d->rabit.img = d->rabit.winImg;
            d->gori.img = d->gori.loseImg;
        }
        //�X�e�[�g�؂�ւ�
        d->frameCnt = d->frameRestrictInput;
        d->state = d->RESULT;
    }

}
int collision(struct CHARA* c, struct BULLET* b) {
    //��`�Ƌ�`�̓����蔻��
    if (b->hp > 0) {
        float cRight = c->px + c->halfW;
        float cLeft = c->px - c->halfW;
        float cTop = c->py - c->halfH;
        float cBottom = c->py + c->halfH;
        float bRight = b->px + b->halfW;
        float bLeft = b->px - b->halfW;
        float bTop = b->py - b->halfH;
        float bBottom = b->py + b->halfH;
        if (cRight < bLeft || bRight < cLeft ||
            bBottom < cTop || cBottom < bTop ) {
            //�G��Ă��Ȃ�
            return 0;
        }
        else {
            //�G��Ă���
            return 1;
        }
    }
    return 0;
}
void draw(struct DATA* d) {
    clear();
    imageColor(255);
    //�w�i
    rectMode(CORNER);
    image(d->backImg, 0, 0);
    rectMode(CENTER);
    //�L����
    image(d->rabit.img, d->rabit.px, d->rabit.py);
    image(d->gori.img, d->gori.px, d->gori.py);
    //�e
    if (d->ninjin.hp > 0) {
        image(d->ninjin.img, d->ninjin.px, d->ninjin.py);
    }
    if (d->unko.hp > 0) {
        image(d->unko.img, d->unko.px, d->unko.py);
    }
    //�g�o�Q�[�W
    hpGauge(&d->gori);
    hpGauge(&d->rabit);
#if _DEBUG
    //�����蔻��G���A�\��
    fill(255, 255, 255, 128);
    rect(d->rabit.px, d->rabit.py, d->rabit.halfW * 2, d->rabit.halfH * 2);
    rect(d->unko.px, d->unko.py, d->unko.halfW * 2, d->unko.halfH * 2);
    rect(d->gori.px, d->gori.py, d->gori.halfW * 2, d->gori.halfH * 2);
    rect(d->ninjin.px, d->ninjin.py, d->ninjin.halfW * 2, d->ninjin.halfH * 2);
#endif
}
void hpGauge(struct CHARA* c) {
    float px = c->px - c->hp / 2;
    float py = c->py + c->hpGaugeOfsY;
    if (c->hp > 15) {
        imageColor(0, 255, 0);
    }
    else {
        imageColor(255, 0, 0);
    }
    for (int i = 0; i < c->hp; i++) {
        image(c->hpGaugeImg, px + i, py);
    }
}
void result(struct DATA* d) {
    //�j���W���ƃE���R����ʊO�܂ňړ�
    if (d->ninjin.hp > 0) {
        d->ninjin.py += d->ninjin.vy;
        if (d->ninjin.py < -d->ninjin.halfH) {
            d->ninjin.hp = 0;
        }
    }
    if (d->unko.hp > 0) {
        d->unko.py += d->unko.vy;
        if (d->unko.py > height + d->unko.halfH) {
            d->unko.hp = 0;
        }
    }
    //�`��
    draw(d);
    //���X�^�[�g
    if (d->frameCnt > 0) {
        d->frameCnt--;
    }
    else {
        text("Space�Ń^�C�g���ɖ߂�܂�", 25, height);
    }
    if (d->frameCnt <= 0 && isTrigger(KEY_SPACE)) {
        d->state = d->TITLE;
    }
}

void gmain() {
    window(300, 480, full);
    //�S�f�[�^
    struct DATA d;
    //�S�摜�ǂݍ���
    loadImages(&d);
    ShowCursor(false);
    while (notQuit) {
        //�Q�[���X�e�[�g����
        if      (d.state == d.TITLE ) { title(&d); }
        else if (d.state == d.PLAY  ) { play(&d); }
        else if (d.state == d.RESULT) { result(&d); }
    }
    ShowCursor(true);
}
