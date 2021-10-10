// Werewolf Derived Class Of Warrior

#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "warrior.h"

class Werewolf : public Warrior {
    public:
        Werewolf(std::string werewolf_name); // Werewolf Name Constructor Delegated To Base Main Constructor
};
#endif // WEREWOLF_H
