#include "color_text.h"

#include <sstream>

std::string get_color_string(std::string text, color color, std::string end) {
    std::stringstream color_string;

    // Insert text with ANSI color codes to string stream.

    switch (color) {
        case BLACK: {
            color_string << "\033[0;30m";
            break;
        } case DARK_RED: {
            color_string << "\033[0;31m";
            break;
        } case DARK_GREEN: {
            color_string << "\033[0;32m";
            break;
        } case DARK_YELLOW: {
            color_string << "\033[0;33m";
            break;
        } case DARK_BLUE: {
            color_string << "\033[0;34m";
            break;
        } case DARK_MAGENTA: {
            color_string << "\033[0;35m";
            break;
        } case DARK_CYAN: {
            color_string << "\033[0;36m";
            break;
        } case DARK_WHITE: {
            color_string << "\033[0;37m";
            break;
        } case GRAY: {
            color_string << "\033[1;30m";
            break;
        } case RED: {
            color_string << "\033[1;31m";
            break;
        } case GREEN: {
            color_string << "\033[1;32m";
            break;
        } case YELLOW: {
            color_string << "\033[1;33m";
            break;
        } case BLUE: {
            color_string << "\033[1;34m";
            break;
        } case MAGENTA: {
            color_string << "\033[1;35m";
            break;
        } case CYAN: {
            color_string << "\033[1;36m";
            break;
        } case WHITE: {
            color_string << "\033[1;37m";
            break;
        } default: {
            color_string << "\033[0;37m";
            break;
        }
    }

    color_string << text << end << "\033[0;37m";

    return color_string.str();
}
