#include "balancer.h"


Balancer::Balancer(Team *t1, Team *t2)
{
    size=0;
    calculatemethod=0;
    team1=t1;team2=t2;
    t1->setcalculatemethod(0);
    t2->setcalculatemethod(0);
}

void Balancer::addPlayer(QString str, int n)
{
    if(size<12){
        Player* p=new Player(str,n);
        unbalanced.append(p);
        if(team1->getsize()<6){
            team1->addplayer(p);
        }
        else{
            team2->addplayer(p);
        }
        size++;
    }
}

void Balancer::BalanceTeams()
{
    if (size==12){
        QList<Player*> tempteam1,tempteam2;
        unsigned int matrix=63;
        setTeams(matrix,tempteam1,tempteam2);
        double bestdifference=abs(average(tempteam1)-average(tempteam2));
        double difference=bestdifference;
        qDebug()<<"Balancing"<<difference;
        team1->setlist(tempteam1);
        team2->setlist(tempteam2);
        while(matrix<64512){
            matrix++;
            if(check6bits(matrix)){
                setTeams(matrix,tempteam1,tempteam2);
                difference=abs(average(tempteam1)-average(tempteam2));
                if(difference<bestdifference){
                    qDebug()<<"New best "<<matrix<<difference;
                    bestdifference=difference;
                    team1->setlist(tempteam1);
                    team2->setlist(tempteam2);
                }
            }
        }
    }
}

void Balancer::setTeams(unsigned int matrix, QList<Player *> &t1, QList<Player *> &t2)
{
    t1.clear();t2.clear();
    for(int i=0;i<12;i++){
        if(getbit(matrix,i)==0) t1.append(unbalanced[i]);
        else t2.append(unbalanced[i]);
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

double Balancer::average(QList<Player*> team)
{
    double total;
    if(calculatemethod==0){//arithmetic average
        total=0;
        for(int i=0;i<6;i++){
            total+=team[i]->getSR();
        }
        return total/6;
    }
    else if(calculatemethod==1){//geometric average
        total=1;
        for(int i=0;i<6;i++){
            total*=team[i]->getSR();
        }
        return pow(total,0.1666667);
    }
    else if(calculatemethod==2){//both
        double Atotal=0;
        double Gtotal=1;
        for(int i=0;i<6;i++){
            Gtotal*=team[i]->getSR();
        }
        for(int i=0;i<6;i++){
            Atotal+=team[i]->getSR();
        }
        total=(Atotal/6+pow(Gtotal,0.1666667))/2;
        return total;
    }
}

double Balancer::getteam1SR()
{
    return team1->countSR();
}

double Balancer::getteam2SR()
{
    return team2->countSR();
}

void Balancer::setcalculatemethod(int method)
{
    calculatemethod=method;
    team1->setcalculatemethod(method);
    team1->renewSRlabel();
    team2->setcalculatemethod(method);
    team2->renewSRlabel();
}

void Balancer::clear()
{
    unbalanced.clear();
    size=0;
    team1->clear();
    team2->clear();
}

void Balancer::swap(int i1, int i2)
{
    Player* p=team2->getplayer(i2);
    team2->setplayer(i2,team1->getplayer(i1));
    team1->setplayer(i1,p);
}

Team *Balancer::getteam1()
{
    return team1;
}

Team *Balancer::getteam2()
{
    return team2;
}

void Balancer::remove(Player *p)
{
    for(int i=0;i<unbalanced.size();i++){
        if(unbalanced[i]==p){
            unbalanced.removeAt(i);
            size--;
        }
    }
}

