/* 
Elif Arıkan
ID:150180010
*/
#ifndef   FACTION_H  
#define   FACTION_H

#include <iostream>
#include <string>

using namespace std;

class Faction{
    friend class Merchant;
protected:
    string name;
    Faction * first_enemy;
    Faction * second_enemy;
    int number_of_units;
    int attack_point;
    int health_point;
    int  unit_regeneration_number;
    int total_health;
    bool is_alive;
public:
    Faction(string, int, int, int, int);
    int getAttackPoint(){ return attack_point;}
    string getName(){return name;}
    bool IsAlive(){return is_alive;}
    void AssignEnemies(Faction* ,Faction* );
    virtual void PerformAttack() = 0; //pure method
    virtual void ReceiveAttack(int, string) = 0; //pure method
    virtual int PurchaseWeapons(int) = 0;  //pure method
    virtual int PurchaseArmors(int) = 0;  //pure method 
    virtual void Print();
    void EndTurn();
};
 
#endif