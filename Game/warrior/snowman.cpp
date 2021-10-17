#include "snowman.h"

// Attacks ==================================
std::vector<Attack> snowman_attacks = {
    Attack("Snowball", 10, 1, GOOD_CHANCE),
    Attack("Earthquake", 80, 3, SLIM_CHANCE),
    Attack("Frostbite", 15, 1, HIGH_CHANCE)
};
// ==========================================

// Constructor(s) ====================================================================================
// Snowman Name To Base Main
Snowman::Snowman(std::string snowman_name) : Warrior("Snowman", snowman_name, 30, snowman_attacks) { }
// ===================================================================================================
