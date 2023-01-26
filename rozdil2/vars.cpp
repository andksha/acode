#include <iostream>
#include <cstdint>

void printIntSizes()
{
    std::uint64_t i = 0;
    std::int64_t o = 9;
    std::int8_t p = 65;

    std::cout << "uint64_t:\t" << sizeof(i) << " bytes" << std::endl;
    std::cout << "int64_t:\t" << sizeof(o) << " bytes" << std::endl;
    std::cout << "int8_t:\t" << p << std::endl;
}

void printFloats()
{
    // double i = 0.1;
    double j = 1.0;
    double d(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

    std::cout << j << std::endl;
    std::cout << d << std::endl;
}

void printChars()
{
    char ch(75);
    char ch1('a');

    std::cout << ch << std::endl;
    std::cout << ch1 << std::endl;
    std::cout << static_cast<int>(ch) << std::endl;
}

void printConst()
{
    const int charHP = 300;

    std::cout << charHP << std::endl;
}