//////////////////////////////////
/*         ELİF ARIKAN        */
/*         150180010          */
//////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include "GreatWarrior.h"
#include <string>

using namespace std; // I added for using cout and cin

Land :: Land(char* landname, char* newholding ){
    name =new char[strlen(landname)+1];
    strcpy(name, landname);
    holding =new char[strlen(holding)+1];
    strcpy(holding , newholding);
}
Land :: Land(Land& newLand){
    name =new char[strlen(newLand.name)+1];
    strcpy(name, newLand.name);
    holding =new char[strlen(newLand.holding)+1];
    strcpy(holding , newLand.holding);    
} 
const Land& Land:: operator=(const Land& la)
{
    name=new char[strlen(la.name)+1];
    strcpy(name, la.name);
    holding = new char[strlen(la.holding)+1];
    strcpy(holding,la.holding);
    next=la.next;
    return *this;
}
void Character :: getTaxes(){
    Land* temp;
    temp = lands;
    while (temp)
    {
        if(temp->holding=="city")
            gold+=10;
        else if (temp->holding=="village")
            gold+=5;
        else if (temp->holding=="castle")
            gold+=7;
        temp=temp->next;
    }

    
}
void Character::addLand( Land& NewL){
    if(!lands){
        lands=&NewL;
    }
    else
    {
        NewL.next=lands;
        lands=&NewL;
    }
    numOfLands++;

}
void Character::removeLand(Land& RemovedL){
    Land* temp= new Land;
    temp=lands;
    
    if(lands && temp->name==RemovedL.name)
    {
        Land* newhead= temp->next;
        delete temp;
        lands=newhead;
        return;
    }
    Land * prev= new Land;
    while (temp->name!= RemovedL.name && temp)
    {
        prev=temp;
        temp=temp->next;
    }
    if(!temp) return; // aranan değer yok
    prev->next =temp->next;
    delete temp;
    numOfLands--;
    
}
Character :: Character(const char* newname, int new_manpower , int new_gold, int new_numOfLands ){ //copy cons
    name =new char[strlen(newname)+1];
    strcpy(name , newname);
    manpower=new_manpower;
    gold=new_gold;
    numOfLands=new_numOfLands;
} 
Character :: Character(Character& chr){  // copy constructor
    name =new char[strlen(chr.name)+1];
    strcpy(name , chr.name);
    manpower=chr.manpower;
    gold=chr.gold;
    numOfLands=chr.numOfLands;

}
Character::~Character() // destructors
{
    
}
const Character& Character::operator=(const Character& ch) 
{
    name= new char[strlen(ch.name)+1];
    strcpy(name, ch.name);
    numOfLands=ch.numOfLands;
    manpower=ch.manpower;
    gold=ch.gold;
    lands=ch.lands;
    return * this;

}
CharacterList :: CharacterList(){
   // CharacterList * characters = new CharacterList;
   //Character* list;
}

void CharacterList ::addCharacter(Character& chr){
    list[size] = chr;
    size++;
}

void CharacterList::delCharacter(Character& chr){
    for(int i=0 ; i<size ; i++){
        if(strcmp(list[i].name, chr.name)==0){
            while (i!=size)
            {
               list[i]=list[i+1];
               i++;
            }
        }
    }
    size--;
}
void CharacterList::getPlayer(){
    
};
Character CharacterList:: getLandOwner(char* searchland){
    for(int i=0; i<size ; i++)
    {   
        while (list[i].lands)
        {
            if(strcmp(list[i].lands->name , searchland)==0) return list[i];
            list[i].lands=list[i].lands->next;
        }
    }
};
CharacterList:: ~CharacterList(){
    delete list;
}