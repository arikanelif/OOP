/* 
Elif Arıkan
ID:150180010
*/
#include "Orcs.h"
#include "Merchant.h"


#include <iostream>
#include <string>

Orcs :: Orcs(string in_name ,int in_number_of_units, int in_attack_point,
            int in_health_point, int  in_unit_regeneration_number )    
            :Faction(in_name, in_number_of_units, in_attack_point, in_health_point, 
            in_unit_regeneration_number) {}
Orcs :: Orcs(const Orcs& newOrcs) 
            :Faction(newOrcs.name, newOrcs.number_of_units, newOrcs.attack_point, 
            newOrcs.health_point, newOrcs.unit_regeneration_number) {}

void Orcs::PerformAttack()
{
    int damage= number_of_units * attack_point;
    if(!first_enemy->IsAlive() && second_enemy->IsAlive()) //first_enemy has assigned with Elves already ,second_enemy has assigned with Dwarves already
    {
        second_enemy->ReceiveAttack(damage, "Orcs");
    }
    else if( first_enemy->IsAlive() && !second_enemy->IsAlive())
    {
        first_enemy->ReceiveAttack(damage, "Orcs");
    }
    else if(first_enemy->IsAlive() && second_enemy->IsAlive() )
    {
        string str=first_enemy->getName();
        switch (str[0])
        {
        case 'E':
            first_enemy->ReceiveAttack(damage*0.7 , "Orcs");
            second_enemy->ReceiveAttack(damage*0.3, "Orcs");
            break;
        case 'D':
            first_enemy->ReceiveAttack(damage *0.3, "Orcs");
            second_enemy->ReceiveAttack(damage*0.7, "Orcs");
            break;
        
        }
    }

}
void Orcs::ReceiveAttack(int attack, string name)
{
    if(name == "Elves")
        attack *= 0.75;
    if( name == "Dwarves")
        attack *= 0.8;

    float number = (attack/ health_point);
    if (number >0.0 && number <1.0)   
        number_of_units -=1;
    else
        number_of_units -= (attack/ health_point);
}
int Orcs::PurchaseWeapons(int weapon)
{
    attack_point += (weapon*2);
    return (20*weapon);
}
int Orcs::PurchaseArmors(int armor)
{
    health_point += (armor*3);
    return armor;
}
void Orcs::Print()
{
    cout<<"\"Stop running, you'll only die tired!\"" << endl;
    cout << "Faction Name:         " << name << endl; 
    if(is_alive)
        cout << "Status:               Alive" << endl;
    else
        cout << "Status:               Defeated" << endl;
    cout << "Number of Units:      " << number_of_units << endl;
    cout << "Attack Point:         " << attack_point << endl;
    cout << "Health Point:         " << health_point << endl;
    cout << "Unit Regen Number     " << unit_regeneration_number << endl;
    cout << "Total Faction Health: " << health_point*number_of_units << endl;
}
