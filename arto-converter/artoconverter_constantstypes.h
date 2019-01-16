#pragma once
#include <string>
#include <vector>
#include <array>
///
/// CONSTANTS
///
const std::string ILL_TERMINATOR = "ill";
const std::string AMB_TERMINATOR = "amb";
const std::string ERR_TERMINATOR = "err";
///
const char ILL_SYMBOL = '?';
const char BLANK_SYMBOL = ' ';
///
const int UNDEF_DIGIT = -1;
///
const int DIGIT_W = 3;
const int DIGIT_H = 4;
const int DIGIT_N = 9;
///
const int MAGIC_CHECKSUM_CONST = 11;
///
/// TYPES
///
using sdigit_t = std::string; // symbol digit type
using scode_t = std::array<sdigit_t, DIGIT_N>;  // symbol code type
using ddigit_t = int;    // digit number type
using dcode_t = std::vector<int>; // digit code type
