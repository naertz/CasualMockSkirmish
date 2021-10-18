// Dwarf Derived Class Of Warrior

#ifndef DWARF_H
#define DWARF_H

#include "../warrior.h"

class Dwarf : public Warrior {
    public:
        Dwarf();                        // Default Constructor Delegated To Base Main Constructor
        Dwarf(std::string dwarf_name);  // Dwarf Name Constructor Delegated To Base Main Constructor
};

#endif // DWARF_H
