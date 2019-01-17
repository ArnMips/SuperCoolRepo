#pragma once
#include "tst.h"
#include <string>
#include <fstream>

#include "../arto-converter/artoconverter_constantstypes.h"

using namespace std;

bool isCorrectChecksum(const dcode_t& code);
bool hasSimular(const scode_t& original, const scode_t& verifiable);
std::vector<string> getSimular(const std::vector<scode_t>& sourceCodes, const scode_t& badCode);
void printCode(ostream &output, const dcode_t& code);
void printIllCode(ostream &output, const dcode_t& code);
vector<vector<int> > restoreAmbCode(const dcode_t& code, const dcode_t& predictionDigits);
void putSeparatedLineInArray(array<scode_t,DIGIT_N>& line_digits, const string& line);
void cleanStringArray(array<scode_t,DIGIT_N>& line_digits);

TEST(TestAsciiToInt, TechnologicalTest) {

}
