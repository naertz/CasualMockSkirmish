#include "serpent.h"

// Attacks ====================================
std::vector<Attack> serpent_attacks = {
    Attack("Suffocate", 400, 1, HIGH_CHANCE),
    Attack("Poison Fang", 250, 1, EVEN_CHANCE),
    Attack("Swallow", 130, 1, LOW_CHANCE)
};
// ============================================

// Constructor(s) ==========================================================================================
// Serpent Name To Base Main
Serpent::Serpent(std::string serpent_name) : Warrior("Serpent", serpent_name, 1200, serpent_attacks, 90) { }
// =========================================================================================================
