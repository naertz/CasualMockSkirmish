#include "grunt.h"

// Constructor(s) ========================================================
// Grunt Name To Base Main
Grunt::Grunt(std::string grunt_name) : Warrior("Grunt", grunt_name, 100) {
    choose_attacks();
}
// =======================================================================

// Populate Attacks ==============
void Grunt::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Pugilism",
        .value = 10,
        .maxtargets = 1,
        .probability = GOODCHANCE
    });
    attacks.push_back((Attack){
        .name = "Freeze",
        .value = 20,
        .maxtargets = 1,
        .probability = EVENCHANCE
    });
}
// ===============================
