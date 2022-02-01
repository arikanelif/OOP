//////////////////////////////////
/*         ELİF ARIKAN        */
/*         150180010          */
//////////////////////////////////



#ifndef _GreatWarrior_           // to include only once
#define _GreatWarrior_
#include <iostream>
#include <fstream>


class Land{
    
public:
    char* name;
    char* holding;
    Land *next;
    Land(char* holding1 ="village", Land *next=NULL) ; //constructor
    Land (char* , char*); //copy const
    Land(Land&);
    const Land& operator=(const Land&);
};

class Character {
    
    
public:
    char* name;
    int manpower;
    int gold;
    int numOfLands;
    Land* lands;
    Character() :manpower(3) , gold(20), numOfLands(1){}; // constructor
    Character(const char* ,int , int , int  ) ; //copy const 
    Character(Character&);
    ~Character(); // destructors
    void getTaxes();
    void addLand(Land&);
    void removeLand(Land&);
    const Character& operator=(const Character &);
};

class CharacterList {
    int size=0;
    Character* list; 
    friend void listCharacters(CharacterList&);
    friend void listLands(CharacterList&) ;
public:
    CharacterList(); //default constructors
    void addCharacter(Character&);
    void delCharacter(Character&);
    void getPlayer();
    Character getLandOwner(char*); 
    ~CharacterList() ; // destructors
};
#endif