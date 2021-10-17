#include "basilisk.h"

// Attacks ====================================
std::vector<Attack> basilisk_attacks = {
    Attack("Poison Tail", 250, 3, EVEN_CHANCE),
    Attack("Death Glare", 350, 2, GOOD_CHANCE),
    Attack("Claw Stab", 100, 1, EVEN_CHANCE)
};
// ============================================

// Constructor(s) =================================================================================================
// Basilisk Name To Base Main
Basilisk::Basilisk(std::string basilisk_name) : Warrior("Basilisk", basilisk_name, 2800, basilisk_attacks, 175) { }
// ================================================================================================================
