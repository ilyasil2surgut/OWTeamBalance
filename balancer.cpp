#include "balancer.h"


Balancer::Balancer()
{
    size=0;
}

void Balancer::addPlayer(QString str, int n)
{
    if(size<12){
        unbalanced[size]=Player(str,n);
        size++;
    }
}

void Balancer::BalanceTeams()
{
    if (size==12){
        double team1SR=0,team2SR=5000;
        double bestdifference=5000;
        std::array<Player,6> bestteam1,bestteam2;
        unsigned int matrix=63;
        setTeams(matrix);
        bestteam1=team1;
        bestteam2=team2;
        bestdifference=abs(average(team1)-average(team2));
        int difference;
        while(matrix<64512){
            matrix++;
            if(check6bits(matrix)){
                setTeams(matrix);
                difference=abs(average(team1)-average(team2));
                if(difference<bestdifference){
                    bestteam1=team1;
                    bestteam2=team2;
                    bestdifference=difference;
                }
            }
        }
        team1=bestteam1;
        team2=bestteam2;
        team1SR=average(team1);
        team2SR=average(team2);
    }
}

void Balancer::setTeams(unsigned int matrix)
{
    int team1pos=0;int team2pos=0;
    for(int i=0;i<12;i++){
        if(getbit(matrix,i)==0) {
            team1[team1pos]=unbalanced[i];
            team1pos++;
        }
        else{
            team2[team2pos]=unbalanced[i];
            team2pos++;
        }
    }
}

int Balancer::getbit(unsigned int X, int n)
{
    if(n<16){
        return (X >> n) & 1;
    }
}

int Balancer::getsize()
{
    return size;
}

bool Balancer::check6bits(int X)
{
    int count=0;
    for(int i=0;i<12;i++){
        if(getbit(X,i)==1)count++;
    }
    if(count==6)return true;
    else return false;
}

double Balancer::average(std::array<Player, 6> team)
{
    double total=0;
    for(int i=0;i<6;i++){
        total+=team[i].mmr;
    }
    return total/6;
}

double Balancer::getteam1SR()
{
    return average(team1);
}

double Balancer::getteam2SR()
{
    return average(team2);
}
