#include "select.h"

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

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

static std::string get_scenario_option(const std::string option_number, const std::string team_blue);
static std::string get_quit_option(const std::string option_number);
static int get_longest_string_length(const std::vector<std::string>& column);
static std::vector<Warrior*> select_warriors(const unsigned int max_total_cost);

void select_scenario(void) {
    // Initialize choice input.
    unsigned int choice = 0;

    do {
        std::cout << get_color_string("Select a scenario for", DARK_WHITE) << " " << get_color_string("Team Blue", BLUE) << get_color_string(":", DARK_WHITE) << "\n\n";
        // Print scenario and quit options.
        std::cout << get_scenario_option("1", "2 Grunts") << "\n"
                  << get_scenario_option("2", "3 Snowmen") << "\n"
                  << get_scenario_option("3", "4 Goblins") << "\n"
                  << get_scenario_option("4", "2 Knights") << "\n"
                  << get_scenario_option("5", "1 Ghost + 2 Witches") << "\n"
                  << get_scenario_option("6", "1 Ogre + 2 Trolls") << "\n"
                  << get_scenario_option("7", "2 Serpents") << "\n"
                  << get_scenario_option("8", "2 Mammoths") << "\n"
                  << get_scenario_option("9", "1 Basilisk + 1 Dragon") << "\n"
                  << get_quit_option("10") << "\n\n\n";

        // Get user input for option choice.
        choice = get_option(10);

        std::cout << "\n\n";

        std::vector<Warrior*> team_red;
        std::vector<Warrior*> team_blue;

        // Determine option selected.
        switch (choice) {
            case 1: { // 2 Grunts
                // Get team red warriors.
                team_red = select_warriors(40);

                // Initialize 2 Grunts for team blue.
                team_blue = {
                    new Grunt("Billy"),
                    new Grunt("Bessie")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 2: { // 3 Snowmen
                // Get team red warriors.
                team_red = select_warriors(40);

                // Initialize 3 Snowmen for team blue.
                team_blue = {
                    new Snowman("Hot Head Alan"),
                    new Snowman("Frosty's Cousin Slushie"),
                    new Snowman("Melty")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 3: { // 4 Goblins
                // Get team red warriors.
                team_red = select_warriors(70);

                // Initialize 4 Goblins for team blue.
                team_blue = {
                    new Goblin("Gib"),
                    new Goblin("Gob"),
                    new Goblin("Glob"),
                    new Goblin("Gorp")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 4: { // 2 Knights
                // Get team red warriors.
                team_red = select_warriors(90);

                // Initialize 2 Knights for team blue.
                team_blue = {
                    new Knight("Romeo"),
                    new Knight("Juilius")

                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 5: { // 1 Ghost + 2 Witches
                // Get team red warriors.
                team_red = select_warriors(100);

                // Initialize 1 Ghost and 2 Witches.
                team_blue = {
                    new Ghost("Googley"),
                    new Witch("Toad Whisperer"),
                    new Witch("Black Cat")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 6: { // 1 Ogre + 2 Trolls
                // Get team red warriors.
                team_red = select_warriors(170);

                // Initialize 1 Ogre and 2 Trolls.
                team_blue = {
                    new Ogre("One Eye"),
                    new Troll("Stumpy"),
                    new Troll("Wobbles")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 7: { // 2 Serpents
                // Get team red warriors.
                team_red = select_warriors(200);

                // Initialize 2 Serpents.
                team_blue = {
                    new Serpent("Scaline"),
                    new Serpent("Sheddar")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 8: { // 2 Mammoths
                // Get team red warriors.
                team_red = select_warriors(200);

                // Initialize 3 Mammoths for team blue.
                team_blue = {
                    new Mammoth("Mumak"),
                    new Mammoth("Tumak")
                };

                std::cout << "\n";

                // Start skirmish simulation.
                start_skirmish(team_red, team_blue);
                break;
            } case 9: { // 1 Basilisk + 1 Dragon
                // Get team red warriors.
                team_red = select_warriors(430);

                // Initialize 1 Basilisk and 1 Dragon for team blue.
                team_blue = {
                    new Basilisk("Salazar"),
                    new Dragon("Smaug")
                };

                std::cout << "\n";

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
    } while (choice < 10);
}

/**
 * @brief get_scenario_option creates a scenario option string.
 * @param option_number = string of option number
 * @param team_red = team red warriors
 * @param team_blue = team blue warriors
 * @return = colored scenario option
 */

static std::string get_scenario_option(const std::string option_number, const std::string team_blue) {
    std::stringstream scenario;
    scenario << get_color_string(option_number, CYAN) << get_color_string(" - ", DARK_WHITE) << get_color_string(team_blue, BLUE);
    return scenario.str();
}

/**
 * @brief get_quit_option creates a quit option string.
 * @param option_number = string of option number
 * @return = colored quit option
 */

static std::string get_quit_option(const std::string option_number) {
    std::stringstream quit;
    quit << get_color_string(option_number, YELLOW) << get_color_string(" - ", DARK_WHITE) << get_color_string("Quit", MAGENTA);
    return quit.str();
}

/**
 * @brief get_longest_string_length loops through each string in a vector, finds the longest string, and returns the string length to use for setting field widths.
 * @param column = vector of column strings
 * @return = longest string length
 */

static int get_longest_string_length(const std::vector<std::string>& column) {
    // Store the first string.
    std::string current_column_string = column[0];

    // Initialize the current string length integer for the upcoming for loop.
    int current_column_string_length = 0;
    // Store the first string length to the longest string length integer.
    int longest_column_string_length = current_column_string.length();

    // Loop through the rest of the strings to determine the longest string length.
    for (unsigned int i = 1; i < column.size(); ++i) {
        current_column_string = column[i];
        current_column_string_length = current_column_string.length();

        if (current_column_string_length > longest_column_string_length) {
            longest_column_string_length = current_column_string_length;
        }
    }

    return longest_column_string_length;
}

/**
 * @brief select_warriors displays a menu to select warriors and gets a valid vector of warriors.
 * @param max_total_cost = max total cost available to select warriors for scenario
 * @return = vector of team red warriors
 */

static std::vector<Warrior*> select_warriors(unsigned int max_total_cost) {
    // String for headings
    std::string option_heading = get_color_string("Option", DARK_CYAN);
    std::string warrior_heading = get_color_string("Warrior", DARK_RED);
    std::string cost_heading = get_color_string("Cost", DARK_GREEN);
    std::string quantity_heading = get_color_string("Quantity", GRAY);

    // Strings for pairs of Warriors ordered by cost and quantities
    std::vector<std::pair<Warrior*, unsigned int>> warriors {
        { new Snowman(),  0 }, // Cost:  10
        { new Grunt(),    0 }, // Cost:  15
        { new Bandit(),   0 }, // Cost:  15
        { new Wolf(),     0 }, // Cost:  15
        { new Goblin(),   0 }, // Cost:  20
        { new Witch(),    0 }, // Cost:  20
        { new Sorcerer(), 0 }, // Cost:  25
        { new Dwarf(),    0 }, // Cost:  30
        { new Troll(),    0 }, // Cost:  35
        { new Knight(),   0 }, // Cost:  40
        { new Ghost(),    0 }, // Cost:  40
        { new Ogre(),     0 }, // Cost:  70
        { new Mammoth(),  0 }, // Cost:  85
        { new Serpent(),  0 }, // Cost:  90
        { new Basilisk(), 0 }, // Cost: 175
        { new Dragon(),   0 }  // Cost: 175
    };

    // Vectors of strings for each column
    std::vector<std::string> option_column = { option_heading };
    unsigned option;
    for (option = 1; option <= warriors.size(); ++option) {
        option_column.push_back(get_color_string(std::to_string(option), CYAN));
    }
    option_column.push_back(get_color_string(std::to_string(option), YELLOW));

    std::vector<std::string> warrior_column = { warrior_heading };
    for (unsigned int i = 0; i < warriors.size(); ++i) {
        warrior_column.push_back(get_color_string(warriors[i].first->get_type(), RED));
    }
    warrior_column.push_back(get_color_string("Submit", MAGENTA));

    std::vector<std::string> cost_column = { cost_heading };
    for (unsigned int i = 0; i < warriors.size(); ++i) {
        cost_column.push_back(get_color_string(std::to_string(warriors[i].first->get_cost()), GREEN));
    }

    std::vector<std::string> quantity_column = { quantity_heading };
    for (unsigned int i = 0; i < warriors.size(); ++i) {
        quantity_column.push_back(get_color_string(std::to_string(warriors[i].second), WHITE));
    }

    // Length of longest string for each column
    const int longest_option_length   = get_longest_string_length(option_column);
    const int longest_warrior_length  = get_longest_string_length(warrior_column);
    const int longest_cost_length     = get_longest_string_length(cost_column);
    int longest_quantity_length       = get_longest_string_length(quantity_column);

    // Length of width padding for each column
    const int option_width   = longest_option_length;
    const int warrior_width  = longest_warrior_length  + 4;
    const int cost_width     = longest_cost_length     + 4;
    int quantity_width       = longest_quantity_length + 4;

    // Declare vector for team red.
    std::vector<Warrior*> team_red;

    // Initialize boolean for valid submission check.
    bool is_valid_submission = false;
    do {
        // Current accumulated cost
        unsigned int current_selection_cost = 0;
        for (unsigned int i = 0; i < warriors.size(); ++i) {
            current_selection_cost += warriors[i].first->get_cost() * warriors[i].second;
        }

        // Print formatted table.
        std::stringstream warrior_selection_table;
        for (unsigned int i = 0; i < option_column.size() - 1; ++i) {
            warrior_selection_table << std::left << std::setw(option_width) << option_column[i] << std::right << std::setw(warrior_width) << warrior_column[i] << std::setw(cost_width) << cost_column[i] << std::setw(quantity_width) << quantity_column[i] << "\n";
        }
        warrior_selection_table << std::left << std::setw(option_width) << option_column.back() << std::right << std::setw(warrior_width) << warrior_column.back() << "\n\n" << get_color_string("Current Total", DARK_YELLOW) << get_color_string(":", DARK_WHITE) << " " << get_color_string(std::to_string(current_selection_cost), WHITE) << "\n" << get_color_string("Max Total", DARK_MAGENTA) << get_color_string(":", DARK_WHITE) << " " << get_color_string(std::to_string(max_total_cost), WHITE);

        // Print table and prompt.
        std::cout << warrior_selection_table.str() << "\n\n\n" <<  get_color_string("Select a warrior.", DARK_WHITE) << "\n";

        // Validate input.
        unsigned int warrior_selection = get_option(warriors.size() + 1);

        switch (warrior_selection) {
            case 1: { // Snowman
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of snowmen to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[0].second = get_quantity(999);

                // Update quantity column.
                quantity_column[1] = get_color_string(std::to_string(warriors[0].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 2: { // Grunt
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of grunts to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[1].second = get_quantity(999);

                // Update quantity column.
                quantity_column[2] = get_color_string(std::to_string(warriors[1].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 3: { // Bandit
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of bandits to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[2].second = get_quantity(999);

                // Update quantity column.
                quantity_column[3] = get_color_string(std::to_string(warriors[2].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 4: { // Wolf
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of wolves to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[3].second = get_quantity(999);

                // Update quantity column.
                quantity_column[4] = get_color_string(std::to_string(warriors[3].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 5: { // Goblin
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of goblins to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[4].second = get_quantity(999);

                // Update quantity column.
                quantity_column[5] = get_color_string(std::to_string(warriors[4].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 6: { // Witch
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of witches to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[5].second = get_quantity(999);

                // Update quantity column.
                quantity_column[6] = get_color_string(std::to_string(warriors[5].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 7: { // Sorcerer
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of sorcerers to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[6].second = get_quantity(999);

                // Update quantity column.
                quantity_column[7] = get_color_string(std::to_string(warriors[6].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 8: { // Dwarf
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of dwarves to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[7].second = get_quantity(999);

                // Update quantity column.
                quantity_column[8] = get_color_string(std::to_string(warriors[7].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 9: { // Troll
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of trolls to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[8].second = get_quantity(999);

                // Update quantity column.
                quantity_column[9] = get_color_string(std::to_string(warriors[8].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 10: { // Knight
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of knights to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[9].second = get_quantity(999);

                // Update quantity column.
                quantity_column[10] = get_color_string(std::to_string(warriors[9].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 11: { // Ghost
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of ghosts to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[10].second = get_quantity(999);

                // Update quantity column.
                quantity_column[11] = get_color_string(std::to_string(warriors[10].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 12: { // Ogre
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of ogres to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[11].second = get_quantity(999);

                // Update quantity column.
                quantity_column[12] = get_color_string(std::to_string(warriors[11].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 13: { // Mammoths
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of mammoths to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[12].second = get_quantity(999);

                // Update quantity column.
                quantity_column[13] = get_color_string(std::to_string(warriors[12].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 14: { // Serpent
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of serpents to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[13].second = get_quantity(999);

                // Update quantity column.
                quantity_column[14] = get_color_string(std::to_string(warriors[13].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 15: { // Basilisk
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of basilisks to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[14].second = get_quantity(999);

                // Update quantity column.
                quantity_column[15] = get_color_string(std::to_string(warriors[14].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 16: { // Dragon
                // Print prompt.
                std::cout << "\n\n" << get_color_string("Enter the amount of dragons to add to your team.", DARK_WHITE) << "\n";

                // Update quantity.
                warriors[15].second = get_quantity(999);

                // Update quantity column.
                quantity_column[16] = get_color_string(std::to_string(warriors[15].second), WHITE);

                // Update longest length and column width.
                longest_quantity_length = get_longest_string_length(quantity_column);
                quantity_width = longest_quantity_length + 4;

                std::cout << "\n\n";
                break;
            } case 17: { // Submit
                std::cout << "\n";
                if (current_selection_cost == 0) {
                    std::cout << "\n" << get_color_string("No warriors selected.", DARK_RED) << "\n\n\n";
                } else if (current_selection_cost > max_total_cost) {
                    std::cout << "\n" << get_color_string("Exceeded max total cost.", DARK_RED) << "\n\n\n";
                } else {
                    std::cout << "\n";

                    // Snowman
                    for (unsigned int i = 0; i < warriors[0].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Snowman " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Snowman(name));
                    }

                    // Grunt
                    for (unsigned int i = 0; i < warriors[1].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Grunt " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Grunt(name));
                    }

                    // Bandit
                    for (unsigned int i = 0; i < warriors[2].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Bandit " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Bandit(name));
                    }

                    // Wolf
                    for (unsigned int i = 0; i < warriors[3].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Wolf " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Wolf(name));
                    }

                    // Goblin
                    for (unsigned int i = 0; i < warriors[4].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Goblin " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Goblin(name));
                    }

                    // Witch
                    for (unsigned int i = 0; i < warriors[5].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Witch " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Witch(name));
                    }

                    // Sorcerer
                    for (unsigned int i = 0; i < warriors[6].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Sorcerer " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Sorcerer(name));
                    }

                    // Dwarf
                    for (unsigned int i = 0; i < warriors[7].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Dwarf " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Dwarf(name));
                    }

                    // Troll
                    for (unsigned int i = 0; i < warriors[8].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Troll " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Troll(name));
                    }

                    // Knight
                    for (unsigned int i = 0; i < warriors[9].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Knight " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Knight(name));
                    }

                    // Ghost
                    for (unsigned int i = 0; i < warriors[10].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Ghost " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Ghost(name));
                    }

                    // Ogre
                    for (unsigned int i = 0; i < warriors[11].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Ogre " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Ogre(name));
                    }

                    // Mammoth
                    for (unsigned int i = 0; i < warriors[12].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Mammoth " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Mammoth(name));
                    }

                    // Serpent
                    for (unsigned int i = 0; i < warriors[13].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Serpent " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Serpent(name));
                    }

                    // Basilisk
                    for (unsigned int i = 0; i < warriors[14].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Basilisk " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Basilisk(name));
                    }

                    // Dragon
                    for (unsigned int i = 0; i < warriors[15].second; ++i) {
                        std::cout << get_color_string("Enter", DARK_WHITE) << " " << get_color_string("Dragon " + std::to_string(i + 1) + "'s", RED) << " " << get_color_string("name:", DARK_WHITE) << " " << std::flush;
                        std::string name;
                        std::getline(std::cin, name);
                        team_red.push_back(new Dragon(name));
                    }

                    is_valid_submission = true;
                }
            }
        }
    } while (is_valid_submission == false);

    std::cout << "\n";

    return team_red;
}
