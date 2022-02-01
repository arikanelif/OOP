/*
Crn:21153
Elif ARIKAN
ID:150180010
*/

#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Person{
    string name;
    string surname;
public :
   // void setname(const string & inname){name = inname;}; //setter method for name
    string getname(){return name;} // getter method for name
    //void setsurname(string insurname){surname=insurname;};  //setter method for surname
    string getsurname(){return surname;}//getter method for surname
    Person(string inname, string insurname){name= inname; surname = insurname;}// default constructor 
};


class Passenger : public Person{ 
    friend class Mission;
    int cash;
    bool ticket=false;
    Passenger* next=NULL;
public:
    Passenger(string inname, string insurname):Person(inname, insurname), cash(0){}
    Passenger(string , string , int ); // constructor with cash attributies
    //~Passenger(){delete next;};
    int getCash(){return cash;}
    bool getTicket(){return ticket;}
    bool buyTicket(int); 
};


class Astronaut : public Person{
    friend class Mission;
    int numMissions; 
    Astronaut* next=NULL;
public :
    Astronaut(string inname, string insurname) :Person(inname, insurname), numMissions(0){}
    Astronaut(string, string , int);
    //~Astronaut(){delete next;};
    void completeMission();
    int getNummission(){return numMissions;}
};
