// Fairy Derived Class Of Warrior
#ifndef FAIRY_H
#define FAIRY_H

#include "warrior.h"

class Fairy : public Warrior {
    public:
        Fairy(std::string fairy_name); // Fairy Name Constructor Delegated To Base Main Constructor
};

#endif // FAIRY_H
