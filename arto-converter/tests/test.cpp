#include "pch.h"
#include "../arto-converter/artoConverter.h"

TEST(TestRomanToArabic, SimleTest_1) {
	short retArabicNum = ;
	bool ret = convert_roman_to_arabic("XI", &retArabicNum);
	short correctArabicNum = 11;
	EXPECT_EQ(retArabicNum, correctArabicNum);
	EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest_2) {
	short retArabicNum = ;
	bool ret = convert_roman_to_arabic("MCLI", &retArabicNum);
	short correctArabicNum = 1151;
	EXPECT_EQ(retArabicNum, correctArabicNum);
	EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest_3) {
	short retArabicNum = 0;
	bool ret = convert_roman_to_arabic("MMXVIII", &retArabicNum);
	short correctArabicNum = 2018;
	EXPECT_EQ(retArabicNum, correctArabicNum);
	EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, ErrorTest_1) {
	short retArabicNum = 0;
	bool ret = convert_roman_to_arabic("", &retArabicNum);
	EXPECT_EQ(retArabicNum, 0);
	EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest_2) {
	short retArabicNum = 0;
	bool ret = convert_roman_to_arabic("-", &retArabicNum);
	EXPECT_EQ(retArabicNum, 0);
	EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest_3) {
	short retArabicNum = 0;
	bool ret = convert_roman_to_arabic("Q", &retArabicNum);
	EXPECT_EQ(retArabicNum, 0);
	EXPECT_FALSE(ret);
}