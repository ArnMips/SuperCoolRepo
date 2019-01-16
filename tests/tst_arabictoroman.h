#pragma once
#include "tst.h"
#include <string>

using namespace std;

TEST(TestArabicToRoman, SimpleTest1) {    
    string retStr;
    bool ret = convert_arabic_to_roman(11, retStr);
    string correctRomanNum = "XI";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest2) {
    string retStr;
    bool ret = convert_arabic_to_roman(1151, retStr);
    string correctRomanNum = "MCLI";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest3) {
    string retStr;
    bool ret = convert_arabic_to_roman(2018, retStr);
    string correctRomanNum = "MMXVIII";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest4) {
    string retStr;
    bool ret = convert_arabic_to_roman(2999, retStr);
    string correctRomanNum = "MMCMXCIX";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest5) {
    string retStr;
    bool ret = convert_arabic_to_roman(0, retStr);
    EXPECT_FALSE(ret);
}
TEST(TestArabicToRoman, SimpleTest6) {
    string retStr;
    bool ret = convert_arabic_to_roman(9, retStr);
    string correctRomanNum = "IX";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest7) {
    string retStr;
    bool ret = convert_arabic_to_roman(1001, retStr);
    string correctRomanNum = "MI";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest8) {
    string retStr;
    bool ret = convert_arabic_to_roman(3999, retStr);
    string correctRomanNum = "MMMCMXCIX";
    EXPECT_EQ(retStr, correctRomanNum);
    EXPECT_TRUE(ret);
}

