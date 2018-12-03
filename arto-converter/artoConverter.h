#pragma once

bool convert_roman_to_arabic(const char* roman_num, short *arabic= nullptr);
bool convert_arabic_to_roman(unsigned int arabic_number, char* roman_num  = nullptr);

bool convert_asciidigit_to_arabic_part(const char *ascii, unsigned int stride, short roman_num)
