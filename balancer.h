#ifndef BALANCER_H
#define BALANCER_H
#include <QString>
#include <player.h>
#include <array>
class Balancer
{
public:
    Balancer();
    void addPlayer(QString,int);
    void BalanceTeams();
    void setTeams(unsigned int);
    int getsize();
    std::array<Player,6> team1;
    std::array<Player,6> team2;
    double average(std::array<Player,6>);
    double getteam1SR();
    double getteam2SR();
private:
    int getbit(unsigned int X, int n);
    bool check6bits(int X);
    int size;
    std::array<Player,12> unbalanced;
};

#endif // BALANCER_H