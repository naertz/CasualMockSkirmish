// Serpant Derived Class Of Warrior
#ifndef SERPENT_H
#define SERPENT_H

#include "../warrior.h"

class Serpent : public Warrior {
    public:
        Serpent(std::string serpent_name); // Serpent Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);         // Populate Serpent Attacks
};

#endif // SERPENT_H
