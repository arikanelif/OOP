/*
Crn:21153
Elif ARIKAN
ID:150180010
*/

#include "Agency.h"
#include "Mission.h"
#include "Person.h"


#include <iostream>
#include <cstdlib>

using namespace std;

Agency :: Agency (string inname, int incash, int inticketPrice){
    name=inname;
    cash=incash;
    completedMissions=NULL ;
    nextMissions=NULL; 
    if (inticketPrice < 0)
    {   
        cerr << "Ticket price can't be negative. It is set to 0." << endl;
        ticketPrice=0;
    }
    else 
        ticketPrice=inticketPrice;

}
ostream& operator<<(std::ostream &output, const Agency &agency) 
{
    output << "Agency name: " << agency.name <<" , Total cash: " << agency.cash << ", Ticket Price: " << agency.ticketPrice << endl;
    output << "Next Missions:" << endl;
    if (!agency.nextMissions)
        cout << "No missions available." << endl;
    else
    {
        Mission* temp0 = agency.nextMissions;
        while (temp0)
        {
            output << "Mission number: " << temp0->getMissionNum() <<" Mission name: " << temp0->getName() << " Cost: " << temp0->getCost() << endl;
            temp0=temp0->next;
        }
    }    
    output << "Completed Missions:" << endl;
    if(!agency.completedMissions)
        output << "No missions completed before." << endl;
    else
    {
        Mission * temp1= agency.completedMissions;
        while(temp1)
        {
            output << "Mission number: "<< temp1->getMissionNum() << " Mission name: "<< temp1->getName() << " Cost: "<< temp1->getCost() << endl;
            temp1=temp1->next;
        }
    }
    return output;
}
void Agency ::addMission(Mission& newmission)
{
    if(!nextMissions)
        nextMissions= &newmission; // eğer nextmission listesi boşsa yeni mission u listenin başına ekler.
    else
    {
        Mission* tempadd= nextMissions;
        while (tempadd->next)
        {
            tempadd=tempadd->next;
        }
        tempadd->next=&newmission;        // yeni eklenen mission ı nextmission listesinin sonuna ekler.
    }
}

void Agency::executeNextMission()
{
    if(nextMissions== NULL)
        cout << "No available mission to execute!" << endl;
    else
    {
        Mission *temp= nextMissions;
        
        if(temp->executeMission())
        {
            Mission *pre=new Mission(temp->name, temp->cost, temp->faultProbability);
            pre->missionNumber=temp->missionNumber;
            if(!completedMissions) // tamamlanmış  görev yoksa completedmission listesinin başına ekler.
            {
                completedMissions=pre;
            }   
            else  // tamamlanmış görev listesinin başına yeni görevi ekler .
            {
                Mission *tmp;
                tmp=completedMissions;
                while(tmp->next)
                {
                    tmp=tmp->next;
                }
                tmp->next=pre;
            }
            nextMissions=nextMissions->next;
            cash += temp->calculateProfit(ticketPrice);
            delete temp;
        }
        else
        {
            nextMissions=nextMissions->next; // next mission un ilk elemanını 2. elemanı olacak şekilde eşitledik.
            if(nextMissions)
            {
                Mission *temp2= nextMissions; // next mission un yeni hali içinde dolaşmak için bir temp2 tanımladım.
                while (temp2->next) // listenin sonuna gider.
                {
                    temp2=temp2->next;
                } 
                temp2->next=temp; // listenin en sonuna baştan beri işlem yaptığımız görevi (temp) ekledim.
                cash += temp->calculateProfit(ticketPrice);
                delete temp;
                delete temp2;
            }
            else
            {   
                nextMissions=temp;
                cash += temp->calculateProfit(ticketPrice);
                delete temp;
            }
        }
    }
    
    
}