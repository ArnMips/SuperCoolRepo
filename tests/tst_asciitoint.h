#pragma once
#include "tst.h"
#include <string>
#include <fstream>

using namespace std;

string readFile(const string& fileName) {
    string strFile;
    ifstream file(fileName);
    getline(file, strFile, '\0');
    file.close();
    return strFile;
}

string pathToFiles = "/Users/ilkin_galoev/Documents/7 semester/Designing of information systems/SuperCoolRepo/tests/";

TEST(TestAsciiToInt, SimpleTest1) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile1.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[4] = { "320123456\n", "878902459 err\n", "546957811\n", "546?5?8?6 ill\n" };
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3]);
}
TEST(TestAsciiToInt, SimpleTest2) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile2.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[3] = { "012345678 err\n", "999999990\n", "3?0?2?4?6 ill\n" };
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2]);
}
TEST(TestAsciiToInt, SimpleTest3) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile3.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[10] = { "000000000\n",
                                "111111110\n",
                                "222222220\n",
                                "333333330\n",
                                "444444440\n",
                                "555555550\n",
                                "666666660\n",
                                "777777770\n",
                                "888888880\n",
                                "999999990\n"};
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3] + correctCodes[4]  + correctCodes[5]  + correctCodes[6]  + correctCodes[7]  + correctCodes[8]  + correctCodes[9]);
}
TEST(TestAsciiToInt, SimpleTest4) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile4.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[10] = { "000000001 err\n",
                                "111111111 err\n",
                                "222222222 err\n",
                                "333333333 err\n",
                                "444444444 err\n",
                                "555555555 err\n",
                                "666666666 err\n",
                                "777777777 err\n",
                                "888888888 err\n",
                                "999999999 err\n" };
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3] + correctCodes[4]  + correctCodes[5]  + correctCodes[6]  + correctCodes[7]  + correctCodes[8]  + correctCodes[9]);
}
TEST(TestAsciiToInt, SimpleTest5) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile5.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[10] = { "0?0??0?01 ill\n",
                                "1?1??1?11 ill\n",
                                "2?2??2?22 ill\n",
                                "3?3??3?33 ill\n",
                                "4?4??4?44 ill\n",
                                "5?5??5?55 ill\n",
                                "6?6??6?66 ill\n",
                                "7?7??7?77 ill\n",
                                "8?8??8?88 ill\n",
                                "9?9??9?99 ill\n" };
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3] + correctCodes[4]  + correctCodes[5]  + correctCodes[6]  + correctCodes[7]  + correctCodes[8]  + correctCodes[9]);
}
TEST(TestAsciiToInt, SimpleTest6) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile6.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[4] = { "320122456 err 320123456 amb\n", "878902459 err 878902439 err amb\n", "546957811\n", "546?5?8?6 ill\n" };
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3]);
}
TEST(TestAsciiToInt, SimpleTest7) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile7.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[10] = { "000000001 err amb\n",
                                "111111111 err amb\n",
                                "222222222 err amb\n",
                                "333333333 err 353333333 err amb\n",
                                "444444444 err amb\n",
                                "555555555 err 535555555 err amb\n",
                                "666666666 err amb\n",
                                "777777777 err amb\n",
                                "888888888 err amb\n",
                                "999999999 err amb\n" };
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3] + correctCodes[4]  + correctCodes[5]  + correctCodes[6]  + correctCodes[7]  + correctCodes[8]  + correctCodes[9]);
}
TEST(TestAsciiToInt, SimpleTest8) {
    auto istr = createStream<std::istream>(pathToFiles+"TestFile8.txt");
    auto ostr = createStream<std::ostream>(pathToFiles+"Result.txt");
    bool ret = convert_asciidigit_to_arabic(*istr, *ostr);
    string correctCodes[10] = { "000000000 amb\n",
                                "111111110 amb\n",
                                "2?2222220 ill\n",
                                "3?33?333? ill\n",
                                "444444440 amb\n",
                                "555555550 553555550 err amb\n",
                                "66?66?660 ill\n",
                                "777777770 amb\n",
                                "888888880 amb\n",
                                "999999990\n"};
    EXPECT_TRUE(ret);
    EXPECT_EQ(readFile(pathToFiles+"Result.txt"), correctCodes[0] + correctCodes[1] + correctCodes[2] + correctCodes[3] + correctCodes[4]  + correctCodes[5]  + correctCodes[6]  + correctCodes[7]  + correctCodes[8]  + correctCodes[9]);
}
