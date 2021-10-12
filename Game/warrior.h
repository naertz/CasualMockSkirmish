// Warrior Base Class

#ifndef WARRIOR_H
#define WARRIOR_H

#include "entity.h"

#include <vector>
#include <string>

enum {
    SLIMCHANCE = 25,
    LOWCHANCE = 40,
    EVENCHANCE = 50,
    GOODCHANCE = 60,
    HIGHCHANCE = 75
};

typedef struct {
    std::string name;          // Name of the attack
    unsigned int value;        // Attack damage dealt to opponent
    unsigned int maxtargets;   // Maximum number of targets
    unsigned int probability;  // Chance out of 100 that attack will succeed
} Attack;

class Warrior : private Entity {
    public:
        virtual ~Warrior(void);
        void receive_damage(unsigned int damage_amount) override;                                   // Health (Receive Damage) Mutator
        std::string get_type(void) const;                                                           // Warrior Type Accessor
        std::string get_name(void) const;                                                           // Warrior Individual Name Accessor
        unsigned int get_health(void) const;                                                        // Health Amount Accessor
        unsigned int get_attack_damage(void) const;                                                 // Damage Amount Per Attack Accessor
        bool attack(Warrior *opponent, Attack *info);                                               // Attack Opponent
        bool attack(Warrior *opponent, Warrior *otheropp, Attack *info);                            // Attack Two Opponents
        virtual void choose_attacks(void);                                                          // Populate attacks based on creature type
        bool is_alive(void) const override;                                                         // Alive Verification
        std::vector<Attack> attacks;                                                                // Attacks
    protected:
        Warrior(std::string warrior_type, std::string warrior_name, unsigned int health_capacity);  // Main Constructor
    private:
        std::string type;                                                                           // Warrior Type (Derived Class Name)
        std::string name;                                                                           // Warrior Individual Name
        unsigned int health;                                                                        // Health Amount
};

#endif // WARRIOR_H
