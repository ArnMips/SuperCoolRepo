#include "pch.h"
#include "../arto-converter/artoConverter.h"

TEST(TestRomanToArabic, Test1) {
	short retArabicNum;
	bool ret = convert_roman_to_arabic("XI", &retArabicNum);
	///
	short correctArabicNum = 11;
	EXPECT_EQ(retArabicNum, correctArabicNum);
}