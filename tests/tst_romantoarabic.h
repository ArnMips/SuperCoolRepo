#pragma once
#include "tst.h"


TEST(TestRomanToArabic, SimleTest1) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XI", retArabicNum);
    short correctArabicNum = 11;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest2) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MCLI", retArabicNum);
    short correctArabicNum = 1151;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest3) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MMXVIII", retArabicNum);
    short correctArabicNum = 2018;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest4) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MMMCMXCIX", retArabicNum);
    short correctArabicNum = 3999;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest5) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XXX", retArabicNum);
    short correctArabicNum = 30;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest6) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("CCC", retArabicNum);
    short correctArabicNum = 300;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest7) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("LXXX", retArabicNum);
    short correctArabicNum = 80;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest8) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MMM", retArabicNum);
    short correctArabicNum = 3000;
    EXPECT_EQ(retArabicNum, correctArabicNum);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest9) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XCI", retArabicNum);
    EXPECT_EQ(retArabicNum, 91);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest10) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("I", retArabicNum);
    EXPECT_EQ(retArabicNum, 1);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest11) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("II", retArabicNum);
    EXPECT_EQ(retArabicNum, 2);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest12) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("III", retArabicNum);
    EXPECT_EQ(retArabicNum, 3);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest13) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("IV", retArabicNum);
    EXPECT_EQ(retArabicNum, 4);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest14) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("V", retArabicNum);
    EXPECT_EQ(retArabicNum, 5);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest15) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("VI", retArabicNum);
    EXPECT_EQ(retArabicNum, 6);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest16) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("VII", retArabicNum);
    EXPECT_EQ(retArabicNum, 7);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest17) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("VIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 8);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest18) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("IX", retArabicNum);
    EXPECT_EQ(retArabicNum, 9);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest19) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XII", retArabicNum);
    EXPECT_EQ(retArabicNum, 12);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest20) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 13);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest21) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XIV", retArabicNum);
    EXPECT_EQ(retArabicNum, 14);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest22) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XV", retArabicNum);
    EXPECT_EQ(retArabicNum, 15);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest23) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XVI", retArabicNum);
    EXPECT_EQ(retArabicNum, 16);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest24) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XVII", retArabicNum);
    EXPECT_EQ(retArabicNum, 17);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest25) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XVIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 18);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest26) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XIX", retArabicNum);
    EXPECT_EQ(retArabicNum, 19);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest27) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XX", retArabicNum);
    EXPECT_EQ(retArabicNum, 20);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest28) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XXI", retArabicNum);
    EXPECT_EQ(retArabicNum, 21);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest29) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XL", retArabicNum);
    EXPECT_EQ(retArabicNum, 40);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest30) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XLII", retArabicNum);
    EXPECT_EQ(retArabicNum, 42);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest31) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("LIX", retArabicNum);
    EXPECT_EQ(retArabicNum, 59);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest32) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("LXXVII", retArabicNum);
    EXPECT_EQ(retArabicNum, 77);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest33) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XC", retArabicNum);
    EXPECT_EQ(retArabicNum, 90);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest34) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("CX", retArabicNum);
    EXPECT_EQ(retArabicNum, 110);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest35) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("CDXCIX", retArabicNum);
    EXPECT_EQ(retArabicNum, 499);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest36) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("DLXXXIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 583);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest37) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("DCCCLXXXVIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 888);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest38) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MDCLXVIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 1668);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest39) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MCMLXXXIX", retArabicNum);
    EXPECT_EQ(retArabicNum, 1989);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, SimleTest40) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("CIX", retArabicNum);
    EXPECT_EQ(retArabicNum, 109);
    EXPECT_TRUE(ret);
}
TEST(TestRomanToArabic, ErrorTest1) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest2) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("-", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest3) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("Q", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest4) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("IIII", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest5) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("XXXX", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest6) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("CCCC", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest7) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("MMMM", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest8) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("CIC", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest9) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("IIIVL", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest10) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("VVVV", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest11) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("IIIV", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
TEST(TestRomanToArabic, ErrorTest12) {
    short retArabicNum = 0;
    bool ret = convert_roman_to_arabic("VL", retArabicNum);
    EXPECT_EQ(retArabicNum, 0);
    EXPECT_FALSE(ret);
}
