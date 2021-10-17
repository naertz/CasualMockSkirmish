#include "ogre.h"

// Attacks ===================================
std::vector<Attack> ogre_attacks = {
    Attack("Body Slam", 200, 2, EVEN_CHANCE),
    Attack("Club Smash", 150, 1, GOOD_CHANCE),
    Attack("Foul Breath", 50, 3, LOW_CHANCE)
};
// ===========================================

// Constructor(s) ========================================================================
// Ogre Name To Base Main
Ogre::Ogre(std::string ogre_name) : Warrior("Ogre", ogre_name, 1000, ogre_attacks, 70) { }
// =======================================================================================
