#ifndef SORCERER_H
#define SORCERER_H

#include "warrior.h"

class Sorcerer : public Warrior {
    public:
        Sorcerer(std::string sorcerer_name); // Sorcerer Name Constructor Delegated To Base Main Constructor
};

#endif // SORCERER_H
