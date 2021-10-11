#include "knight.h"

// Constructor(s) =============================
// Knight Name To Base Main
Knight::Knight(std::string knight_name): Warrior("Knight", knight_name, 600) {
    choose_attacks();
}
// ============================================

// Populate Knight Attacks
void Knight::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Javelin Charge",
        .value = 35,
        .maxtargets = 1
    });
    attacks.push_back((Attack){
        .name = "Arrow Strike",
        .value = 40,
        .maxtargets = 1
    });
}
