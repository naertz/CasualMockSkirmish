// Dragon Derived Class Of Warrior

#ifndef DRAGON_H
#define DRAGON_H

#include "../warrior.h"

class Dragon : public Warrior {
    public:
        Dragon(std::string dragon_name);  // Dragon Name Constructor Delegated To Base Main Constructor
};

#endif // DRAGON_H
