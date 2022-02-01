/*
Crn:21153
Elif ARIKAN
ID:150180010
*/

#include "Mission.h"
#include "Person.h"

#include <iostream>
#include <cstdlib>


using namespace std;

Mission :: Mission(string in_name , int in_cost ,int in_faultP)
{
    string str= in_name.substr(0,2);
    size_t pos = in_name.find("-");
    
    if(str[0] == toupper(str[0]) && str[1] == toupper(str[1]) && pos==2 )
    {
        name = in_name;
    }
    else
    {
        cout << "Given name does not satisfy the mission naming convention. Please set a new name!"<< endl;
        name = "AA-00" ;
    }
    cost = in_cost;
    faultProbability=in_faultP;
    completed=false;
    missionNumber=++numMissions;
    passengers=NULL;
    crew = NULL;
    
}
Mission Mission::operator+=(Astronaut* const ast)
{
    Astronaut* pre;
    pre=new Astronaut(ast->getname(),ast->getsurname(), ast->getNummission());
    if(!this->crew)
    {
        this->crew= pre;
    }
    else
    {
        Astronaut *tmp;
        tmp=this->crew;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        tmp->next=pre;
    }
    return *this;
}
Mission Mission :: operator+=( Passenger* const pss)
{
    if(pss->getTicket()== false)
        cout << "Passenger " << pss->getname() << " " << pss->getsurname() << " does not have a valid ticket!" << endl;
    else
    {
        Passenger *pre;
        pre=new Passenger(pss->getname(), pss->getsurname(),pss->getCash());
        pre->ticket=pss->ticket;

        if(this->passengers==NULL)
            this->passengers= pre;
            //this->passengers->ticket = pss->getTicket() ;
        else
        {
            Passenger *tmp;
            tmp=this->passengers;
            while(tmp->next)
            {
                tmp=tmp->next;
            }
            tmp->next=pre;
        }
    }
    return *this;
}
bool Mission :: executeMission(){
    int random_fa = rand()%100 ;
    if(faultProbability==100 || random_fa < faultProbability)  //başarısızlık durumu 
    {   
        cout << "MISSION " << name << " FAILED!" << endl;
        cout << "Agency reschedules the mission." << endl;
        return completed;
    }
    else                            // başarı durumu
    {
        cout << "MISSION " << name << " SUCCESSFUL!" << endl;
        Astronaut* tempcrew = crew;
        while(tempcrew)
        {
            tempcrew->completeMission();
            cout << "Astronaut "<< tempcrew->getname() << " " << tempcrew->getsurname() <<" successfully completed "<< tempcrew->getNummission() <<" missions." << endl;
            tempcrew=tempcrew->next;
        }
        completed=true;
    }
    return completed;
}

int Mission :: calculateProfit(int price){
    int profit=0; // görevin kazancı başta 0 olarak ayarladım.
    if (completed== true) //görev başarılıysa
    {
        int i=0; // number of passengers
        while ( passengers )
        {
            passengers=passengers->next;
            i++;
        } 
        profit= price*i;
    }
    profit -= cost; // görev sonunda kardan maliyet çıkarılır.
    return profit;
}

