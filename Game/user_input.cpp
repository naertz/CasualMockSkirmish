#include "user_input.h"

#include "color_text.h"

#include <climits>
#include <cstdlib>
#include <errno.h>
#include <iostream>

enum string_to_unsigned_integer_error { SUCCESS, OUT_OF_RANGE, INCONVERTIBLE };

/**
 * @brief string_to_unsigned_integer_validation parses an unsigned integer from a string and returns the error result.
 * @param parsed_unsigned_integer = integer to receive parsed result passed by reference
 * @param string_input_pointer = passed pointer to null-terminated byte string constant to be interpreted
 * @param base = integer to determine base of integer passed by value (default to 0 for auto-detected base)
 * @return = string_to_unsigned_integer_error enum representing the validation result from parsing string to integer
 */

string_to_unsigned_integer_error string_to_unsigned_integer_validation (unsigned int &parsed_unsigned_integer, const char *string_input_pointer, int base = 0) {
    // Error result to return
    string_to_unsigned_integer_error error_result;
    // Pointer to pointer of character past the last character interpreted
    char *end;
    // Unsigned long to parse from string and to be cast to unsigned integer after validation
    unsigned long unsigned_long_to_parse;
    // A preprocesor macro initialized to 0 for upcoming validation. In this case, it is used to determine if the unsigned long receives a value that is out of range.
    errno = 0;
    // Interpret unsigned integer value from byte string pointed to by the string_input_pointer.
    unsigned_long_to_parse = std::strtoul(string_input_pointer, &end, base);

    // Determine if errno is out of range AND unsigned long returns ULONG_MAX (the maximum value of an unsigned long) OR unsigned long exceeds UINT_MAX (the maximum value of an unsigned integer). Upon error, unsigned long returns 0.
    if ((errno == ERANGE && unsigned_long_to_parse == ULONG_MAX) || unsigned_long_to_parse > UINT_MAX) {
        if (*string_input_pointer == '\0' || *end != '\0') { // Prevents input such as "-5g".
            error_result = INCONVERTIBLE;
        } else { // Prevents input such as "-5" and "99999999999999999999999999999999999999".
            error_result = OUT_OF_RANGE;
        }
    } else if (*string_input_pointer == '\0' || *end != '\0') { // Determine if byte string or character pointer of last pointer returns null. Prevents input such as "5g".
        error_result = INCONVERTIBLE;
    } else { // Input is a valid integer.
        error_result = SUCCESS;
        // Cast valid unsigned long to unsigned integer.
        parsed_unsigned_integer = static_cast<unsigned int>(unsigned_long_to_parse);
    }

    // Return error result.
    return error_result;
}

/**
 * @brief string_to_unsigned_integer takes a given string and attempts to parse and return an unsigned integer. Upon error, unsigned integer is 0.
 * @param string_input = input string to be parsed
 * @param invalid_result = default value if result is invalid
 * @return = an unsigned integer parsed from the input string
 */

unsigned int string_to_unsigned_integer(std::string string_input, unsigned int invalid_result) {
    // Convert string to c-string and then convert to constant byte string to pass to validation function.
    const char * string_input_pointer = string_input.c_str();

    // Declare unsigned integer to pass by reference and to store parsed result from input string.
    unsigned int unsigned_integer_from_string = invalid_result;

    // Call validation function and store error result to enum variable.
    string_to_unsigned_integer_error error_result = string_to_unsigned_integer_validation(unsigned_integer_from_string, string_input_pointer);

    // Determine error result.
    if (error_result == OUT_OF_RANGE) {
        // Print message informing user that input is out of range (e.g., "-5", "99999999999999999999999999999999999999").
        std::cout << get_color_string("Input is out of range. Please enter a positive integer less than or equal to " + std::to_string(UINT_MAX) + ".", DARK_RED, "\n");
    } else if (error_result == INCONVERTIBLE) {
        // Print message informing user that input is not a valid integer (e.g., "5g", "-5g", "9 9").
        std::cout << get_color_string("Invalid input. Please enter a positive integer.", DARK_RED, "\n");
    }

    // Returns parsed unsigned integer.
    return unsigned_integer_from_string;
}

/**
 * @brief get_option prompts and gets validated input for option selection.
 * @param max_digit = number of options available
 * @return = validated input
 */

unsigned int get_option(unsigned int max_digit) {
    std::string prompt = get_color_string("Enter a value between ", DARK_WHITE) + get_color_string("1", CYAN) + get_color_string(" and ", DARK_WHITE) + get_color_string(std::to_string(max_digit), YELLOW) + get_color_string(": ", DARK_WHITE);

    std::string string_input = "0";

    const unsigned int invalid_input = 0;

    unsigned int answer = invalid_input;

    bool is_valid_input = false;

    std::cout << prompt << std::flush;

    while (!is_valid_input) {
        std::getline(std::cin, string_input);

        if (string_input.length() <= 2) {
            answer = string_to_unsigned_integer(string_input, invalid_input);
        }

        if (answer > 0 && answer <= max_digit) {
            is_valid_input = true;
        } else {
            std::cout << get_color_string("Invalid input. Try again...", DARK_RED, "\n") << prompt << std::flush;
        }
    }

    return answer;
}

/**
 * @brief get_quantity prompts and gets validated input for quantity.
 * @param max_digit = max quantity allowed
 * @return = validated quantity input
 */

unsigned int get_quantity(unsigned int max_digit) {
    std::string prompt = get_color_string("Enter a value between ", DARK_WHITE) + get_color_string("1", CYAN) + get_color_string(" and ", DARK_WHITE) + get_color_string(std::to_string(max_digit), CYAN) + get_color_string(": ", DARK_WHITE);

    std::string string_input = "0";

    const unsigned int invalid_input = 1000;

    unsigned int answer = invalid_input;

    bool is_valid_input = false;

    std::cout << prompt << std::flush;

    while (!is_valid_input) {
        std::getline(std::cin, string_input);

        if (string_input.length() <= 3) {
            answer = string_to_unsigned_integer(string_input, invalid_input);
        }

        if (answer >= 0 && answer <= max_digit) {
            is_valid_input = true;
        } else {
            std::cout << get_color_string("Invalid input. Try again...", DARK_RED, "\n") << prompt << std::flush;
        }
    }

    return answer;
}
