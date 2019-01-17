#pragma once
#include <istream>
#include <ostream>
#include <iostream>

bool convert_roman_to_arabic(const char* roman_num, short &arabic);
bool convert_arabic_to_roman(unsigned int arabic_number, std::string &roman_num);

int convert_asciidigit_to_arabic(std::istream &input, std::ostream &output);
