#ifndef PLAYER_H
#define PLAYER_H
#include <QString>


class Player
{
public:
    Player();
    Player(QString, int);
    QString text();
    int getSR();
    QString name;
    int mmr;
private:
};

#endif // PLAYER_H
