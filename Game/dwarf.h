// Dwarf Derived Class Of Warrior

#ifndef DWARF_H
#define DWARF_H

#include "warrior.h"

class Dwarf : public Warrior {
    public:
        Dwarf(std::string dwarf_name); // Dwarf Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);     // Populate Dwarf Attacks
};

#endif // DWARF_H
