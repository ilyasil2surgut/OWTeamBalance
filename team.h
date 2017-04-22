#ifndef TEAM_H
#define TEAM_H
#include <player.h>
#include <QListWidget>
#include <QLabel>

class Team
{
public:
    Team(QListWidget*,QLabel*);
    int getsize();
    Player *getplayer(int i);
    void setplayer(int i,Player *);
    void addplayer(Player*);
    double countSR();
    void setcalculatemethod(int);
    QList<Player*> getlist();
    void setlist(QList<Player*>);
    void renewSRlabel();
    void clear();
    Player* pop(int);
private:

    void renewlistwidget();
    QListWidget* widget;
    QLabel* SRlabel;
    QList<Player*> players;
    int calculatemethod;
};

#endif // TEAM_H
