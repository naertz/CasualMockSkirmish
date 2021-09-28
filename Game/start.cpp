#include "dragon.h"
#include "dwarf.h"
#include "goblin.h"
#include "grunt.h"
#include "ogre.h"
#include "troll.h"

#include "print.h"
#include "skirmish.h"
#include "user_input.h"

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
        print_scenario("3", "4 goblins", "2 dwarves");
        print_scenario("4", "5 ogres", "9 trolls");
        print_scenario("5", "1 dragon", "13 dwarves");
        print_scenario("6", "1 dwarf + 1 grunt + 1 troll", "1 goblin + 1 ogre");
        print_quit();
        print();

        // Get and validate choice input.
        choice = get_option(7);

        // Determine option selected.
        if (choice == 1) { // 1 grunt vs 1 grunt
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
        } else if (choice == 3) { // 4 goblins vs 2 dwarves
            // Initialize 4 goblins for team red.
            Goblin red_goblin_azog      = Goblin("Azog");
            Goblin red_goblin_bolg      = Goblin("Bolg");
            Goblin red_goblin_golfimbul = Goblin("Golfimbul");
            Goblin red_goblin_yazneg    = Goblin("Yazneg");

            // Initialize 2 dwarves for team blue.
            Dwarf blue_dwarf_bifur = Dwarf("Bifur");
            Dwarf blue_dwarf_bofur = Dwarf("Bofur");

            // Initialize each team.
            std::vector<Warrior*> team_red  { &red_goblin_azog, &red_goblin_bolg, &red_goblin_golfimbul, &red_goblin_yazneg };
            std::vector<Warrior*> team_blue { &blue_dwarf_bifur, &blue_dwarf_bofur };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
        } else if (choice == 4) { // 5 ogres vs 9 trolls
            // Initialize 5 ogres for team red.
            Ogre red_ogre_dozug    = Ogre("Dozug");
            Ogre red_ogre_grizikur = Ogre("Grizikur");
            Ogre red_ogre_iuzug    = Ogre("Iuzug");
            Ogre red_ogre_glezakag = Ogre("Glezakag");
            Ogre red_ogre_krezar   = Ogre("Krezar");

            // Initialize 9 trolls for team blue.
            Troll blue_troll_tom     = Troll("Tom");
            Troll blue_troll_bert    = Troll("Bert");
            Troll blue_troll_william = Troll("William");
            Troll blue_troll_torog   = Troll("Torog");
            Troll blue_troll_rogash  = Troll("Rogash");
            Troll blue_troll_dingal  = Troll("Dingal");
            Troll blue_troll_bill    = Troll("Bill");
            Troll blue_troll_ronald  = Troll("Ronald");
            Troll blue_troll_bolmug  = Troll("Bolmug");

            // Initialize each team.
            std::vector<Warrior*> team_red  { &red_ogre_dozug, &red_ogre_grizikur, &red_ogre_iuzug, &red_ogre_glezakag, &red_ogre_krezar };
            std::vector<Warrior*> team_blue { &blue_troll_tom, &blue_troll_bert, &blue_troll_william, &blue_troll_torog, &blue_troll_rogash, &blue_troll_dingal, &blue_troll_bill, &blue_troll_ronald, &blue_troll_bolmug };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
        } else if (choice == 5) { // 1 dragon vs 13 dwarves
            // Initialize dragon for team red.
            Dragon red_dragon_smaug = Dragon("Smaug");

            // Initialize 13 dwarves for team blue.
            Dwarf blue_dwarf_dwalin = Dwarf("Dwalin");
            Dwarf blue_dwarf_balin  = Dwarf("Balin");
            Dwarf blue_dwarf_kili   = Dwarf("Kili");
            Dwarf blue_dwarf_fili   = Dwarf("Fili");
            Dwarf blue_dwarf_dori   = Dwarf("Dori");
            Dwarf blue_dwarf_nori   = Dwarf("Nori");
            Dwarf blue_dwarf_ori    = Dwarf("Ori");
            Dwarf blue_dwarf_oin    = Dwarf("Oin");
            Dwarf blue_dwarf_gloin  = Dwarf("Gloin");
            Dwarf blue_dwarf_bifur  = Dwarf("Bifur");
            Dwarf blue_dwarf_bofur  = Dwarf("Bofur");
            Dwarf blue_dwarf_bombur = Dwarf("Bombur");
            Dwarf blue_dwarf_thorin = Dwarf("Thorin");

            // Initialize each team.
            std::vector<Warrior*> team_red  { &red_dragon_smaug };
            std::vector<Warrior*> team_blue { &blue_dwarf_dwalin, &blue_dwarf_balin, &blue_dwarf_kili, &blue_dwarf_fili, &blue_dwarf_dori, &blue_dwarf_nori, &blue_dwarf_oin, &blue_dwarf_gloin, &blue_dwarf_bifur, &blue_dwarf_bofur, &blue_dwarf_bombur, &blue_dwarf_thorin };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
        } else if (choice == 6) { // 1 dwarf + 1 grunt + 1 troll vs 1 goblin + 1 ogre
            // Initialize dwarf, grunt, and troll for team red.
            Dwarf red_dwarf_thorin = Dwarf("Thorin");
            Grunt red_grunt_bilbo  = Grunt("Bilbo");
            Troll red_troll_bruz   = Troll("Bruz");

            // Initialize goblin and ogre for team blue.
            Goblin blue_goblin_grinnah = Goblin("Grinnah");
            Ogre blue_ogre_ozoc        = Ogre("Ozoc");

            // Initialize each team.
            std::vector<Warrior*> team_red  { &red_dwarf_thorin, &red_grunt_bilbo, &red_troll_bruz };
            std::vector<Warrior*> team_blue { &blue_goblin_grinnah, &blue_ogre_ozoc };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
        } else if (choice < 1 || choice >= 7) {
            // End game.
            print();
            print("Bye.");
        }
    } while (choice < 7);

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
    print("7", YELLOW, false);
    print(" - ", DARK_WHITE, false);
    print("Quit", MAGENTA);
}
