#include "dragon.h"

// Constructor(s) ==============================
// Dragon Name To Base Main
Dragon::Dragon(std::string dragon_name): Warrior("Dragon", dragon_name, 4000) {
    choose_attacks();
}
// =============================================

// Populate Dragon Attacks
void Dragon::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Fire Breath",
        .value = 300,
        .maxtargets = 3,
        .probability = HIGHCHANCE,
    });
    attacks.push_back((Attack){
        .name = "Talon Strike",
        .value = 250,
        .maxtargets = 1,
        .probability = EVENCHANCE
    });
}
