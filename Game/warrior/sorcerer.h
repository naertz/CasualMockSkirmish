// Sorcerer Derived Class of Warrior

#ifndef SORCERER_H
#define SORCERER_H

#include "../warrior.h"

class Sorcerer : public Warrior {
    public:
        Sorcerer(std::string sorcerer_name); // Sorcerer Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);           // Populate Sorcerer Attacks
};

#endif // SORCERER_H
