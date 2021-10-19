#include "dwarf.h"

// Attacks ===============================
std::vector<Attack> dwarf_attacks = {
    Attack("Trip", 50, 1, EVEN_CHANCE),
    Attack("Curse", 40, 1, GOOD_CHANCE),
    Attack("Pugilism", 20, 1, HIGH_CHANCE)
};
// =======================================

// Constructor(s) =============================================================================
// Default To Base Main
Dwarf::Dwarf() : Warrior("Dwarf", "", 300, dwarf_attacks, 30) { }

// Dwarf Name To Base Main
Dwarf::Dwarf(std::string dwarf_name) : Warrior("Dwarf", dwarf_name, 300, dwarf_attacks, 30) { }
// ============================================================================================
