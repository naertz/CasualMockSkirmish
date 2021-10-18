#include "sorcerer.h"

// Attacks =====================================
std::vector<Attack> sorcerer_attacks = {
    Attack("Fire Ball", 75, 2, EVEN_CHANCE),
    Attack("Thunder Bolt", 85, 1, LOW_CHANCE),
    Attack("Reanimate Dead", 60, 1, EVEN_CHANCE)
};
// =============================================

// Constructor(s) ===============================================================================================
// Default To Base Main
Sorcerer::Sorcerer() : Warrior("Sorcerer", "", 100, sorcerer_attacks, 25) { }

// Sorcerer Name To Base Main
Sorcerer::Sorcerer(std::string sorcerer_name) : Warrior("Sorcerer", sorcerer_name, 100, sorcerer_attacks, 25) { }
// ==============================================================================================================
