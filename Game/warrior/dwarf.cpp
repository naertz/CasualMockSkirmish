#include "dwarf.h"

// Constructor(s) ========================================================
// Dwarf Name To Base Main
Dwarf::Dwarf(std::string dwarf_name) : Warrior("Dwarf", dwarf_name, 300) {
    choose_attacks();
}
// =======================================================================

// Populate Attacks ==============
void Dwarf::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Trip",
        .value = 50,
        .maxtargets = 1,
        .probability = EVENCHANCE
    });
    attacks.push_back((Attack){
        .name = "Curse",
        .value = 40,
        .maxtargets = 1,
        .probability = GOODCHANCE
    });
}
// ===============================
