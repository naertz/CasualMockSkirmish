#include "serpent.h"

// Constructor(s) ==============================
// Serpant Name To Base Main
Serpent::Serpent(std::string serpent_name): Warrior("Serpent", serpent_name, 1200) {
    choose_attacks();
}
// =============================================

// Populate Serpent Attacks
void Serpent::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Suffocate",
        .value = 400,
        .maxtargets = 1
    });
    attacks.push_back((Attack){
        .name = "Poison Fang",
        .value = 250,
        .maxtargets = 1
    });
}
