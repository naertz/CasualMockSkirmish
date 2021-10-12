// Witch Derived Class Of Warrior

#ifndef WITCH_H
#define WITCH_H

#include "../warrior.h"

class Witch : public Warrior {
    public:
        Witch(std::string witch_name);  // Witch Name Constructor Delegated To Base Main Constructor
};

#endif // WITCH_H
