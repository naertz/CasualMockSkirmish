// Ogre Derived Class Of Warrior

#ifndef OGRE_H
#define OGRE_H

#include "../warrior.h"

class Ogre : public Warrior {
    public:
        Ogre(std::string ogre_name);  // Ogre Name Constructor Delegated To Base Main Constructor
};

#endif // OGRE_H
