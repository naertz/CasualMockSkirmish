// Mammoth Derived Class Of Warrior

#ifndef MAMMOTH_H
#define MAMMOTH_H

#include "../warrior.h"

class Mammoth : public Warrior {
    public:
        Mammoth(std::string mammoth_name);  // Mammoth Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);          // Populate Mammoth Attacks
};

#endif // MAMMOTH_H