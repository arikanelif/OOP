/* 
Elif Arıkan
ID:150180010
*/
#ifndef   ELVES_H  
#define   ELVES_H



#include <iostream>
#include <string>

#include "Faction.h"
using namespace std;

class Elves:public Faction{
public:
    Elves(string, int, int, int, int);
    Elves(const Elves&);
    void PerformAttack();
    void ReceiveAttack(int, string);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};

#endif