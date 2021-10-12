#include "ogre.h"

// Constructor(s) ====================================================
// Ogre Name To Base Main
Ogre::Ogre(std::string ogre_name) : Warrior("Ogre", ogre_name, 1000) {
    choose_attacks();
}
// ===================================================================

// Populate Attacks =============
void Ogre::choose_attacks(void) {
    attacks.push_back((Attack){
        .name = "Body Slam",
        .value = 200,
        .maxtargets = 2,
        .probability = GOODCHANCE
    });
    attacks.push_back((Attack){
        .name = "Club Smash",
        .value = 150,
        .maxtargets = 1,
        .probability = EVENCHANCE
    });
	attacks.push_back((Attack){
		.name = "Foul Breath",
		.value = 50,
		.maxtargets = 3,
        .probability = LOWCHANCE
	});
}
// ==============================
