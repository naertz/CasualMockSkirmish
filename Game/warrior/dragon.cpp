#include "dragon.h"

// Attacks ====================================
std::vector<Attack> dragon_attacks = {
    Attack("Fire Breath", 300, 3, HIGH_CHANCE),
    Attack("Talon Strike", 250, 1, EVEN_CHANCE),
    Attack("Abduct", 100, 1, LOW_CHANCE)
};
// ============================================

// Constructor(s) =====================================================================================
// Default To Base Main
Dragon::Dragon() : Warrior("Dragon", "", 3000, dragon_attacks, 175) { }

// Dragon Name To Base Main
Dragon::Dragon(std::string dragon_name) : Warrior("Dragon", dragon_name, 3000, dragon_attacks, 175) { }
// ====================================================================================================
