#pragma once
#include <istream>
#include <ostream>
#include <iostream>

bool convert_roman_to_arabic(const char* roman_num, short *arabic= nullptr);
// С такой сигнатурой вряд ли что-то будет работать
bool convert_arabic_to_roman(unsigned int arabic_number, char* roman_num  = nullptr);

int convert_asciidigit_to_arabic(std::istream &input, std::ostream &output);
