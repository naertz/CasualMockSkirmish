// Ghost Derived Class Of Warrior
// Hard to do damage to but does little damage.

#ifndef GHOST_H
#define GHOST_H

#include "../warrior.h"

class Ghost : public Warrior {
    public:
        Ghost();                        // Default Constructor Delegated To Base Main Constructor
        Ghost(std::string ghost_name);  // Ghost Name Constructor Delegated To Base Main Constructor
};

#endif // GHOST_H
