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
#include "select.h"

#include <ctime>
#include <iostream>
#include <sstream>

#if defined(WINDOWS)
#include <windows.h>
#endif // OS

static std::string get_title_heading(void);

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
    std::cout << get_title_heading() << "\n\n\n";

    // Run select scenario menu.
    select_scenario();

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
