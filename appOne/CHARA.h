#pragma once
//�E�T�M�ƃS�����p�\���̌^
struct CHARA 
{
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
    //�e���˃I�t�Z�b�g�ʒu
    float bulletOfsY;//py�ɂ��̒l�����Z�����l�𔭎ˈʒu�Ƃ���
    //�̗�
    int hp;
    //�g�o�Q�[�W�\���I�t�Z�b�g�ʒu
    float hpGaugeOfsY;
    //�����蔻��p�A�����̕��ƍ���
    float halfW;
    float halfH;
};
