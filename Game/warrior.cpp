#include "warrior.h"

// Constructor(s) ============================================================================================================
// Main
Warrior::Warrior(std::string warrior_type, std::string warrior_name, unsigned int health_capacity, unsigned int damage_amount)
    : type(warrior_type)
    , name(warrior_name)
    , health(health_capacity)
    , attack_damage(damage_amount) { }
// ===========================================================================================================================

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

// Accessor(s) ==================================
// Warrior Type
std::string Warrior::get_type() const {
    return type;
}

// Warrior Individual Name
std::string Warrior::get_name() const {
    return name;
}

// Health Amount
unsigned int Warrior::get_health() const {
    return health;
}

// Damage Amount Per Attack
unsigned int Warrior::get_attack_damage() const {
    return attack_damage;
}
// ==============================================

// Function(s) =================================
// Attack Opponent
bool Warrior::attack(Warrior* opponent) const {
    bool is_successful_attack = rand() % 2;

    if (is_successful_attack) {
        opponent->receive_damage(attack_damage);
        return true;
    } else {
        return false;
    }
}

// Alive Verification
bool Warrior::is_alive() const {
    return health > 0;
}
// =============================================
