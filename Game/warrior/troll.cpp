#include "troll.h"

// Attacks ==================================
std::vector<Attack> troll_attacks = {
    Attack("Pickpocket", 45, 1, EVEN_CHANCE),
    Attack("Scratch", 50, 1, EVEN_CHANCE),
    Attack("Bite", 40, 1, GOOD_CHANCE)
};
// ==========================================

// Constructor(s) =============================================================================
// Troll Name To Base Main
Troll::Troll(std::string troll_name) : Warrior("Troll", troll_name, 400, troll_attacks, 35) { }
// ============================================================================================
