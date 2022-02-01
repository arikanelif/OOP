/* 
Elif Arıkan
ID:150180010
*/
#include "Merchant.h"
#include "Orcs.h"
#include "Dwarves.h"
#include "Elves.h"


#include <iostream>
#include <string>

Merchant::Merchant(int startingWeaponPoints, int startingArmorPoints)
{
    starting_weapon_point=startingWeaponPoints;
    starting_armor_point=startingArmorPoints;
    revenue=0;
    weapon_point=starting_weapon_point;
    armor_point=starting_armor_point;
}
void Merchant:: AssignFactions(Faction* orcs, Faction* dwarves, Faction* elves)
{
    first_faction=orcs; 
    second_faction=dwarves;
    third_faction=elves;
}


bool Merchant :: SellWeapons(string name, int weapon)
{
    if(weapon>weapon_point)
    {
        cout << "You try to sell more weapons than you have in possession." << endl;
        return false;
    }
    if(first_faction->getName()== name )
    {
        if(!first_faction->IsAlive())
        {
            cout<< "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        else
        {
            revenue += first_faction->PurchaseWeapons(weapon);
            cout << "Weapons sold!" <<endl;
            weapon_point-=weapon;
            return true;
        }
    }
    else if(second_faction->getName()== name)
    {
        if(!second_faction->IsAlive())
        {
            cout<< "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        else
        {
            revenue += second_faction->PurchaseWeapons(weapon);
            cout << "Weapons sold!" <<endl;
            weapon_point-=weapon;
            return true;
        }
    }
    else if(third_faction->getName()== name)
    {
        if(!third_faction->IsAlive())
        {
            cout<< "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        else
        {
            revenue += third_faction->PurchaseWeapons(weapon);
            cout << "Weapons sold!" <<endl;
            weapon_point-=weapon;
            return true;
        }
    }

}
bool Merchant :: SellArmors(string name, int armor)
{
    if(armor > armor_point)
    {
        cout << "You try to sell more armors than you have in possession." << endl;
        return false;
    }
    if(first_faction->getName()== name)
    {
        if(!first_faction->IsAlive())
        {
            cout<< "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        else
        {
            revenue += first_faction->PurchaseArmors(armor);
            cout << "Armors sold!" <<endl;
            armor_point -= armor;
            return true;
        }
    }
    else if(second_faction->getName()== name)
    {
        if(!second_faction->IsAlive())
        {
            cout<< "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        else
        {
            revenue += second_faction->PurchaseArmors(armor);
            cout << "Armors sold!" <<endl;
            armor_point -= armor;
            return true;
        }
    }
    else if(third_faction->getName()== name)
    {
        if(!third_faction->IsAlive())
        {
            cout<< "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        else
        {
            revenue += third_faction->PurchaseArmors(armor);
            cout << "Armors sold!" <<endl;
            armor_point -= armor;
            return true;
        }
    }
}
void Merchant ::  EndTurn()
{
    armor_point=starting_armor_point;
    weapon_point=starting_weapon_point;
}