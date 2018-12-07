#include "artoConverter.h"
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <array>
#define    NUMS    13

using namespace std;
static map<char, short> roman_dict = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
		{'Z', 2000},
};

template<class K, class V>
bool has_in_the_dict(const map<K, V>& dict, K value) {
    if (dict.find(value) == dict.end()) {
		return false;
	}
	return true;
}

bool is_correct_roman_number(std::string roman_number)
{
	char counter(0);
	const auto MAX_REPEATABLY_NUM = 3;
	///
	const auto first_symbol = roman_number.at(0);
    if (!has_in_the_dict<char,short>(roman_dict, first_symbol)) {
		return false;
	}
	///
	for (auto i = 0; i < roman_number.size() - 1; ++i) {
		const auto current_symbol = roman_number.at(i);
		const auto next_symbol = roman_number.at(i + 1);
        if (!has_in_the_dict<char, short>(roman_dict, next_symbol)) {
			return false;
		} else 	if (current_symbol == next_symbol)	{
			++counter;
			if (counter == MAX_REPEATABLY_NUM) {
				return false;
			}
		} else {
			counter = 0;
		}
	}
	return true;
}

bool convert_roman_to_arabic(const char* roman_num, short *arabic)
{
	string roman_number(roman_num);
	///
	if (roman_number.empty()) {
		return false;
	} else if (!is_correct_roman_number(roman_number)) {
		return false;
	}
	///
	short sum(0);

	const auto roman_n = roman_number.size();
	for (int i = roman_n - 1; i >= (int)(roman_n % 2); i -= 2) {
		const auto first_symbol = roman_number[i-1];
		const auto second_symbol = roman_number[i];
		///
		const auto arabic_first = roman_dict[first_symbol];
		const auto arabic_second= roman_dict[second_symbol];
		if (arabic_first >= arabic_second) {
			sum += arabic_first + arabic_second;
		} else {
			sum += arabic_second - arabic_first;
		}
	}
	///
    if(roman_n%2 == 1) {
		sum += roman_dict[roman_number.at(0)];
	}
	///
	*arabic = sum;
	return true;
}

bool convert_arabic_to_roman(unsigned int arabic_number, char* roman_num)
{
  if (arabic_number < 0)
    return false;
  unsigned int a_num[NUMS] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  char* r_str[NUMS] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  int counter = NUMS;
  *roman_num = '\0';
  while (counter--)
  {
    while (arabic_number >= a_num[counter]) {
      arabic_number -= a_num[counter];
      strcat(roman_num, r_str[counter]);
    }
  }
  return true;
}


int convert_asciidigit_to_arabic(istream &input, ostream &output)
{
    static const map<string, short> dict = {
        {" _ "
         "| |"
         "|_|"
         "   ", 0},
        {"   "
         "  |"
         "  |"
         "   ", 1},
        {" _ "
         " _|"
         "|_ "
         "   ", 2},
        {" _ "
         " _|"
         " _|"
         "   ", 3},
        {"   "
         "|_|"
         "  |"
         "   ", 4},
        {" _ "
         "|_ "
         " _|"
         "   ", 5},
        {" _ "
         "|_ "
         "|_|"
         "   ", 6},
        {" _ "
         "  |"
         "  |"
         "   ", 7},
        {" _ "
         "|_|"
         "|_|"
         "   ", 8},
        {" _ "
         "|_|"
         " _|"
         "   ", 9}
    };
    static const size_t DIGIT_W = 3;
    static const size_t DIGIT_H = 4;
    static const size_t DIGIT_N_MAX = 9;
    static const size_t LINE_MAX_N = DIGIT_N_MAX * DIGIT_W;

    while(!input.eof()){
        array<string,DIGIT_N_MAX> line_digits;
        string line;
        for (size_t j = 0; j < DIGIT_H; ++j) {
            std::getline(input, line);
            if (input.eof() ||
                line.size() > LINE_MAX_N ||
                line.size() <= 0 ||
                line.size() % DIGIT_W != 0) return false;

            const size_t DIGIT_N = line.size() / DIGIT_W;
            for (size_t i = 0; i < DIGIT_N; ++i) {
                line_digits[i] += line.substr(i*DIGIT_W, DIGIT_W);
            }
        }
        for(const auto& digit : line_digits){
            if (digit.empty()) continue;
            if (!has_in_the_dict<string, short>(dict, digit)) return false;
            output << dict.at(digit);
        }
        output << endl;
    }
    return true;
}
