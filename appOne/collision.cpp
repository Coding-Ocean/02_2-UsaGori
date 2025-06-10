#include "CHARA.h"
#include "BULLET.h"
int collision(struct CHARA* c, struct BULLET* b) 
{
    //‹éŒ`‚Æ‹éŒ`‚Ì“–‚½‚è”»’è
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
            //G‚ê‚Ä‚¢‚È‚¢
            return 0;
        }
        else {
            //G‚ê‚Ä‚¢‚é
            return 1;
        }
    }
    return 0;
}