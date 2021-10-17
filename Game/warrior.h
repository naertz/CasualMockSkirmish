// Warrior Base Class

#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H

#include "entity.h"

#include "attack.h"
class Attack;  // Forward Attack Declaration

#include <string>
#include <vector>

class Warrior : private Entity {
    public:
        virtual ~Warrior(void);                                                                                                                     // Destructor
        void receive_damage(unsigned int damage_amount) override;                                                                                   // Health (Receive Damage) Mutator
        std::string get_type(void) const;                                                                                                           // Warrior Type Accessor
        std::string get_name(void) const;                                                                                                           // Warrior Individual Name Accessor
        unsigned int get_health(void) const;                                                                                                        // Health Amount Accessor
        unsigned int get_cost(void) const;                                                                                                          // Cost Accessor
        bool attack(Warrior *opponent, Attack &chosen_attack);                                                                                      // Attack 1 Opponent
        bool is_alive(void) const override;                                                                                                         // Alive Verification
    protected:
        Warrior(std::string warrior_type, std::string warrior_name, unsigned int health_capacity, std::vector<Attack> attacks, unsigned int cost);  // Main Constructor
    private:
        std::string type;                                                                                                                           // Warrior Type (Derived Class Name)
        std::string name;                                                                                                                           // Warrior Individual Name
        unsigned int health;                                                                                                                        // Health Amount
        std::vector<Attack> attacks;                                                                                                                // Attacks
        unsigned int cost;                                                                                                                          // Cost
};

#endif // WARRIOR_H
