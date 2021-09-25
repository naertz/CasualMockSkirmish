#include "print.h"
#include "user_input.h"
#include "grunt.h"
#include "skirmish.h"

#include <ctime>
#include <vector>

static void print_title();
static void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue);
static void print_quit();

int main() {
    // Set new random seed for each compile time.
    srand(static_cast<unsigned int>(time(nullptr)));

    // Print title.
    print_title();
    print();

    // Initialize choice input.
    unsigned int choice = 0;

    do {
        // Print scenario and quit options.
        print_scenario("1", "1 grunt", "1 grunt");
        print_scenario("2", "2 grunts", "2 grunts");
        print_quit();
        print();

        // Get and validate choice input.
        choice = get_option(3);

        // Determine option selected.
        if (choice <= 1) { // 1 grunt vs 1 grunt
            // Initialize 1 grunt for each team.
            Grunt red_grunt_billy  = Grunt("Billy");
            Grunt blue_grunt_tasha = Grunt("Tasha");

            // Initialize each team.
            std::vector<Warrior*> team_red  { &red_grunt_billy };
            std::vector<Warrior*> team_blue { &blue_grunt_tasha };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
        } else if (choice == 2) { // 2 grunts vs 2 grunts
            // Initialize two grunts for each team.
            Grunt red_grunt_billy   = Grunt("Billy");
            Grunt red_grunt_tasha   = Grunt("Tasha");
            Grunt blue_grunt_sam    = Grunt("Sam");
            Grunt blue_grunt_bessie = Grunt("Bessie");

            // Initialize each team.
            std::vector<Warrior*> team_red  { &red_grunt_billy, &red_grunt_tasha };
            std::vector<Warrior*> team_blue { &blue_grunt_sam, &blue_grunt_bessie };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
        } else if (choice >= 3) {
            // End game.
            print();
            print("Bye.");
        }
    } while (choice < 3);

    // Exit program successfully.
    return 0;
}

/**
 * @brief print_title prints title header of simulation game.
 */

static void print_title() {
    print("************************", MAGENTA);
    print("* ", MAGENTA, false);
    print("Casual Mock Skirmish", DARK_RED, false);
    print(" *", MAGENTA);
    print("************************", MAGENTA);
}

/**
 * @brief print_scenario prints scenario option.
 * @param optionNumber = string of option number
 * @param teamRed = team red warriors
 * @param teamBlue = team blue warriors
 */

static void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue) {
    print(optionNumber, CYAN, false);
    print(" - ", DARK_WHITE, false);
    print(teamRed, RED, false);
    print(" vs ", DARK_WHITE, false);
    print(teamBlue, BLUE);
}

/**
 * @brief print_quit prints quit option.
 */

static void print_quit() {
    print("3", YELLOW, false);
    print(" - ", DARK_WHITE, false);
    print("Quit", MAGENTA);
}
