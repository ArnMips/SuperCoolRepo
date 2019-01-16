#include "artoConverter.h"
#include <unordered_map>
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
#include <algorithm>

const static unsigned int NUMS = 13;

using namespace std;

const static unordered_map<char, short> roman_dict = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
		{'Z', 2000},
};

const static unordered_map<char, short> roman_num_exept_repeated = {
    {'I', 1},
    {'X', 10},
    {'C', 100},
    {'M', 1000},
};

const static unordered_map<string, short> roman_num_subtraction_rule = {
    {"IV", 4},
    {"IX", 9},
    {"XL", 40},
    {"XC", 90},
    {"CD", 400},
    {"CM", 900},
};

template<class K, class V>
static bool has_in_the_dict(const unordered_map<K, V>& dict, K value) {
    if (dict.find(value) == dict.end()) {
		return false;
	}
	return true;
}


static bool is_correct_roman_number(std::string &roman_number)
{
	char counter(0);
	const auto MAX_REPEATABLY_NUM = 3;
	///
    const auto first_symbol = roman_number.at(roman_number.size() - 1);
    if (!has_in_the_dict<char,short>(roman_dict, first_symbol)) {
		return false;
	}
	///
    for (int i = roman_number.size() - 1; i > 0 ; --i) {
        const auto current_symbol = roman_number.at(i);
        const auto next_symbol = roman_number.at(i - 1);
        if (!has_in_the_dict(roman_dict, next_symbol)) {
			return false;
        } else 	if (current_symbol == next_symbol)	{
            if (has_in_the_dict(roman_num_exept_repeated, current_symbol)) {
                ++counter;
                if (counter == MAX_REPEATABLY_NUM) {
                    return false;
                }
            } else {
                return false;
            }
		} else {
            counter = 0;
		}
        if ((roman_dict.at(next_symbol) < roman_dict.at(current_symbol))) {
            if (((i - 2) >= 0) && (roman_number.at(i - 2) == next_symbol)) {
                  return false;
            }
            char *check_this = new char [3];
            check_this[0] = next_symbol;
            check_this[1] = current_symbol;
            check_this[3] = '\0';
            if (!has_in_the_dict(roman_num_subtraction_rule, string(check_this)))
                return false;
        }
	}
	return true;
}

bool convert_roman_to_arabic(const char* roman_num, short &arabic)
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
    int i = roman_n - 1;
    for (; i >= 1; i -= 2) {
		const auto first_symbol = roman_number[i-1];
		const auto second_symbol = roman_number[i];
		///
        const auto arabic_first = roman_dict.at(first_symbol);
        const auto arabic_second= roman_dict.at(second_symbol);
		if (arabic_first >= arabic_second) {
            if ((i - 2) >= 0 && roman_dict.at(roman_number[i-2]) < arabic_first) {
                sum += arabic_second;
                i += 1;
            }
            else {
                sum += arabic_first + arabic_second;
            }
		} else {
			sum += arabic_second - arabic_first;
		}
	}
	///
    if(i == 0) {
        sum += roman_dict.at(roman_number.at(0));
	}
    ///

    arabic = sum;
	return true;
}

struct NumAR
{
    NumAR(int _aNum, char *_rStr): a_num(_aNum), r_str(_rStr)
    {
    }
    const int a_num;
    const string r_str;
};


bool convert_arabic_to_roman(unsigned int arabic_number, string &roman_num)
{
  if (arabic_number <= 0)
    return false;

  int counter = NUMS;
  const static NumAR dict[NUMS] = {NumAR(1, "I"),
                     NumAR(4, "IV"),
                     NumAR(5, "V"),
                     NumAR(9, "IX"),
                     NumAR(10, "X"),
                     NumAR(40, "XL"),
                     NumAR(50, "L"),
                     NumAR(90, "XC"),
                     NumAR(100, "C"),
                     NumAR(400, "CD"),
                     NumAR(500, "D"),
                     NumAR(900, "CM"),
                     NumAR(1000, "M")};

  while (counter--)
  {
    while (arabic_number >= dict[counter].a_num) {
      arabic_number -= dict[counter].a_num;
      roman_num.append(dict[counter].r_str);
    }
  }
  return true;
}

////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------

