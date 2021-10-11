#include "troll.h"

// Constructor(s) ===========================
// Troll Name To Base Main
Troll::Troll(std::string troll_name): Warrior("Troll", troll_name, 400) {
    choose_attacks();
}
// ==========================================

// Populate Attacks
void Troll::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Pickpocket",
        .value = 45,
        .maxtargets = 1,
        .probability = EVENCHANCE
    });
    attacks.push_back((Attack){
        .name = "Scratch",
        .value = 50,
        .maxtargets = 1,
        .probability = EVENCHANCE
    });
}
