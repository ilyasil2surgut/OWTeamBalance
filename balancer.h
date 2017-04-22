#ifndef BALANCER_H
#define BALANCER_H
#include <QString>
#include <player.h>
#include <array>
#include <math.h>
#include <QDebug>
#include <team.h>
class Balancer
{
public:
    Balancer(Team*,Team*);
    void addPlayer(QString,int);
    void BalanceTeams();
    void setTeams(unsigned int,QList<Player*>&,QList<Player*>&);
    int getsize();
    double average(QList<Player*>);
    double getteam1SR();
    double getteam2SR();
    void setcalculatemethod(int);
    void clear();
    void swap(int,int);
    Team* getteam1();
    Team *getteam2();
    void remove(Player *p);
private:
    int getbit(unsigned int X, int n);
    bool check6bits(int X);
    QList<Player*> unbalanced;
    int size;
    int calculatemethod;
    Team* team1;
    Team* team2;
};

#endif // BALANCER_H
