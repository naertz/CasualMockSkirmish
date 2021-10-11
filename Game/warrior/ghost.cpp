#include "ghost.h"

// Constructor(s) ==============================
// Ghost Name To Base Main
Ghost::Ghost(std::string ghost_name): Warrior("Ghost", ghost_name, 1000) {
    choose_attacks();
} //hard to do damage to, but does little damage
// =============================================

void Ghost::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Spook!",
        .value = 2,
        .maxtargets = 2
    });
    attacks.push_back((Attack){
        .name = "Haunt",
        .value = 3,
        .maxtargets = 1
    });
}
