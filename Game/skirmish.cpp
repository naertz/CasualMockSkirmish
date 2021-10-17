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
//----------------------------------
// 2021
//==================================

#include "skirmish.h"

#include "attack.h"
#include "color_text.h"
#include "warrior.h"

#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief get_turn_heading creates a heading string for the current turn.
 * @param current_team = current attacking team
 * @param turn = current simulation turn
 * @return = colored heading
 */

std::string get_turn_heading(unsigned int current_team, unsigned int turn) {
    std::stringstream heading;

    switch (current_team) {
        case 0: {
            heading << get_color_string("Team Red", RED) << get_color_string(" -- ", DARK_WHITE) << get_color_string("Turn ", DARK_GREEN) << get_color_string(std::to_string(turn), WHITE);
            break;
        }
        case 1: {
            heading << get_color_string("Team Blue", BLUE) << get_color_string(" -- ", DARK_WHITE) << get_color_string("Turn ", DARK_GREEN) << get_color_string(std::to_string(turn), WHITE);
            break;
        }
    }

    return heading.str();
}

/**
 * @brief start_skirmish runs a skirmish simulation.
 * @param team_red  = team red warriors
 * @param team_blue = team blue warriors
 */

void start_skirmish(std::vector<Warrior*> team_red, std::vector<Warrior*> team_blue) {
    std::cout << "\n";

    unsigned int turn = 0;

    // Simulation prints current turn until one team has no warriors left.
    while (team_red.size() > 0 && team_blue.size() > 0) {
        switch (turn % 2) {
            case 0: { // Team Red attacks
                // Print header.
                std::cout << get_turn_heading(turn % 2, turn) << "\n\n\n";

                // Random attacking and defending warriors are selected at random.
                unsigned int random_red_warrior  = rand() % team_red.size();
                unsigned int random_blue_warrior = rand() % team_blue.size();

                // Get the defending warrior's health before the attack because we are printing everything after
                unsigned int old_health = team_blue[random_blue_warrior]->get_health();

                std::stringstream attackEventOSS;
                Attack attack_attempt;

                // Get boolean to determine if the attack is hit or miss.
                bool is_successful_attack = team_red[random_red_warrior]->attack(team_blue[random_blue_warrior], attack_attempt);

                // Append first part of event message before red warrior attacks to string stream.
                attackEventOSS << get_color_string("Red " + team_red[random_red_warrior]->get_type(), RED) << " "
                               << get_color_string(team_red[random_red_warrior]->get_name(), YELLOW) << " "
                               << get_color_string("(HP: " + std::to_string(team_red[random_red_warrior]->get_health()) + ")", DARK_MAGENTA) << " "
                               << get_color_string("uses", DARK_WHITE) << " " << get_color_string(attack_attempt.get_name(), DARK_YELLOW) << " " << get_color_string("on", DARK_WHITE) << " "
                               << get_color_string("Blue " + team_blue[random_blue_warrior]->get_type(), BLUE) << " "
                               << get_color_string(team_blue[random_blue_warrior]->get_name(), CYAN) << " "
                               << get_color_string("(HP: " + std::to_string(old_health) + ")", DARK_MAGENTA) << " ";

                // Append attack result to string stream.
                if (is_successful_attack) {
                    attackEventOSS << get_color_string("and", DARK_WHITE) << " " << get_color_string("lands a blow", GREEN) << " " << get_color_string("(-" + std::to_string(attack_attempt.get_damage_amount()) + ")", DARK_RED) << get_color_string(".", DARK_WHITE) << " ";
                } else {
                    attackEventOSS << get_color_string("and", DARK_WHITE) << " " << get_color_string("misses", GRAY) << " " << get_color_string("(-0)", MAGENTA) << get_color_string(".", DARK_WHITE) << " ";
                }

                // Append defending warrior's health result to string stream.
                attackEventOSS << get_color_string("Blue " + team_blue[random_blue_warrior]->get_type(), BLUE) << " "
                               << get_color_string(team_blue[random_blue_warrior]->get_name(), CYAN) << " "
                               << get_color_string("(HP: " + std::to_string(team_blue[random_blue_warrior]->get_health()) + ")", DARK_MAGENTA) << "\n";

                // Print string stream.
                std::cout << attackEventOSS.str() << "\n\n";

                // Remove warrior from defending team if they died.
                if (!team_blue[random_blue_warrior]->is_alive()) {
                    delete(team_blue[random_blue_warrior]);
                    team_blue.erase(team_blue.begin() + random_blue_warrior);
                }

                break;
            } case 1: { // Team Blue attacks
                // Print header.
                std::cout << get_turn_heading(turn % 2, turn) << "\n\n\n";

                // Random attacking and defending warriors are selected at random.
                unsigned int random_blue_warrior = rand() % team_blue.size();
                unsigned int random_red_warrior  = rand() % team_red.size();
                unsigned int old_health = team_red[random_red_warrior]->get_health();

                std::stringstream attackEventOSS;
                Attack attack_attempt;

                // Get boolean to determine if the attack is hit or miss.
                bool is_successful_attack = team_blue[random_blue_warrior]->attack(team_red[random_red_warrior], attack_attempt);

                // Append first part of event message before blue warrior attacks to string stream.
                attackEventOSS << get_color_string("Blue " + team_blue[random_blue_warrior]->get_type(), BLUE) << " "
                               << get_color_string(team_blue[random_blue_warrior]->get_name(), CYAN) << " "
                               << get_color_string("(HP: " + std::to_string(team_blue[random_blue_warrior]->get_health()) + ")", DARK_MAGENTA) << " "
                               << get_color_string("uses", DARK_WHITE) << " " << get_color_string(attack_attempt.get_name(), DARK_YELLOW) << " " << get_color_string("on", DARK_WHITE) << " "
                               << get_color_string("Red " + team_red[random_red_warrior]->get_type(), RED) << " "
                               << get_color_string(team_red[random_red_warrior]->get_name(), YELLOW) << " "
                               << get_color_string("(HP: " + std::to_string(old_health) + ")", DARK_MAGENTA) << " ";

                // Append attack result to string stream.
                if (is_successful_attack) {
                    attackEventOSS << get_color_string("and", DARK_WHITE) << " " << get_color_string("lands a blow", GREEN) << " " << get_color_string("(-" + std::to_string(attack_attempt.get_damage_amount()) + ")", DARK_RED) << get_color_string(".", DARK_WHITE) << " ";
                } else {
                    attackEventOSS << get_color_string("and", DARK_WHITE) << " " << get_color_string("misses", GRAY) << " " << get_color_string("(-0)", MAGENTA) << get_color_string(".", DARK_WHITE) << " ";
                }

                // Append defending warrior's health result to string stream.
                attackEventOSS << get_color_string("Red " + team_red[random_red_warrior]->get_type(), RED) << " "
                               << get_color_string(team_red[random_red_warrior]->get_name(), YELLOW) << " "
                               << get_color_string("(HP: " + std::to_string(team_red[random_red_warrior]->get_health()) + ")", DARK_MAGENTA) << "\n";

                // Print string stream.
                std::cout << attackEventOSS.str() << "\n\n";

                // Remove warrior from defending team if they died.
                if (!team_red[random_red_warrior]->is_alive()) {
                    delete(team_red[random_red_warrior]);
                    team_red.erase(team_red.begin() + random_red_warrior);
                }

                break;
            }
        }

        // Proceed to next turn.
        ++turn;
    }

    // Print winning team.
    if (team_red.size() > 0) {
        std::cout << get_color_string("Team Red", RED) << " " << get_color_string("Wins", GREEN) << get_color_string("!", DARK_WHITE) << "\n\n";
		if (team_red.size() > 1) {
			delete(team_red[1]);
		}
        delete(team_red[0]);
    }
	else {
        std::cout << get_color_string("Team Blue", BLUE) << " " << get_color_string("Wins", GREEN) << get_color_string("!", DARK_WHITE) << "\n\n";
		if (team_blue.size() > 1) {
			delete(team_blue[1]);
		}
        delete(team_blue[0]);
    }
}
