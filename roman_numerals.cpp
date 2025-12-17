#include <iostream>
#include <string>
#include <map>

#include "roman_numerals.hpp"

// Helper function to get the integer value of a single Roman character
int roman_char_to_int(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; // Invalid character
    }
}

// Function to parse the entire Roman numeral string
long long parse_roman(const char* str, size_t len) {
    long long value = 0;
    for (size_t i = 0; i < len; ++i) {
        int current_val = roman_char_to_int(str[i]);
        // Check if there is a next character and if it indicates a subtraction (e.g., IV = 4)
        if (i + 1 < len && current_val < roman_char_to_int(str[i+1])) {
            value -= current_val; // Subtract the current value
        } else {
            value += current_val; // Otherwise, add it
        }
    }
    return value;
}

// The user-defined literal operator
long long operator"" _ronum(const char* str, size_t len) {
    return parse_roman(str, len);
}
