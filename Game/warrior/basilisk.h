// Basilisk Derived Class Of Warrior

#ifndef BASILISK_H
#define BASILISK_H

#include "../warrior.h"

class Basilisk : public Warrior {
    public:
        Basilisk();                           // Default Constructor Delegated To Base Main Constructor
        Basilisk(std::string basilisk_name);  // Basilisk Name Constructor Delegated To Base Main Constructor
};

#endif // BASILISK_H
