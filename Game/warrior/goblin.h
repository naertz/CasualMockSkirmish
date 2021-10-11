// Goblin Derived Class Of Warrior
#ifndef GOBLIN_H
#define GOBLIN_H

#include "../warrior.h"

class Goblin : public Warrior {
    public:
        Goblin(std::string goblin_name); // Goblin Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);       // Populate Goblin Attacks
};

#endif // GOBLIN_H
