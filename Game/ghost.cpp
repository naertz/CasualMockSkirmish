#include "ghost.h"

// Constructor(s) ==============================
// Ghost Name To Base Main
Ghost::Ghost(std::string ghost_name)
    : Warrior("Ghost", ghost_name, 1000, 2) { } //hard to do damage to, but does little damage
// =============================================
