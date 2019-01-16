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

#include "artoconverter_constantstypes.h"

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
bool has_in_the_dict(const unordered_map<K, V>& dict, K value) {
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
///---------------------------------------------------------------------------------

enum class CodeCheckStatus {
    CORRECT,    // check-sum is correct
    INCORRECT,  // check-sum is NOT correct
};
enum class CodeDictStatus {
    FOUND,      // all symbols found in the dict
    MISSING,    // some symbols are incorrect (it not found in the dict)
};

static const unordered_map<sdigit_t, short> symbolDigitDict = {
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

void cleanStringArray(scode_t& symbolCode)
{
    for_each(symbolCode.begin(), symbolCode.end(), [](sdigit_t& s){ s = "" ;});
}

void putSeparatedLineInArray(scode_t& line_digits, const string& line)
{
    for (size_t i = 0; i < DIGIT_N; ++i) {
        line_digits[i] += line.substr(i*DIGIT_W, DIGIT_W);
    }
}

CodeCheckStatus getCheckCodeStatus(const scode_t& symbolCode)
{
    const size_t codeN = symbolCode.size();
    int checksum(0), idx(0);
    for (const auto& symbolDigit : symbolCode){
        if(has_in_the_dict(symbolDigitDict, symbolDigit)){
            checksum += (codeN - idx) * symbolDigitDict.at(symbolDigit);
            ++idx;
        } else {
            return CodeCheckStatus::INCORRECT;
        }
    }
    return (checksum % MAGIC_CHECKSUM_CONST == 0)
            ? CodeCheckStatus::CORRECT : CodeCheckStatus::INCORRECT;
}

CodeDictStatus getCodeDictStatus(const scode_t& symbolCode)
{
    auto nCorrectDigit = count_if(symbolCode.begin(), symbolCode.end(),
                                  [](const sdigit_t& sdigit) { return has_in_the_dict(symbolDigitDict, sdigit); }
    );

    if (static_cast<size_t>(nCorrectDigit) == symbolCode.size()){
        return CodeDictStatus::FOUND;
    } else {
        return CodeDictStatus::MISSING;
    }
}

ostream& operator<<(ostream& out, const scode_t& symbolCode)
{
    for (const sdigit_t& symbolDigit : symbolCode) {
        if(has_in_the_dict(symbolDigitDict, symbolDigit)) {
            out << symbolDigitDict.at(symbolDigit);
        } else {
            out << ILL_SYMBOL;
        }
    }
    return out;
}

ostream& operator<<(ostream& out, const std::vector<scode_t>& symbolCodes)
{

    for(auto it = symbolCodes.begin(); it != symbolCodes.end();) {
        out << *it;
        if (++it != symbolCodes.end()) {
            out << BLANK_SYMBOL;
        }
    }
    return out;
}

bool hasSimularDigit(const sdigit_t& sourceSDigit, const sdigit_t& verifiableSDigit)
{
    if(sourceSDigit.size() != verifiableSDigit.size()) return false;
    bool hasDiff = false;
    for(size_t i = 0; i < sourceSDigit.size(); ++i) {
        if(sourceSDigit[i] != verifiableSDigit[i]) {
            if(verifiableSDigit[i] != BLANK_SYMBOL) return false;
            if(hasDiff) return false;
            hasDiff = true;
        }
    }
    return true;
}

std::vector<sdigit_t> getSimilarDigits(const sdigit_t& patternSCode)
{
    static vector<sdigit_t> sourceSymbolCodes;
    if (sourceSymbolCodes.empty()) {
        for (auto d : symbolDigitDict) sourceSymbolCodes.push_back(d.first);
    }
    ///
    std::vector<sdigit_t> similarDigits;

    copy_if(sourceSymbolCodes.begin(), sourceSymbolCodes.end(),
            back_inserter(similarDigits),
            [&patternSCode](const sdigit_t& sourceSymbolCode) {
                return hasSimularDigit(sourceSymbolCode, patternSCode);
            }
    );
    return similarDigits;
}

vector<scode_t> restoreCode(const scode_t& badCode)
{    
    vector<scode_t> restoredCodes;
    for(size_t i = 0; i < badCode.size(); ++i) {
        for(const auto& digit : getSimilarDigits(badCode[i])) {
            auto tmpCode = badCode;
            tmpCode[i] = digit; // <- attempt to make correct code
            if(getCheckCodeStatus(tmpCode) == CodeCheckStatus::CORRECT) {
                restoredCodes.push_back(tmpCode);
            }
        }
    }
    return restoredCodes;
}

int convert_asciidigit_to_arabic(istream &input, ostream &output)
{
    int currentLine(0);
    string line;
    scode_t symbolCode;

    while(std::getline(input, line)) {
        if (input.eof()) return false;

        putSeparatedLineInArray(symbolCode, line);

        // all lines were read for one symbolCode
        if (++currentLine == DIGIT_H) {
            currentLine = 0;

            switch (getCheckCodeStatus(symbolCode)) {
            case CodeCheckStatus::CORRECT : {
                output << symbolCode;
            } break;
            case CodeCheckStatus::INCORRECT : {
                auto restoredCodes = restoreCode(symbolCode);
                // the code is restored uniquely
                if (restoredCodes.size() == 1) {
                    output << restoredCodes.front();
                }
                // the code is restored ambiguously
                else if (restoredCodes.size() > 1) {
                    output << restoredCodes << AMB_TERMINATOR;
                }
                // the code is not restored
                else {
                    switch (getCodeDictStatus(symbolCode)) {
                    case CodeDictStatus::MISSING : {
                        output << symbolCode << ILL_TERMINATOR;
                    } break;
                    case CodeDictStatus::FOUND : {
                        output << symbolCode << ERR_TERMINATOR;
                    } break;
                    }
                }
            } break;
            }
            output << endl;
            cleanStringArray(symbolCode);
        }
    }
    return true;
}

