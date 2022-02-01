/* 
Elif Arıkan
ID:150180010
*/
#ifndef   DWARVES_H  
#define   DWARVES_H

#include <iostream>
#include <string>
#include "Faction.h"



using namespace std;

class Dwarves:public Faction{
public:
    Dwarves(string, int, int, int, int);
    Dwarves(const Dwarves&);
    void PerformAttack();
    void ReceiveAttack(int, string);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};

#endif