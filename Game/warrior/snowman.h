// Snowman Derived Class Of Warrior
#ifndef SNOWMAN_H
#define SNOWMAN_H

#include "../warrior.h"

class Snowman : public Warrior {
    public:
        Snowman(std::string snowman_name); // Snowman Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);         // Populate Snowman Attacks
};

#endif // SNOWMAN_H
