// Wolf Derived Class Of Warrior

#ifndef WOLF_H
#define WOLF_H

#include "warrior.h"

class Wolf : public Warrior {
    public:
        Wolf(std::string wolf_name); // Wolf Name Constructor Delegated To Base Main Constructor
};

#endif // WOLF_H
