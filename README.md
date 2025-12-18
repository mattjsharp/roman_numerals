# Roman Numeral UDL
Do you find youself longing for the Roman Empire? Do you find silly little numbers like <em>0</em> and <em>-67</em> confusing? 
Are you confused by the all the weird letters around the clock face? You, my friend, are in luck! This C++ library provides a User 
Defined Literal to convert a string containing Roman Numerals over to a numeric value, and a fucniton that that converts integers to a Roman Numeral string.

## Examples
```
// _ronum UDL
int super_bowl = "LIX"_ronum;
int year = "MDCCLXXVI"_ronum;

// parsing function
std::string hour = ronum::ronum_from_int(12);
std::string star_wars = ronum::ronum_from_int(67);
```

## Building
```
mkdir build # in project root
cd build
cmake ..
```

### Requirements
- C++ 17
- Google Test (gtest)
- CMake

## Testing
Simply run `ctest` within the `build` directory to execute unit tests.
