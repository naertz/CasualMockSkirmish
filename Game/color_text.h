#ifndef COLOR_TEXT_H
#define COLOR_TEXT_H

#include <string>

enum color { BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_YELLOW, DARK_WHITE, GRAY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE };

std::string get_color_string(std::string text = "", color color = DARK_WHITE, std::string end = "");

#endif // COLOR_TEXT_H
