#include "artoConverter.h"
#include "stdafx.h"
#include <map>
#include <string>

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

bool has_in_the_dict(map<char, short> dict, char arabic_letter) {
	if (dict.find(arabic_letter) == dict.end()) {
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
	if (!has_in_the_dict(roman_dict, first_symbol)) {
		return false;
	}
	///
	for (auto i = 0; i < roman_number.size() - 1; ++i) {
		const auto current_symbol = roman_number.at(i);
		const auto next_symbol = roman_number.at(i + 1);
		if (!has_in_the_dict(roman_dict, next_symbol)) {
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
	if(roman_n == 1) {
		sum += roman_dict[roman_number.at(0)];
	}
	///
	*arabic = sum;
	return true;
}
