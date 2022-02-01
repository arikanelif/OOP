/*
Crn:21153
Elif ARIKAN
ID:150180010
*/

#pragma once
#include "Person.h"
#include "Mission.h"


#include <iostream>
#include <cstdlib>

using namespace std;

class Agency{
    string name;
    int cash;
    int ticketPrice;
    Mission* completedMissions;
    Mission* nextMissions;
public:
    Agency(){completedMissions=NULL ;nextMissions=NULL; };
    ~Agency(){delete completedMissions; delete nextMissions;};
    Agency(string , int , int);
    void addMission(Mission& );
    void executeNextMission();
    void setTicketPrice(int inprice){ ticketPrice=inprice;};
    int getTicketPrice(){return ticketPrice;};
    friend ostream &operator<<(ostream&, const Agency&);  // writen to use Agency attribitiues.
};