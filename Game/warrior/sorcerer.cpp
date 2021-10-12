#include "sorcerer.h"

// Attacks ==================================
std::vector<Attack> sorcerer_attacks = {
    Attack("Fire Ball", 75, 2, EVEN_CHANCE),
    Attack("Thunder Bolt", 85, 1, LOW_CHANCE)
};
// ==========================================

// Constructor(s) ===========================================================================================
// Sorcerer Name To Base Main
Sorcerer::Sorcerer(std::string sorcerer_name) : Warrior("Sorcerer", sorcerer_name, 100, sorcerer_attacks) { }
// ==========================================================================================================
