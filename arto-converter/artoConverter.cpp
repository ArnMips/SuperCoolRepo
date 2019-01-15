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

#include "artoconverter_constantstypes.h"

// Макросы обычно используются, когда нет других альтернатив
// Здесь и константы достаточно
#define    NUMS    13

using namespace std;
// Почему не const?
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

// Функция пишется в одну строчку, но это нестрашно
// А вот то, что она при линковке будет торчать наружу это уже хуже
// Нужно либо static делать, либо в анонимный namespace помещать
template<class K, class V>
bool has_in_the_dict(const map<K, V>& dict, K value) {
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


bool isCorrectChecksum(const dcode_t& code)
{
    const size_t codeSize = code.size();
    int checksum = 0;
    for (size_t i = 0; i < codeSize; i++){
        if (code[i] < 0) return false;
        checksum += (codeSize - i) * static_cast<size_t>(code[i]);
    }
    return checksum % MAGIC_CHECKSUM_CONST == 0 ? true : false;
}

bool hasSimular(const scode_t& original, const scode_t& verifiable)
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

std::vector<string> getSimular(const std::vector<scode_t>& sourceCodes, const scode_t& badCode)
{
    std::vector<scode_t> simular;
    copy_if(sourceCodes.begin(), sourceCodes.end(), back_inserter(simular),
        [&badCode](const scode_t& sourceCode) {
            return hasSimular(sourceCode, badCode);
        }
    );
    return simular;
}

void printCode(ostream &output, const dcode_t& code)
{
    for_each(code.begin(), code.end(), [&output](const ddigit_t& d) {
        output << d;
    });
    if (!isCorrectChecksum(code)){
        output << " " << ERR_TERMINATOR;
    }
}

void printIllCode(ostream &output, const dcode_t& code)
{
    for_each(code.begin(), code.end(), [&output](const ddigit_t& d) {
        if (d == UNDEF_DIGIT) output << ILL_SYMBOL;
        else output << d;
    });
    output << " " << ILL_TERMINATOR;
}

vector<vector<int> > restoreAmbCode(const dcode_t& code, const dcode_t& predictionDigits)
{
    vector<dcode_t > restoreCodes;
    for(auto predictionDigit : predictionDigits){
        dcode_t healthyCode(code);
        replace(healthyCode.begin(), healthyCode.end(), UNDEF_DIGIT, predictionDigit);
        if (isCorrectChecksum(healthyCode)){
            restoreCodes.push_back(healthyCode);
        }
    }
    return restoreCodes;
}

void putSeparatedLineInArray(array<scode_t,DIGIT_N>& line_digits, const string& line)
{
    for (size_t i = 0; i < DIGIT_N; ++i) {
        line_digits[i] += line.substr(i*DIGIT_W, DIGIT_W);
    }
}

void cleanStringArray(array<scode_t,DIGIT_N>& line_digits)
{
    for_each(line_digits.begin(), line_digits.end(), [](sdigit_t& s){ s = "" ;});
}


int convert_asciidigit_to_arabic(istream &input, ostream &output)
{
    static const map<scode_t, short> dict = {
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
    vector<scode_t> vdict;
    for (auto d : dict) vdict.push_back(d.first);
    int currentLine(0);
    string line;
    array<scode_t,DIGIT_N> line_digits;
    bool isIll = false;
    bool isDigitMissingInDict = false;

    while(std::getline(input, line)) {
        if (input.eof()) return false;

        putSeparatedLineInArray(line_digits, line);

        if (++currentLine == DIGIT_H) {
            currentLine = 0;
            dcode_t code;
            dcode_t predictionDigits;
            for(const auto& digit : line_digits){
                if (!has_in_the_dict(dict, digit)) {
                    for(auto predictionDigit : getSimular(vdict, digit)){
                        int idigit = dict.at(predictionDigit);
                        predictionDigits.push_back(idigit);
                    }
                    if (isDigitMissingInDict || predictionDigits.empty()) {
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
            } else if (predictionDigits.empty()){
                printCode(output, code);
            } else { ///ambiguous  code
                auto restoredCode = restoreAmbCode(code, predictionDigits);
                for_each(restoredCode.begin(), restoredCode.end(), [&output](const vector<int>& code) {
                    printCode(output, code);
                    output << " ";
                });
                if (restoredCode.size() > 1) {
                    output << AMB_TERMINATOR;
                }
            }
            output << endl;

            cleanStringArray(line_digits);
            isIll = false;
            isDigitMissingInDict = false;
        }
    }
    return true;
}
