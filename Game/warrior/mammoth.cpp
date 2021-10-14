#include "mammoth.h"

// Attacks ===================================
std::vector<Attack> mammoth_attacks = {
    Attack("Stomp", 150, 2, HIGH_CHANCE),
    Attack("Tusk Charge", 170, 3, EVEN_CHANCE),
    Attack("Spit", 30, 1, PERFECT_CHANCE)
};
// ===========================================

// Constructor(s) ======================================================================================
// Mammoth Name To Base Main
Mammoth::Mammoth(std::string mammoth_name) : Warrior("Mammoth", mammoth_name, 1500, mammoth_attacks) { }
// =====================================================================================================
