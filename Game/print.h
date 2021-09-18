#ifndef PRINT_H
#define PRINT_H

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
#define NIX
#else
#define UNKNOWN
#endif // OS Definitions

#include <string>

enum text_color { BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_YELLOW, DARK_WHITE, GRAY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE };

void print(std::string text = "", text_color textColor = DARK_WHITE, bool newLine=true);

#endif // PRINT_H
