#include "goblin.h"

// Attacks =====================================
std::vector<Attack> goblin_attacks = {
    Attack("Flare Burn", 35, 1, EVEN_CHANCE),
    Attack("Pitchfork Stab", 40, 1, GOOD_CHANCE)
};
// =============================================

// Constructor(s) ===============================================================================
// Goblin Name To Base Main
Goblin::Goblin(std::string goblin_name) : Warrior("Goblin", goblin_name, 150, goblin_attacks) { }
// ==============================================================================================
