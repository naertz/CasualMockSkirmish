// Warrior Base Class

#ifndef WARRIOR_H
#define WARRIOR_H

#include "entity.h"

#include <string>

class Warrior : private Entity {
    public:
        virtual ~Warrior(void);
        void receive_damage(unsigned int damage_amount) override;                                                              // Health (Receive Damage) Mutator
        std::string get_type(void) const;                                                                                          // Warrior Type Accessor
        std::string get_name(void) const;                                                                                          // Warrior Individual Name Accessor
        unsigned int get_health(void) const;                                                                                       // Health Amount Accessor
        unsigned int get_attack_damage(void) const;                                                                                // Damage Amount Per Attack Accessor
        bool attack(Warrior* opponent) const;                                                                                      // Attack Opponent
        bool is_alive(void) const override;                                                                                        // Alive Verification
    protected:
        Warrior(std::string warrior_type, std::string warrior_name, unsigned int health_capacity, unsigned int damage_amount); // Main Constructor
    private:
        std::string type;                                                                                                      // Warrior Type (Derived Class Name)
        std::string name;                                                                                                      // Warrior Individual Name
        unsigned int health;                                                                                                   // Health Amount
        unsigned int attack_damage;                                                                                            // Damage Amount Per Attack
};

#endif // WARRIOR_H
