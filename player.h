#ifndef PLAYER_H
#define PLAYER_H
#include <QString>


class Player
{
public:
    Player();
    Player(QString, int);
    QString text();
    QString name;
    int mmr;
};

#endif // PLAYER_H
