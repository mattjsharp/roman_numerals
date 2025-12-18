#pragma once

#include <string>

/// Maxium Roman numeral value is 3999 (MMMCMXCIX)
int operator"" _ronum(const char* str, size_t len);

namespace ronum {
    std::string ronum_from_int(int num);
}