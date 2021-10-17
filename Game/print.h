#ifndef PRINT_H
#define PRINT_H

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#endif // OS Definitions

#include <string>

enum text_color { BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_YELLOW, DARK_WHITE, GRAY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE };

void print(std::string text = "", text_color text_color = DARK_WHITE, bool new_line=true);

#endif // PRINT_H
