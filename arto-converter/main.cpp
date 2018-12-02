#include "artoConverter.h"
#include <iostream>

int main(int argc, char *argv[]) {
    short arabic;
    convert_roman_to_arabic("XI", &arabic);
    std::cout << arabic;
    return 0;
}
