// Troll Derived Class Of Warrior

#ifndef TROLL_H
#define TROLL_H

#include "../warrior.h"

class Troll : public Warrior {
    public:
        Troll(std::string troll_name);  // Troll Name Constructor Delegated To Base Main Constructor
};

#endif // TROLL_H
