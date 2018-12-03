#include "artoConverter.h"
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include <vector>

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


bool convert_asciidigit_to_arabic(const char *filename, char &roman_num)
{
    ofstream fin(filename);
    if (!fin.is_open()){
        return false;
    }
    ifstream fout("res.txt");

    vector<string> digitLine;
    while (fin.eof()){
        string line;
        for (int i = 0; i < 4; ++i) {
            string tmp;
            fin >> tmp;
            line += tmp;
        }
        string digits;
        const int N = line.size() / 3;
        for (int i = 0; i < N; ++i) {
            short digit;
            convert_asciidigit_to_arabic_part(line.c_str(), N, &digit);
            digits += to_string(digit);
        }
        fout << digits << endl;
    }

    convert_asciidigit_to_arabic_part(filename, )
}

bool convert_asciidigit_to_arabic_part(const char *ascii, unsigned int stride, short roman_num)
{
    static const map<string, short> dict = {
        {" _ | ||_|", 0},
        {"     |  |", 1},
        {" _  _||_ ", 2},
        {" _  _| _|", 3},
        {"   |_|  |", 4},
        {" _ |_  _|", 5},
        {" _ |_ |_|", 6},
        {" _   |  |", 7},
        {" _ |_||_|", 8},
        {" _ |_| _|", 9}
    };

    std::string digit;


    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; ++j){
            digit += ascii[i * stride + j];
        }
    }

    roman_num = dict.at(digit);
}
