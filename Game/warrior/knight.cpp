#include "knight.h"

// Attacks ======================================
std::vector<Attack> knight_attacks = {
    Attack("Javelin Charge", 35, 1, GOOD_CHANCE),
    Attack("Arrow Strike", 60, 1, LOW_CHANCE)
};
// ==============================================

// Constructor(s) ===============================================================================
// Knight Name To Base Main
Knight::Knight(std::string knight_name) : Warrior("Knight", knight_name, 600, knight_attacks) { }
// ==============================================================================================
