#pragma once
#include <string>
#include <vector>

///
/// CONSTANTS
///
const std::string ILL_TERMINATOR = "ill";
const std::string AMB_TERMINATOR = "amb";
const std::string ERR_TERMINATOR = "err";
///
const char ILL_SYMBOL = '?';
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
using scode_t = std::string;  // symbol code type
using sdigit_t = std::string; // symbol digit type
using ddigit_t = int;    // digit number type
using dcode_t = std::vector<int>; // digit code type
