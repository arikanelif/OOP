/* 
Elif Arıkan
ID:150180010
*/
#ifndef   ORCS_H  
#define   ORCS_H

#include <iostream>
#include <string>

#include "Faction.h"


using namespace std;

class Orcs:public Faction{
public:
    Orcs(string, int, int, int, int);
    Orcs(const Orcs&);
    void PerformAttack();
    void ReceiveAttack(int, string);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};

#endif