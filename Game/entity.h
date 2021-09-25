// Interface for Warriors

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    public:
        virtual void receive_damage(unsigned int damage_amount) = 0; // Health Mutator (Receive Damage)
        virtual bool is_alive() const = 0;                           // Alive Verification
};

#endif // ENTITY_H
