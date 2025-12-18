#include <map>
#include <stdexcept>

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
int parse_roman(const char* str, size_t len) {
    int value = 0;
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
int operator"" _ronum(const char* str, size_t len) {
    return parse_roman(str, len);
}

namespace ronum {
    std::string ronum_from_int(int num) {
        if (num <= 0 || num > 3999) {
                throw std::out_of_range("Number must be between 1 and 3999");
            }
        
            // Roman numeral symbols and their values
            const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            const std::string symbols[] = {
                "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
            };
        
            std::string result;
            for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
                while (num >= values[i]) {
                    num -= values[i];
                    result += symbols[i];
                }
            }
            return result;
    }
}
