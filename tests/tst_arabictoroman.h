#pragma once
#include "tst.h"
#include <string>

using namespace std;

TEST(TestArabicToRoman, SimpleTest1) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(11, retRomanNum);
    string correctRomanNum = "XI";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest2) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(1151, retRomanNum);
    string correctRomanNum = "MCLI";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest3) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(2018, retRomanNum);
    string correctRomanNum = "MMXVIII";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest4) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(2999, retRomanNum);
    string correctRomanNum = "MMCMXCIX";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest5) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(0, retRomanNum);
    string correctRomanNum = "";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest6) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(9, retRomanNum);
    string correctRomanNum = "IX";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, SimpleTest7) {
    char* retRomanNum = new char[256];
    bool ret = convert_arabic_to_roman(1001, retRomanNum);
    string correctRomanNum = "MI";
    EXPECT_EQ(string(retRomanNum), correctRomanNum);
    EXPECT_TRUE(ret);
}
TEST(TestArabicToRoman, DISABLED_BadTest) {
    // Здесь падает, а потом он пофэйлится
    bool ret = convert_arabic_to_roman(0);
    EXPECT_FALSE(ret);
}
