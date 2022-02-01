/*
Crn:21153
Elif ARIKAN
ID:150180010
*/

#pragma once
#include "Person.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class Mission{
    friend class Agency;
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed;
    Passenger *passengers;
    Astronaut *crew;
    int static numMissions;
public:
    Mission* next=NULL;
    Mission(){ passengers=NULL; crew = NULL;}
    //~Mission() { delete passengers; delete crew ;}
    Mission(string, int, int); //take attributies name, cost , faultProbability
    void setName(string inname){name = inname;}  //setter method for name
    string getName (){return name;}  //getter method for name
    int getnumMission(){ return numMissions;}  //getter method for numMission
    int getMissionNum(){return missionNumber;}  //getter method for missionNumber
    int getCost(){return cost;}  //getter method for cost
    Mission operator+=(Astronaut* const);  
    Mission operator+=(Passenger* const);
    bool executeMission();
    int calculateProfit(int);
};