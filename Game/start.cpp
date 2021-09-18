#include "print.h"
#include "user_input.h"

void print_title();
void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue);
void print_quit();

int main() {
    print_title();
    print();
    print_scenario("1", "50 knights", "50 knights");
    print_scenario("2", "1 boss", "1 boss");
    print_scenario("3", "1 catapult", "2 archers");
    print_scenario("4", "1 clubber", "1 clubber");
    print_scenario("5", "30 Vikings", "10 trebuchets");
    print_scenario("6", "5 catapults + 1 boss", "300 clubbers");
    print("...");
    print_quit();
    print();

    unsigned int choice = get_option(7);

    if (choice >= 1 && choice <= 6) {
        print("You selected a scenario.");
    } else if (choice == 7) {
        print("Bye.");
    }
}

void print_title() {
    print("************************", MAGENTA);
    print("* ", MAGENTA, false);
    print("Casual Mock Skirmish", DARK_RED, false);
    print(" *", MAGENTA);
    print("************************", MAGENTA);
}

void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue) {
    print(optionNumber, CYAN, false);
    print(" - ", DARK_WHITE, false);
    print(teamRed, RED, false);
    print(" vs ", DARK_WHITE, false);
    print(teamBlue, BLUE);
}

void print_quit() {
    print("7", YELLOW, false);
    print(" - ", DARK_WHITE, false);
    print("Quit", MAGENTA);
}
