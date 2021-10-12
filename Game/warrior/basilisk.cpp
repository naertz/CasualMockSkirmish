#include "basilisk.h"

// Attacks ====================================
std::vector<Attack> basilisk_attacks = {
    Attack("Poison Tail", 250, 3, EVEN_CHANCE),
    Attack("Death Glare", 400, 2, GOOD_CHANCE)
};
// ============================================

// Constructor(s) ============================================================================================
// Basilisk Name To Base Main
Basilisk::Basilisk(std::string basilisk_name) : Warrior("Basilisk", basilisk_name, 3500, basilisk_attacks) { }
// ===========================================================================================================
