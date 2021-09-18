#include "print.h"

#include <iostream>
#include <string>

#if defined(WINDOWS)
#include <windows.h>
#endif // OS

void print(std::string text, text_color textColor, bool newLine) {
#if defined(WINDOWS)
    // Print text with Windows console colors:

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (textColor) {
        case BLACK: {
            SetConsoleTextAttribute(hConsole, BLACK);
            break;
        } case DARK_BLUE: {
            SetConsoleTextAttribute(hConsole, DARK_BLUE);
            break;
        } case DARK_GREEN: {
            SetConsoleTextAttribute(hConsole, DARK_GREEN);
            break;
        } case DARK_CYAN: {
            SetConsoleTextAttribute(hConsole, DARK_CYAN);
            break;
        } case DARK_RED: {
            SetConsoleTextAttribute(hConsole, DARK_RED);
            break;
        } case DARK_MAGENTA: {
            SetConsoleTextAttribute(hConsole, DARK_MAGENTA);
            break;
        } case DARK_YELLOW: {
            SetConsoleTextAttribute(hConsole, DARK_YELLOW);
            break;
        } case DARK_WHITE: {
            SetConsoleTextAttribute(hConsole, DARK_WHITE);
            break;
        } case GRAY: {
            SetConsoleTextAttribute(hConsole, GRAY);
            break;
        } case BLUE: {
            SetConsoleTextAttribute(hConsole, BLUE);
            break;
        } case GREEN: {
            SetConsoleTextAttribute(hConsole, GREEN);
            break;
        } case CYAN: {
            SetConsoleTextAttribute(hConsole, CYAN);
            break;
        } case RED: {
            SetConsoleTextAttribute(hConsole, RED);
            break;
        } case MAGENTA: {
            SetConsoleTextAttribute(hConsole, MAGENTA);
            break;
        } case YELLOW: {
            SetConsoleTextAttribute(hConsole, YELLOW);
            break;
        } case WHITE: {
            SetConsoleTextAttribute(hConsole, WHITE);
            break;
        }
    }

    if (newLine) {
        std::cout << text << std::endl;
    } else {
        std::cout << text << std::flush;
    }

    SetConsoleTextAttribute(hConsole, DARK_WHITE);
#elif defined(NIX) || defined(UNKNOWN)
    // Print text with ANSI color codes:

    switch (textColor) {
        case BLACK: {
            std::cout << "\033[0;30m" << std::flush;
            break;
        } case DARK_RED: {
            std::cout << "\033[0;31m" << std::flush;
            break;
        } case DARK_GREEN: {
            std::cout << "\033[0;32m" << std::flush;
            break;
        } case DARK_YELLOW: {
            std::cout << "\033[0;33m" << std::flush;
            break;
        } case DARK_BLUE: {
            std::cout << "\033[0;34m" << std::flush;
            break;
        } case DARK_MAGENTA: {
            std::cout << "\033[0;35m" << std::flush;
            break;
        } case DARK_CYAN: {
            std::cout << "\033[0;36m" << std::flush;
            break;
        } case DARK_WHITE: {
            std::cout << "\033[0;37m" << std::flush;
            break;
        } case GRAY: {
            std::cout << "\033[1;30m" << std::flush;
            break;
        } case RED: {
            std::cout << "\033[1;31m" << std::flush;
            break;
        } case GREEN: {
            std::cout << "\033[1;32m" << std::flush;
            break;
        } case YELLOW: {
            std::cout << "\033[1;33m" << std::flush;
            break;
        } case BLUE: {
            std::cout << "\033[1;34m" << std::flush;
            break;
        } case MAGENTA: {
            std::cout << "\033[1;35m" << std::flush;
            break;
        } case CYAN: {
            std::cout << "\033[1;36m" << std::flush;
            break;
        } case WHITE: {
            std::cout << "\033[1;37m" << std::flush;
            break;
        } default: {
            std::cout << "\033[0;37m" << std::flush;
            break;
        }
    }

    if (newLine) {
        text += "\n";
    }

    std::cout << text.c_str() << "\033[0;37m" << std::flush;
#endif
}
