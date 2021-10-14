#include "goblin.h"

// Attacks =====================================
std::vector<Attack> goblin_attacks = {
    Attack("Flare Burn", 35, 2, EVEN_CHANCE),
    Attack("Pitchfork Stab", 40, 1, GOOD_CHANCE),
    Attack("Pitchfork Toss", 50, 1, LOW_CHANCE)
};
// =============================================

// Constructor(s) ===============================================================================
// Goblin Name To Base Main
Goblin::Goblin(std::string goblin_name) : Warrior("Goblin", goblin_name, 150, goblin_attacks) { }
// ==============================================================================================
