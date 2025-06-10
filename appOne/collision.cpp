#include "CHARA.h"
#include "BULLET.h"
int collision(struct CHARA* c, struct BULLET* b) 
{
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
            bBottom < cTop || cBottom < bTop) {
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