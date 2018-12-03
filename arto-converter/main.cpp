#include "artoConverter.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    short arabic = 0;
    //std::ifstream fin("/Users/ilkin_galoev/Documents/file.txt");
    std::ifstream is;
    is.open ("/Users/ilkin_galoev/Documents/file.txt");
    convert_asciidigit_to_arabic(is, std::cout);
    std::cout << arabic;
    return 0;
}
