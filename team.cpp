#include "team.h"

Team::Team(QListWidget *listwidget, QLabel *label)
{
    widget=listwidget;
    SRlabel=label;
    calculatemethod=0;
}

int Team::getsize()
{
    return players.size();
}

Player *Team::getplayer(int i)
{
    return players[i];
}

void Team::setplayer(int i, Player *p)
{
    players[i]=p;
    renewSRlabel();
    renewlistwidget();
}

void Team::addplayer(Player *newplayer)
{
    players.append(newplayer);
    widget->addItem(newplayer->text());
    renewSRlabel();
}

double Team::countSR()
{
    double total;
    double tsize=getsize();
    if(calculatemethod==0){//arithmetic average
        total=0;
        for(int i=0;i<players.length();i++){
            total+=players[i]->getSR();
        }
        return total/tsize;
    }
    else if(calculatemethod==1){//geometric average
        total=1;
        for(int i=0;i<players.length();i++){
            total*=players[i]->getSR();
        }
        return pow(total,1/tsize);
    }
    else if(calculatemethod==2){//both
        double Atotal=0;
        double Gtotal=1;
        for(int i=0;i<players.length();i++){
            Gtotal*=players[i]->getSR();
        }
        for(int i=0;i<players.length();i++){
            Atotal+=players[i]->getSR();
        }
        total=(Atotal/getsize()+pow(Gtotal,1/tsize))/2;
        return total;
    }
}

void Team::setcalculatemethod(int n)
{
    calculatemethod=n;
}

QList<Player *> Team::getlist()
{
    return players;
}

void Team::setlist(QList<Player *> l)
{
    players=l;
    renewSRlabel();
    renewlistwidget();
}

void Team::renewSRlabel()
{
    if(getsize()>0)SRlabel->setText(QString::number(countSR()));
    else SRlabel->setText(QString::number(0));
}

void Team::clear()
{
    players.clear();
    widget->clear();
    renewSRlabel();
}

Player *Team::pop(int i)
{
    Player* p=players[i];
    players.removeAt(i);
    renewSRlabel();
    renewlistwidget();
    return p;
}

void Team::renewlistwidget()
{
    widget->clear();
    foreach (Player* a, players) {
        widget->addItem(a->text());
    }
}

