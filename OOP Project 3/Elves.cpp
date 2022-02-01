/* 
Elif Arıkan
ID:150180010
*/
#include "Elves.h"
#include "Merchant.h"

#include <iostream>
#include <string>

using namespace std;

Elves :: Elves(string in_name ,int in_number_of_units, int in_attack_point, 
        int in_health_point, int  in_unit_regeneration_number )
        :Faction(in_name, in_number_of_units, in_attack_point, 
            in_health_point, in_unit_regeneration_number) {}

Elves :: Elves(const Elves& newElves) 
        :Faction(newElves.name, newElves.number_of_units, newElves.attack_point, 
            newElves.health_point, newElves.unit_regeneration_number) {}

void Elves::PerformAttack()  // first_enemy : orcs , second_enemy: dwarves
{
    int damage= number_of_units*attack_point;
    if(!first_enemy->IsAlive() && second_enemy->IsAlive() )
    {
        string str=second_enemy->getName();
        switch (str[0])
        {
        case 'D':
            second_enemy->ReceiveAttack(damage*1.5, "Elves");
            break;
        case 'O':
            second_enemy->ReceiveAttack(damage, "Elves");
            break;
        }
    } 
    else if (first_enemy->IsAlive() && !second_enemy->IsAlive() )
    {
        string str =first_enemy->getName();
        switch (str[0])
        {
        case 'D':
            first_enemy->ReceiveAttack(damage*1.5, "Elves");
            break;
        case 'O':
            first_enemy->ReceiveAttack(damage, "Elves");
            break;
        }
    }
    else if (first_enemy->IsAlive() && second_enemy->IsAlive() )
    {
        string str=first_enemy->getName();
        switch (str[0])
        {
        case 'D':
            first_enemy->ReceiveAttack(damage *0.6, "Elves");
            second_enemy->ReceiveAttack(damage*0.6, "Elves");
            break;
        case 'O':
            first_enemy->ReceiveAttack(damage*0.6 , "Elves");
            second_enemy->ReceiveAttack(damage*0.6, "Elves");
            break;
        }
    }

}
void Elves ::ReceiveAttack(int attack, string name)
{
    
    if( name == "Orcs")
        attack *= 1.25;
    else if( name == "Dwarves")
        attack *= 0.75;
    float number = (attack/ health_point);
    if (number > 0.0 && number <1.0)   
        number_of_units -=1;
    else
        number_of_units -= (attack/ health_point);
}
int Elves::PurchaseWeapons(int weapon)
{
    attack_point += (weapon*2);
    return (15*weapon);
}
int Elves::PurchaseArmors(int armor)
{
    health_point += (armor*4);
    return (5*armor);
}
void Elves::Print()
{
    cout<<"\"You cannot reach our elegance.\"" << endl;
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