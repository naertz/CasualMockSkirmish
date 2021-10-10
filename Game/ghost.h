// Ghost Derived Class Of Warrior
#ifndef GHOST_H
#define GHOST_H

#include "warrior.h"

class Ghost : public Warrior {
    public:
        Ghost(std::string ghost_name); // Ghost Name Constructor Delegated To Base Main Constructor
};

#endif // GHOST_H
