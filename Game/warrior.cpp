//==================================
// Casual Mock Skirmish
//----------------------------------
// Class: CIS-164 Advanced C++
//----------------------------------
// Reckless Alliance (Contributors):
//     - Noah Allan Ertz
//     - Tanner Babcock
//     - Owen Miner
//     - Lukas Lawler
//     - Gage Decker
//     - Jeffrey Garretto
//----------------------------------
// License: AGPL-3.0
// ---------------------------------
// 2021
//==================================

#include "warrior.h"

// Constructor(s) ================================================================================
// Main
Warrior::Warrior(std::string warrior_type, std::string warrior_name, unsigned int health_capacity)
    : type(warrior_type)
    , name(warrior_name)
    , health(health_capacity) { }
// ===============================================================================================

// Destructor ===========
// Main
Warrior::~Warrior(void) {
    type = "";
    name = "";
    health = 0;
}
// ======================

// Mutator(s) ============================================
// Health (Receive Damage)
void Warrior::receive_damage(unsigned int damage_amount) {
    if (damage_amount > health) {
        this->health = 0;
    } else {
        this->health -= damage_amount;
    }
}
// =======================================================

// Accessor(s) ===============================
// Warrior Type
std::string Warrior::get_type(void) const {
    return type;
}

// Warrior Individual Name
std::string Warrior::get_name(void) const {
    return name;
}

// Health Amount
unsigned int Warrior::get_health(void) const {
    return health;
}
// ===========================================

// Function(s) =======================================================================
// Attack Opponent
bool Warrior::attack(Warrior *opponent, Attack *info) {
    unsigned int attack_chance = rand() % 100;
    unsigned int attack_choice = rand() % attacks.size();
    bool is_successful_attack = (attack_chance <= attacks[attack_choice].probability);

    if (is_successful_attack) {
        opponent->receive_damage(attacks[attack_choice].value);
    }
    *info = attacks[attack_choice];
    return is_successful_attack;
}

// Attack Two Opponents
bool Warrior::attack(Warrior *opponent, Warrior *otheropp, Attack *info) {
    bool first = rand() % 2;
    bool second = rand() % 2;
    unsigned int attack_choice = rand() % attacks.size();

    if (first) {
        opponent->receive_damage(attacks[attack_choice].value);
    }
    if ((attacks[attack_choice].maxtargets > 1) && (second)) {
        otheropp->receive_damage(attacks[attack_choice].value);
    }
    *info = attacks[attack_choice];
    return (first && second);
}

void Warrior::choose_attacks(void) { }

// Alive Verification
bool Warrior::is_alive(void) const {
    return health > 0;
}
// ===================================================================================
