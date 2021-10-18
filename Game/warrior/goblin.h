// Goblin Derived Class Of Warrior

#ifndef GOBLIN_H
#define GOBLIN_H

#include "../warrior.h"

class Goblin : public Warrior {
    public:
        Goblin();                         // Default Constructor Delegated To Base Main Constructor
        Goblin(std::string goblin_name);  // Goblin Name Constructor Delegated To Base Main Constructor
};

#endif // GOBLIN_H
