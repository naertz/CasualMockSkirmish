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

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#endif // OS Definitions

#include "color_text.h"
#include "skirmish.h"
#include "user_input.h"

#include "warrior/bandit.h"
#include "warrior/basilisk.h"
#include "warrior/dragon.h"
#include "warrior/dwarf.h"
#include "warrior/ghost.h"
#include "warrior/goblin.h"
#include "warrior/grunt.h"
#include "warrior/knight.h"
#include "warrior/mammoth.h"
#include "warrior/ogre.h"
#include "warrior/serpent.h"
#include "warrior/snowman.h"
#include "warrior/sorcerer.h"
#include "warrior/troll.h"
#include "warrior/witch.h"
#include "warrior/wolf.h"

#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

#if defined(WINDOWS)
#include <windows.h>
#endif // OS

static std::string get_title_heading(void);
static std::string get_scenario_option(std::string option_number, std::string team_red, std::string team_blue);
static std::string get_quit_option(std::string option_number);

int main(void) {
#if defined(WINDOWS)
    HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD console_mode;
    GetConsoleMode(h_console, &console_mode);
    console_mode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    console_mode |= 0x0008; // DISABLE_NEWLINE_AUTO_RETURN
    SetConsoleMode(h_console, console_mode);
#endif

    // Set new random seed for each compile time.
    srand(static_cast<unsigned int>(time(nullptr)));

    // Print title.
    std::cout << get_title_heading() << "\n\n";

    // Initialize choice input.
    unsigned int choice = 0;

    do {
        // Print scenario and quit options.
        std::cout << get_scenario_option("1", "1 grunt", "1 grunt") << "\n"
                  << get_scenario_option("2", "2 grunts", "2 grunts") << "\n"
                  << get_scenario_option("3", "4 goblins", "2 dwarves") << "\n"
                  << get_scenario_option("4", "1 ogres", "7 trolls") << "\n"
                  << get_scenario_option("5", "1 dragon", "13 dwarves") << "\n"
                  << get_scenario_option("6", "5 dwarves + 4 grunts + 2 trolls", "1 goblin + 1 ogre") << "\n"
                  << get_scenario_option("7", "1 knight", "7 wolves") << "\n"
                  << get_scenario_option("8", "1 mammoth", "2 dragons") << "\n"
                  << get_scenario_option("9", "4 sorcerers", "2 knights + 1 wolf") << "\n"
                  << get_scenario_option("10", "1 ghost", "8 witches") << "\n"
                  << get_scenario_option("11", "9 snowmen", "3 bandits") << "\n"
                  << get_scenario_option("12", "3 snowmen + 1 serpent + 1 ghost", "1 basilisk") << "\n"
                  << get_scenario_option("13", "3 snowmen + 1 ogre + 1 grunt", "2 ghosts + 2 sorcerers + 1 grunt") << "\n"
                  << get_scenario_option("14", "1 wolf + 1 bandit", "1 goblin + 2 snowmen") << "\n"
                  << get_quit_option("15") << "\n\n";

        // Get user input for option choice.
        choice = get_option(15);

        std::cout << "\n";

        std::vector<Warrior*> team_red;
        std::vector<Warrior*> team_blue;

        // Determine option selected.
        switch (choice) {
            case 1: { // 1 grunt vs 1 grunt
                // Initialize 1 grunt for team red.
                team_red  = {
                    new Grunt("Billy")
                };

                // Initialize 1 grunt for team blue.
                team_blue = {
                    new Grunt("Tasha")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
				break;
            } case 2: { // 2 grunts vs 2 grunts
                // Initialize 2 grunts for team red.
                team_red  = {
                    new Grunt("Billy"),
                    new Grunt("Tasha")
                };

                // Initialize 2 grunts for team blue.
                team_blue = {
                    new Grunt("Sam"),
                    new Grunt("Bessie")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 3: { // 4 goblins vs 2 dwarves
                // Initialize 4 goblins for team red.
                team_red = {
                    new Goblin("Azog"),
                    new Goblin("Bolg"),
                    new Goblin("Golfimbul"),
                    new Goblin("Yazneg")
                };

                // Initialize 2 dwarves for team blue.
                team_blue = {
                    new Dwarf("Bifur"),
                    new Dwarf("Bofur")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 4: { // 1 ogres vs 7 trolls
                // Initialize 1 ogre for team red.
                team_red  = {
                    new Ogre("Dozug")
                };

                // Initialize 7 trolls for team blue.
                team_blue = {
                    new Troll("Tom"),
                    new Troll("Bert"),
                    new Troll("William"),
                    new Troll("Torog"),
                    new Troll("Rogash"),
                    new Troll("Dingal"),
                    new Troll("Bill")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 5: { // 1 dragon vs 13 dwarves
                // Initialize 1 dragon for team red.
                team_red  = {
                    new Dragon("Smaug")
                };

                // Initialize 13 dwarves for team blue.
                team_blue = {
                    new Dwarf("Dwalin"),
                    new Dwarf("Balin"),
                    new Dwarf("Kili"),
                    new Dwarf("Fili"),
                    new Dwarf("Dori"),
                    new Dwarf("Nori"),
                    new Dwarf("Ori"),
                    new Dwarf("Oin"),
                    new Dwarf("Gloin"),
                    new Dwarf("Bifur"),
                    new Dwarf("Bofur"),
                    new Dwarf("Bombur"),
                    new Dwarf("Thorin")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 6: { // 5 dwarf + 4 grunt + 2 troll vs 1 goblin + 1 ogre
                // Initialize 5 dwarves, 4 grunts, and 2 trolls for team red.
                team_red  = {
                    new Dwarf("Thorin"),
                    new Dwarf("Redbeard"),
                    new Dwarf("Dorin"),
                    new Dwarf("Dwurf"),
                    new Dwarf("Murf"),
                    new Grunt("Bilbo"),
                    new Grunt("Gollum"),
                    new Grunt("Smeagol"),
                    new Grunt("Bigfoot"),
                    new Troll("Bruz"),
                    new Troll("Truz")
                };

                // Initialize 1 goblin and 1 ogre for team blue.
                team_blue = { new Goblin("Grinnah"), new Ogre("Ozoc") };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 7: { // 1 knight vs 7 wolves
                // Initialize 1 knight for team red.
                team_red  = {
                    new Knight("Peregrin")
                };

                // Initialize 7 wolves for team blue.
                team_blue = {
                    new Wolf("Harog"),
                    new Wolf("Harach"),
                    new Wolf("Ulku"),
                    new Wolf("Bandi"),
                    new Wolf("Pooch"),
                    new Wolf("Ukwu"),
                    new Wolf("Pamalam")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 8: { // 1 mammoth vs 2 dragons
                // Initialize 1 mammoth for team red.
                team_red  = {
                    new Mammoth("Mumak")
                };

                // Initialize 2 dragons for team blue.
                team_blue = {
                    new Dragon("Scatha"),
                    new Dragon("Gostir")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 9: { // 4 sorcerers vs 2 knights + 1 wolf
                // Initialize 4 sorcerers for team red.
                team_red  = {
                    new Sorcerer("Merlin"),
                    new Sorcerer("Nicolas"),
                    new Sorcerer("Durion"),
                    new Sorcerer("Cassandra")
                };

                // Initialize 2 knights and 1 wolf for team blue.
                team_blue = {
                    new Knight("Peregrin"),
                    new Knight("Elessar"),
                    new Wolf("Harog")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 10: { // 1 ghost vs 8 witches
                // Initialize 1 ghost for team red.
                team_red  = {
                    new Ghost("Casper")
                };

                // Initialize 8 witches for team blue.
                team_blue = {
                    new Witch("Glenda"),
                    new Witch("Snaggletooth"),
                    new Witch("Nosewart"),
                    new Witch("Circe"),
                    new Witch("Blair"),
                    new Witch("Hecate"),
                    new Witch("Morgan le Fay"),
                    new Witch("Nimue")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 11: { // 9 snowmen vs 3 bandits
                // Initialize 9 snowmen for team red.
                team_red  = {
                    new Snowman("Tim"),
                    new Snowman("Angel Mcslushie"),
                    new Snowman("Hot Head Alan"),
                    new Snowman("Jimmy No Nose"),
                    new Snowman("Timmy knows Jimmy No Nose"),
                    new Snowman("Frosty"),
                    new Snowman("Frosty's Cousin Slushie"),
                    new Snowman("Melty"),
                    new Snowman("Melvin No Buttons")
                };

                // Initialize 3 bandits for team blue.
                team_blue = {
                    new Bandit("Scary Terry"),
                    new Bandit("Mischief Mike"),
                    new Bandit("Burglar Barry")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 12: { // 3 snowmen + 1 serpent + 1 ghost vs 1 basilisk
                // Initialize 3 snowmen, 1 serpent, and 1 ghost for team red.
                team_red  = {
                    new Snowman("Tim"),
                    new Snowman("Angel Mcslushie"),
                    new Snowman("Hot Head Alan"),
                    new Serpent("Rattles"),
                    new Ghost("Casper")
                };

                // Initialize 1 basilisk for team blue.
                team_blue = {
                    new Basilisk("Zaccasash")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 13: { // 3 snowmen + 1 ogre + 1 grunt vs 2 ghost + 2 sorcerer + 1 grunt
                // Initialize 3 snowmen, 1 ogre, and 1 grunt for team red.
                team_red = {
                    new Snowman("Melter Skelter"),
                    new Snowman("Quizsnows"),
                    new Snowman("Icy Stars"),
                    new Ogre("Blurek"),
                    new Grunt("Glik")
                };

                // Initialize 2 ghosts, 2 sorcerers, and 1 grunt for team blue.
                team_blue = {
                    new Ghost("Scary Gary"),
                    new Ghost("Slimer"),
                    new Sorcerer("Bimble"),
                    new Sorcerer("Yerdott"),
                    new Grunt("Ungor")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 14: { // 1 wolf + 1 bandit vs 1 goblin + 2 snowmen
                // Initialize 1 wolf and 1 bandit for team red.
                team_red = {
                    new Wolf("Doggo"),
                    new Bandit("Buster")
                };

                // Initialize 1 goblin and 2 snowmen for team blue.
                team_blue = {
                    new Goblin("Irk"),
                    new Snowman("The Cold One"),
                    new Snowman("Mr. Freeze")
                };

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } default: {
                // End game.
                std::cout << get_color_string("Bye", DARK_MAGENTA) << get_color_string(".", DARK_WHITE);
                break;
            }
        }

        std::cout << "\n";
    } while (choice < 15);

    // Exit program successfully.
    return 0;
}

/**
 * @brief get_title_heading creates a title heading string.
 * @return = colored heading
 */

static std::string get_title_heading(void) {
    std::stringstream heading;
    heading << get_color_string("************************", MAGENTA, "\n")
            << get_color_string("* ", MAGENTA) << get_color_string("Casual Mock Skirmish", DARK_RED) << get_color_string(" *", MAGENTA, "\n")
            << get_color_string("************************", MAGENTA);
    return heading.str();
}

/**
 * @brief get_scenario_option creates a scenario option string.
 * @param option_number = string of option number
 * @param team_red = team red warriors
 * @param team_blue = team blue warriors
 * @return = colored scenario option
 */

static std::string get_scenario_option(std::string option_number, std::string team_red, std::string team_blue) {
    std::stringstream scenario;
    scenario << get_color_string(option_number, CYAN) << get_color_string(" - ", DARK_WHITE) << get_color_string(team_red, RED) << get_color_string(" vs ", DARK_WHITE) << get_color_string(team_blue, BLUE);
    return scenario.str();
}

/**
 * @brief get_quit_option creates a quit option string.
 * @param option_number = string of option number
 * @return = colored quit option
 */

static std::string get_quit_option(std::string option_number) {
    std::stringstream quit;
    quit << get_color_string(option_number, YELLOW) << get_color_string(" - ", DARK_WHITE) << get_color_string("Quit", MAGENTA);
    return quit.str();
}
