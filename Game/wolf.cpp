#include "wolf.h"

// Constructor(s) ==========================
// Wolf Name To Base Main
Wolf::Wolf(std::string wolf_name): Warrior("Wolf", wolf_name, 200) {
    choose_attacks();
}
// =========================================

// Populate Wolf Attacks
void Wolf::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Bite",
        .value = 15,
        .maxtargets = 1
    });
    attacks.push_back((Attack){
        .name = "Charge",
        .value = 20,
        .maxtargets = 1
    });
}
