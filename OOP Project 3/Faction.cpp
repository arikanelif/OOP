/* 
Elif Arıkan
ID:150180010
*/
#include "Faction.h"
#include "Dwarves.h"
#include "Orcs.h"
#include "Elves.h"

#include <iostream>
#include <string>

Faction::Faction(string in_name ,int in_number_of_units, int in_attack_point,
                int in_health_point, int  in_unit_regeneration_number)
{
    name=in_name;
    number_of_units=in_number_of_units;
    attack_point=in_attack_point;
    health_point=in_health_point;
    unit_regeneration_number=in_unit_regeneration_number;
    total_health=number_of_units*health_point;
    is_alive=true;
    first_enemy=NULL;
    second_enemy=NULL;
}
void Faction:: AssignEnemies(Faction* fnct1, Faction* fnct2)
{
    first_enemy=fnct1;
    second_enemy=fnct2;
}
void Faction::Print()
{
    cout << "Faction Name:         " << name << endl; 
    if(is_alive)
        cout << "Status:               Alive" << endl;
    else
        cout << "Status:               Defeated" << endl;
    cout << "Number of Units:      " << number_of_units << endl;
    cout << "Attack Point:         " << attack_point << endl;
    cout << "Health Point:         " << health_point << endl;
    cout << "Unit Regen Number     " << unit_regeneration_number << endl;
    cout << "Total Faction Health: " << total_health << endl;
}
void Faction::EndTurn()
{
    if(number_of_units<0)
    {
        number_of_units=0;
        is_alive=false;
    }
    else if(number_of_units==0)
        is_alive=false;
    if(is_alive)
        number_of_units += unit_regeneration_number;
}