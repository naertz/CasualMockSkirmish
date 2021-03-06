// Sorcerer Derived Class Of Warrior

#ifndef SORCERER_H
#define SORCERER_H

#include "../warrior.h"

class Sorcerer : public Warrior {
    public:
        Sorcerer();                           // Default Constructor Delegated To Base Main Constructor
        Sorcerer(std::string sorcerer_name);  // Sorcerer Name Constructor Delegated To Base Main Constructor
};

#endif // SORCERER_H
