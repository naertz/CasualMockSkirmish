// Knight Derived Class Of Warrior

#ifndef KNIGHT_H
#define KNIGHT_H

#include "../warrior.h"

class Knight : public Warrior {
    public:
        Knight(std::string knight_name); // Knight Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);     // Populate Knight Attacks
};

#endif // KNIGHT_H
