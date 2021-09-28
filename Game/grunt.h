// Grunt Derived Class Of Warrior

#ifndef GRUNT_H
#define GRUNT_H

#include "warrior.h"

class Grunt : public Warrior {
    public:
        Grunt(std::string grunt_name); // Grunt Name Constructor Delegated To Base Main Constructor
};

#endif // GRUNT_H
