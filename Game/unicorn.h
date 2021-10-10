// Unicorn Derived Class Of Warrior
#ifndef UNICORN_H
#define UNICORN_H

#include "warrior.h"

class Unicorn : public Warrior {
    public:
        Unicorn(std::string unicorn_name); // Unicorn Name Constructor Delegated To Base Main Constructor
};

#endif // UNICORN_H
