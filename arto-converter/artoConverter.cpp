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
#include <algorithm>
#include <unordered_map>

#include "artoconverter_constantstypes.h"

// Макросы обычно используются, когда нет других альтернатив
// Здесь и константы достаточно
#define    NUMS    13

using namespace std;
// Почему не const?
static unordered_map<char, short> roman_dict = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
		{'Z', 2000},
};

// Функция пишется в одну строчку, но это нестрашно
// А вот то, что она при линковке будет торчать наружу это уже хуже
// Нужно либо static делать, либо в анонимный namespace помещать
template<class K, class V>
bool has_in_the_dict(const unordered_map<K, V>& dict, K value) {
    if (dict.find(value) == dict.end()) {
		return false;
	}
	return true;
}

// Также вопрос по линковке
// Строку лучше передавать по ссылке
// Эту функцию обязательно нужно покрывать тестами отдельно
// Кажется, что эта функция не работает, так как CIC и IIIVL
// не являются корректными римскими числами
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
        // Типы-параметры здесь необязательно писать, если правильно описать шаблон
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
    // Что, если arabic == nullptr
    // И, разумеется, должен быть написан такой тест
	*arabic = sum;
	return true;
}

// Чтобы воспользовать этой функцией пользователю нужно знать, сколько памяти выделить
// под ответ. При этом никакого способа проверки того, хватило ли памяти нет
// Это плохой интерфейс
bool convert_arabic_to_roman(unsigned int arabic_number, char* roman_num)
{
  // Что, если arabic_number == 0
  if (arabic_number < 0)
    return false;

  // Иметь два тесно связанных массива обычно плохо
  // Лучше завести массив структур или map
  unsigned int a_num[NUMS] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  // Данная вещь не требует пересоздания на каждом вызове функции,
  // и она не меняется
  // Более того, если попытаться поменять данный массив, то могут вохзникнуть проблемы
  char* r_str[NUMS] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  int counter = NUMS;
  *roman_num = '\0';
  // А если roman_num == nullptr
  while (counter--)
  {
    while (arabic_number >= a_num[counter]) {
      arabic_number -= a_num[counter];
      strcat(roman_num, r_str[counter]);
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
        out << (has_in_the_dict(symbolDigitDict, symbolDigit)
                ? symbolDigitDict.at(symbolDigit)
                : ILL_SYMBOL);
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
    return sourceSymbolCodes;
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
    ///
    while(std::getline(input, line)) {
        if (input.eof()) return false;
        ///
        putSeparatedLineInArray(symbolCode, line);
        ///
        // was readed all for lines of symbole code
        if (++currentLine == DIGIT_H) {
            currentLine = 0;
            ///
            auto codeStatus = getCheckCodeStatus(symbolCode);
            switch (codeStatus) {
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
                    for (const auto& restoredCode : restoredCodes){
                        output << restoredCode << BLANK_SYMBOL;
                    }
                    output << AMB_TERMINATOR;
                }
                // the code is not restored
                else {
                    switch (getCodeDictStatus(symbolCode)) {
                    case CodeDictStatus::MISSING : {
                        output << symbolCode << BLANK_SYMBOL << ILL_TERMINATOR;
                    } break;
                    case CodeDictStatus::FOUND : {
                        output << symbolCode << BLANK_SYMBOL << ERR_TERMINATOR;
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
