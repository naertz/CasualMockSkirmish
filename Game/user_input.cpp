#include "print.h"
#include "user_input.h"

#include <climits>
#include <cstdlib>
#include <errno.h>
#include <iostream>

enum stringToUnsignedIntegerError { SUCCESS, OUT_OF_RANGE, INCONVERTIBLE };

/**
 * @brief string_to_unsigned_integer_validation parses an unsigned integer from a string and returns the error result.
 * @param parsedUnsignedInteger = Integer to receive parsed result passed by reference
 * @param stringInputPointer = Passed pointer to null-terminated byte string constant to be interpreted
 * @param base = Integer to determine base of integer passed by value (default to 0 for auto-detected base)
 * @return = stringToUnsignedIntegerError enum representing the validation result from parsing string to integer
 */

stringToUnsignedIntegerError string_to_unsigned_integer_validation (unsigned int &parsedUnsignedInteger, const char *stringInputPointer, int base = 0) {
    // Error result to return
    stringToUnsignedIntegerError errorResult;
    // Pointer to pointer of character past the last character interpreted
    char *end;
    // Unsigned long to parse from string and to be cast to unsigned integer after validation
    unsigned long unsignedLongToParse;
    // A preprocesor macro initialized to 0 for upcoming validation. In this case, it is used to determine if the unsigned long receives a value that is out of range.
    errno = 0;
    // Interpret unsigned integer value from byte string pointed to by the stringInputPointer.
    unsignedLongToParse = std::strtoul(stringInputPointer, &end, base);

    // Determine if errno is out of range AND unsigned long returns ULONG_MAX (the maximum value of an unsigned long) OR unsigned long exceeds UINT_MAX (the maximum value of an unsigned integer). Upon error, unsigned long returns 0.
    if ((errno == ERANGE && unsignedLongToParse == ULONG_MAX) || unsignedLongToParse > UINT_MAX) {
        if (*stringInputPointer == '\0' || *end != '\0') { // Prevents input such as "-5g".
            errorResult = INCONVERTIBLE;
        } else { // Prevents input such as "-5" and "99999999999999999999999999999999999999".
            errorResult = OUT_OF_RANGE;
        }
    } else if (*stringInputPointer == '\0' || *end != '\0') { // Determine if byte string or character pointer of last pointer returns null. Prevents input such as "5g".
        errorResult = INCONVERTIBLE;
    } else { // Input is a valid integer.
        errorResult = SUCCESS;
        // Cast valid unsigned long to unsigned integer.
        parsedUnsignedInteger = static_cast<unsigned int>(unsignedLongToParse);
    }

    // Return error result.
    return errorResult;
}

/**
 * @brief string_to_unsigned_integer takes a given string and attempts to parse and return an unsigned integer. Upon error, unsigned integer is 0.
 * @param stringInput = Input string to be parsed
 * @return = an unsigned integer parsed from the input string
 */

unsigned int string_to_unsigned_integer(std::string stringInput) {
    // Convert string to c-string and then convert to constant byte string to pass to validation function.
    const char * stringInputPointer = stringInput.c_str();

    // Declare unsigned integer to pass by reference and to store parsed result from input string.
    unsigned int unsignedIntegerFromString = 0;

    // Call validation function and store error result to enum variable.
    stringToUnsignedIntegerError errorResult = string_to_unsigned_integer_validation(unsignedIntegerFromString, stringInputPointer);

    // Determine error result.
    if (errorResult == OUT_OF_RANGE) {
        // Print message informing user that input is out of range (e.g., "-5", "99999999999999999999999999999999999999").
        std::cout << "Input is out of range. Please enter a positive integer less than or equal to " << UINT_MAX << "." << std::endl;
    } else if (errorResult == INCONVERTIBLE) {
        // Print message informing user that input is not a valid integer (e.g., "5g", "-5g", "9 9").
        std::cout << "Invalid input. Please enter a positive integer." << std::endl;
    }

    // Returns parsed unsigned integer.
    return unsignedIntegerFromString;
}

unsigned int get_option(unsigned int maxDigit) {
    std::string prompt = "Enter a value between 1 and " + std::to_string(maxDigit) + ": ";

    std::string stringInput = "0";

    unsigned int answer = 0;

    bool isValidInput = false;

    print(prompt, CYAN, false);

    while (!isValidInput) {
        std::getline(std::cin, stringInput);

        if (stringInput.length() <= 2) {
            answer = string_to_unsigned_integer(stringInput);
        }

        if (answer > 0 && answer <= maxDigit) {
            isValidInput = true;
        } else {
            print("Invalid input. Try again...", DARK_RED);
            print(prompt, CYAN, false);
        }
    }

    return answer;
}
