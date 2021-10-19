#include "basilisk.h"

// Attacks ====================================
std::vector<Attack> basilisk_attacks = {
    Attack("Poison Tail", 250, 3, LOW_CHANCE),
    Attack("Death Glare", 350, 2, EVEN_CHANCE),
    Attack("Claw Stab", 100, 1, PERFECT_CHANCE)
};
// ============================================

// Constructor(s) =================================================================================================
// Default To Base Main
Basilisk::Basilisk() : Warrior("Basilisk", "", 2800, basilisk_attacks, 175) { }

// Basilisk Name To Base Main
Basilisk::Basilisk(std::string basilisk_name) : Warrior("Basilisk", basilisk_name, 2800, basilisk_attacks, 175) { }
// ================================================================================================================
