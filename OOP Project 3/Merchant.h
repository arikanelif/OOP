/* 
Elif Arıkan
ID:150180010
*/
#ifndef   MERCHANT_H 
#define   MERCHANT_H

#include <iostream>
#include <string>

#include "Faction.h"

using namespace std;


class Merchant{
    Faction* first_faction;
    Faction* second_faction;
    Faction* third_faction;
    int starting_weapon_point;
    int starting_armor_point;
    int revenue;
    int weapon_point;
    int armor_point;
public:
    Merchant(int, int);
    int GetRevenue(){return revenue;}
    int GetWeaponPoints(){return weapon_point;}
    int GetArmorPoints(){return armor_point;}
    void AssignFactions(Faction*, Faction*, Faction*);
    bool SellWeapons(string, int);
    bool SellArmors(string, int);
    void EndTurn();
};

#endif