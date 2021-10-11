#include "witch.h"

// Constructor(s) ==============================
// Witch Name To Base Main
Witch::Witch(std::string witch_name): Warrior("Witch", witch_name, 75) {
    choose_attacks();
}
// =============================================

void Witch::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Hex",
        .value = 75,
        .maxtargets = 3
    });
    attacks.push_back((Attack){
        .name = "Poison",
        .value = 60,
        .maxtargets = 1
    });
}
