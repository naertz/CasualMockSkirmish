#include "witch.h"

// Attacks =============================
std::vector<Attack> witch_attacks = {
    Attack("Hex", 75, 3, GOOD_CHANCE),
    Attack("Poison", 60, 1, EVEN_CHANCE),
    Attack("Mean Look", 10, 1, PERFECT_CHANCE)
};
// =====================================

// Constructor(s) ========================================================================
// Witch Name To Base Main
Witch::Witch(std::string witch_name) : Warrior("Witch", witch_name, 75, witch_attacks) { }
// =======================================================================================
