#include "player.h"


Player::Player()
{
    name=QString();mmr=0;
}

Player::Player(QString str, int n)
{
    name=str;mmr=n;
}

QString Player::text()
{
    return name+QString(" ")+QString::number(mmr);
}

int Player::getSR()
{
    return mmr;
}
