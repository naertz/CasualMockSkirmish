#include "snowman.h"

// Constructor(s) ==============================
// Snowman Name To Base Main
Snowman::Snowman(std::string snowman_name): Warrior("Snowman", snowman_name, 30) {
    choose_attacks();
}
// =============================================

// Populate Snowman Attacks
void Snowman::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Snowball",
        .value = 10,
        .maxtargets = 1
    });
    attacks.push_back((Attack){
        .name = "Earthquake",
        .value = 40,
        .maxtargets = 3
    });
}