// Опять макросы, обычные константы намного лучше
#define ILL_TERMINATOR       "ill"
#define AMB_TERMINATOR       "amb"
#define ERR_TERMINATOR       "err"
#define UNDEF_DIGIT          -1
#define ILL_SYMBOL           '?'
#define MAGIC_CHECKSUM_CONST 11

#define DIGIT_W 3
#define DIGIT_H 4
#define DIGIT_N 9
#define LINE_N (DIGIT_N * DIGIT_W)


bool calculate_checksum(vector<int> code)
{
    const int codeSize = code.size();
    int checksum = 0;
    for (int i = 0; i<codeSize; i++){
        checksum += (codeSize - i) * code[i];
    }
    return checksum % MAGIC_CHECKSUM_CONST == 0 ? true : false;
}

bool hasSimular(const string& original, const string& verifiable)
{
    static const char BLANK = ' ';
    if (original.size() != verifiable.size()) return false;
    bool hasDiff = false;
    for (size_t i = 0; i < original.size(); ++i) {
        if (original[i] != verifiable[i]) {
            if (verifiable[i] != BLANK) return false;
            if (hasDiff) return false;
            hasDiff = true;
        }
    }
    return true;
}

std::vector<string> getSimular(const std::vector<string>& originals, const string& pattern)
{
    std::vector<string> simular;
    for (auto & original : originals) {
        if(hasSimular(original, pattern)) {
            simular.push_back(original);
        }
    }
    return simular;
}

void printCode(ostream &output, const vector<int>& code)
{
    for_each(code.begin(), code.end(), [&output](const int& d) {
        output << d;
    });
    if (!calculate_checksum(code)){
        output << " " << ERR_TERMINATOR;
    }
}

void printIllCode(ostream &output, const vector<int>& code)
{
    for_each(code.begin(), code.end(), [&output](const int& d) {
        if (d == UNDEF_DIGIT) output << ILL_SYMBOL;
        else output << d;
    });
    output << " " << ILL_TERMINATOR;
}

void printAmbCode(ostream &output, const vector<int>& code, const vector<int>& predictionCode)
{
    for(auto predictionDigit : predictionCode){
        vector<int> healthyCode;
        for (auto digit : code){
            auto healthyDigit = (digit == UNDEF_DIGIT ? predictionDigit : digit);
            healthyCode.push_back(healthyDigit);
        }
        printCode(output, healthyCode);
        output << " ";
    }
    output << AMB_TERMINATOR;
}

void putSeparatedLineInArray(array<string,DIGIT_N>& line_digits, const string& line)
{
    for (size_t i = 0; i < DIGIT_N; ++i) {
        line_digits[i] += line.substr(i*DIGIT_W, DIGIT_W);
    }
}

void cleanStringArray(array<string,DIGIT_N>& line_digits)
{
    for_each(line_digits.begin(), line_digits.end(), [](string& s){ s = "" ;});
}


int convert_asciidigit_to_arabic(istream &input, ostream &output)
{
    static const unordered_map<string, short> dict = {
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
    vector<string> vdict;
    for (auto d : dict) vdict.push_back(d.first);
    int currentLine(0);
    string line;
    array<string,DIGIT_N> line_digits;
    bool isIll = false;
    bool isDigitMissingInDict = false;

    while(std::getline(input, line)) {
        if (input.eof() || line.size() != LINE_N) return false;

        putSeparatedLineInArray(line_digits, line);

        if (++currentLine == DIGIT_H) {
            currentLine = 0;
            vector<int> code;
            vector<int> predictionCode;
            for(const auto& digit : line_digits){
                if (!has_in_the_dict<string, short>(dict, digit)) {
                    for(auto predictionDigit : getSimular(vdict, digit)){
                        int idigit = dict.at(predictionDigit);
                        predictionCode.push_back(idigit);
                    }
                    if (isDigitMissingInDict || predictionCode.empty()) {
                        isIll = true;
                    }
                    isDigitMissingInDict = true;
                    code.push_back(UNDEF_DIGIT);
                } else {
                    code.push_back(dict.at(digit)); 
                }
            }
            if (isIll){
                printIllCode(output, code);
            } else if (predictionCode.empty()){
                printCode(output, code);
            } else {
                printAmbCode(output, code, predictionCode);
            }
            output << endl;

            cleanStringArray(line_digits);
            isIll = false;
            isDigitMissingInDict = false;
        }
    }
    return true;
}

