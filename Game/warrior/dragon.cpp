#include "dragon.h"

// Attacks ====================================
std::vector<Attack> dragon_attacks = {
    Attack("Fire Breath", 300, 3, HIGH_CHANCE),
    Attack("Talon Strike", 250, 1, EVEN_CHANCE)
};
// ============================================

// Constructor(s) ================================================================================
// Dragon Name To Base Main
Dragon::Dragon(std::string dragon_name) : Warrior("Dragon", dragon_name, 4000, dragon_attacks) { }
// ===============================================================================================
