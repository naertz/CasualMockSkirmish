#include "bandit.h"

// Attacks ===============================
std::vector<Attack> bandit_attacks = {
    Attack("Pillage", 30, 3, HIGH_CHANCE),
    Attack("Stab", 20, 1, GOOD_CHANCE)
};
// =======================================

// Constructor(s) ==============================================================================
// Bandit Name To Base Main
Bandit::Bandit(std::string bandit_name) : Warrior("Bandit", bandit_name, 60, bandit_attacks) { }
// =============================================================================================
