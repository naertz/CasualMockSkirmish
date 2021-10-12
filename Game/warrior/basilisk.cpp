#include "basilisk.h"

// Constructor(s) ========================================================================
// Basilisk Name To Base Main
Basilisk::Basilisk(std::string basilisk_name) : Warrior("Basilisk", basilisk_name, 3500) {
    choose_attacks();
}
// =======================================================================================

// Populate Attacks =================
void Basilisk::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Poison Tail",
        .value = 250,
        .maxtargets = 3,
        .probability = EVENCHANCE
    });
    attacks.push_back((Attack){
        .name = "Death Glare",
        .value = 400,
        .maxtargets = 2,
        .probability = GOODCHANCE
    });
}
// ==================================
