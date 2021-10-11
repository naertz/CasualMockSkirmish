#include "bandit.h"

// Constructor(s) ==============================
// Bandit Name To Base Main
Bandit::Bandit(std::string bandit_name): Warrior("Bandit", bandit_name, 60) {
    choose_attacks();
}
// =============================================

// Populate Bandit Attacks
void Bandit::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Pillage",
        .value = 30,
        .maxtargets = 3,
        .probability = HIGHCHANCE
    });
    attacks.push_back((Attack){
        .name = "Stab",
        .value = 20,
        .maxtargets = 1,
        .probability = GOODCHANCE
    });
}
