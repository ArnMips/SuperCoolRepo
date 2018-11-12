#include "rta-converter.h"
#include <map>

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

bool hasInTheDict(map<char, short> dict, char arabic_letter) {
	if (dict.find(arabic_letter) == dict.end()) {
		return false;
	}
	return true;
}

bool is_correct_roman_number(roman_num roman_number)
{
	char counter(0);
	const auto MAX_REPEATABLY_NUM = 3;
	///
	const char first_symbol = roman_number.at(0);
	if (roman_dict.find(first_symbol) == roman_dict.end()) {
		return false;
	}
	///
	for (auto i = 0; i < roman_number.size() - 1; ++i) {
		auto current_symbol = roman_number.at(i);
		auto next_symbol = roman_number.at(i + 1);
		if (roman_dict)
		if (current_symbol == next_symbol)	{
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

bool convert_roman_to_arabic(roman_num roman_number short *arabic)
{
	if (roman_number.empty()) {
		return false;
	} else if (!is_correct_roman_number(roman_number)) {
		return false;
	}
	///
	short sum(0);
	for (const auto& num : roman_number) {
			



	}

	return 0;
}
