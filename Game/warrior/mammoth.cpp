#include "mammoth.h"

// Constructor(s) ===================================================================
// Mammoth Name To Base Main
Mammoth::Mammoth(std::string mammoth_name) : Warrior("Mammoth", mammoth_name, 1500) {
    choose_attacks();
}
// ==================================================================================

// Populate Attacks ================
void Mammoth::choose_attacks(void) {
    attacks.push_back({
        .name = "Stomp",
        .value = 150,
        .maxtargets = 2,
        .probability = HIGHCHANCE
    });
    attacks.push_back({
        .name = "Tusk Charge",
        .value = 170,
        .maxtargets = 3,
        .probability = EVENCHANCE
    });
}
// =================================
