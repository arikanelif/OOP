/*
Crn:21153
Elif ARIKAN
ID:150180010
*/

#include "Person.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Passenger :: Passenger(string in_name , string in_surname, int in_cash):Person(in_name,in_surname)
{
    if(in_cash<0)
    {
        cash=0;
        cerr <<"Passenger cash can’t be negative. It is set to 0." << endl;
    }
    else
    {    
        cash = in_cash;
    }

}

bool Passenger :: buyTicket(int ticketPrice)
{
    if(cash >= ticketPrice)
    {
        ticket = true;
        cash -= ticketPrice;
    }
    return ticket;
}
Astronaut :: Astronaut(string in_name , string in_surname, int in_num):Person(in_name,in_surname)
{
    if(in_num<0)
    {
        cerr << "Number of missions that astronaut completed can't be negative. It is set to 0."<< endl;
        numMissions=0;
    }
    else
        numMissions = in_num;
}
void Astronaut :: completeMission()
{
    numMissions++;
}