#include "sorcerer.h"

// Constructor(s) =================================
// Sorcerer Name To Base Main
Sorcerer::Sorcerer(std::string sorcerer_name): Warrior("Sorcerer", sorcerer_name, 100) {
    choose_attacks();
}
// ================================================

// Populate Attacks
void Sorcerer::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Fire Ball",
        .value = 75,
        .maxtargets = 2
    });
    attacks.push_back((Attack){
        .name = "Thunder Bolt",
        .value = 85,
        .maxtargets = 1
    });
}
