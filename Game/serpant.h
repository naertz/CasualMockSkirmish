// Serpant Derived Class Of Warrior
#ifndef SERPANT_H
#define SERPANT_H

#include "warrior.h"

class Serpant : public Warrior {
    public:
        Serpant(std::string serpant_name); // Serpant Name Constructor Delegated To Base Main Constructor
};

#endif // SERPANT_H
