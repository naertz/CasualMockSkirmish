// Knight Derived Class Of Warrior

#ifndef KNIGHT_H
#define KNIGHT_H

#include "../warrior.h"

class Knight : public Warrior {
    public:
        Knight();                         // Default Constructor Delegated To Base Main Constructor
        Knight(std::string knight_name);  // Knight Name Constructor Delegated To Base Main Constructor
};

#endif // KNIGHT_H
