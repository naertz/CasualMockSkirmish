#include "wolf.h"

// Attacks ==============================
std::vector<Attack> wolf_attacks = {
    Attack("Bite", 15, 1, EVEN_CHANCE),
    Attack("Charge", 20, 1, GOOD_CHANCE),
    Attack("Maul", 40, 2, LOW_CHANCE)
};
// ======================================

// Constructor(s) ===================================================================
// Wolf Name To Base Main
Wolf::Wolf(std::string wolf_name) : Warrior("Wolf", wolf_name, 200, wolf_attacks) { }
// ==================================================================================
