#include "grunt.h"

// Attacks ================================
std::vector<Attack> grunt_attacks = {
    Attack("Pugilism", 10, 1, GOOD_CHANCE),
    Attack("Freeze", 20, 1, EVEN_CHANCE)
};
// ========================================

// Constructor(s) =========================================================================
// Grunt Name To Base Main
Grunt::Grunt(std::string grunt_name) : Warrior("Grunt", grunt_name, 100, grunt_attacks) { }
// ========================================================================================
