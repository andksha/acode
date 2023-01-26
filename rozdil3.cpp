#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

// void printTwoMinuses()
// {
//     int x = 5 - -3;

//     std::cout << x << std::endl;
// }

// void printDividingInts()
// {
//     int x = 8;
//     int y = 5;

//     std::cout << x / y << std::endl;
//     std::cout << static_cast<double>(x) / y << std::endl;
//     std::cout << x / static_cast<double>(y) << std::endl;
//     std::cout << static_cast<double>(x) / static_cast<double>(y) << std::endl;
// }

// bool isEven(int a)
// {
//     return a % 2 == 0;
// }

// bool isAlmostEqual(double a, double b, double epsilon)
// {
//     return (fabs(a - b) <= epsilon);
// }

// bool approximatelyEqual(double a, double b, double epsilon)
// {
//     return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
// }

// bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
// {
//     double diff = fabs(a - b);
    
//     if (diff <= absEpsilon) {
//         return true;
//     }
 
//     return diff <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
// }

// void printDoubleComparison()
// {
//     // double d1(100 - 99.99);
//     // double d2(10 - 9.99);

//     // std::cout << d1 << std::endl;
//     // std::cout << d2 << std::endl;
//     // std::cout << isAlmostEqual(d1, d2, 1e-7) << std::endl;

//     double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
//     std::cout << approximatelyEqualAbsRel(a, 1.0, 1e-12, 1e-8) << std::endl;
//     std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << std::endl;
// }

// void printOr()
// {
//     std::cout << (5 != 0) << std::endl;
// }

// void printInt8AsBinary()
// {
//     unsigned long int a;
//     std::cin >> a;

//     std::cout << "Your nubmer: " << a << std::endl;
//     std::cout << std::bitset<8>(a).to_string() << std::endl;
// }

// void printBinaryOperators()
// {
//     // int x = 3;

//     // std::cout << "multiplying x by 2 5 times" << std::endl;
//     // x <<= 5;
//     // std::cout << x << std::endl;
    
//     // std::cout << "deviding x by 2 3 times" << std::endl;
//     // x >>= 3;
//     // std::cout << x << std::endl;
//     // std::cout << sizeof(x) << std::endl;

//     std::cout << (5 | 12) << std::endl;
// }

const unsigned char isHungry = 0x01; // шістнадцятковий літерал для 0000 0001
const unsigned char isSad = 0x02; // шістнадцятковий літерал для 0000 0010
const unsigned char isFed = 0x04; // шістнадцятковий літерал для 0000 0100
const int isHappy = 4;
const int isDry = 5;

bool checkIfHungryAndSad(unsigned char flag)
{
    return static_cast<bool>(flag & (isHungry | isSad)); 
}

unsigned char feed(unsigned char flag)
{
    flag |= isFed;
    flag &= static_cast<unsigned char>(~(isHungry | isSad));

    return flag;
}

void coutFlag(unsigned char flag)
{
    std::cout << std::bitset<8>(flag).to_string() << std::endl;
}

void coutFlag(std::bitset<8> flag)
{
    std::cout << flag.to_string() << std::endl;
}

void printBinaryFlags()
{
    // const unsigned char isHappy = 0x08; // шістнадцятковий літерал для 0000 1000
    // const unsigned char isDry = 0x10; // шістнадцятковий літерал для 0001 0000
    // const unsigned char isDead = 0x20; // шістнадцятковий літерал для 0010 0000
    // const unsigned char isQuirky = 0x40; // шістнадцятковий літерал для 0100 0000
    // const unsigned char isTall = 0x80; // шістнадцятковий літерал для 1000 0000

    unsigned char flag = 0;
    coutFlag(flag);
    flag |= (isHungry | isSad);
    coutFlag(flag);
    std::cout << checkIfHungryAndSad(flag) << std::endl;
    flag = feed(flag);
    coutFlag(flag);
    std::cout << checkIfHungryAndSad(flag) << std::endl;
}

void printBinaryFlagsWithSTDBits()
{
    std::bitset<8> flag = 0;
    flag.set(isHappy)
        .set(isDry);

    coutFlag(flag);
}

void printArticle()
{
    unsigned char option_viewed = 0x01;
    // unsigned char option_edited = 0x02;
    unsigned char option_favorited = 0x04;
    // unsigned char option_shared = 0x08;
    // unsigned char option_deleted = 0x80;
 
    unsigned char myArticleFlags = 0;

    myArticleFlags |= option_viewed;
    myArticleFlags |= option_favorited;
    std::cout << std::bitset<8> (myArticleFlags).to_string() << std::endl;
    myArticleFlags &= ~option_favorited;

    std::cout << std::bitset<8>(myArticleFlags).to_string() << std::endl;
}

void printBinaryMask()
{
    int i = 157;
    const unsigned int mask = 0xF;

    std::cout << mask << std::endl;
    coutFlag(static_cast<std::bitset<8>>((unsigned int)i));
    i &= (int)mask;
    coutFlag(static_cast<std::bitset<8>>(mask));
    std::cout << i << std::endl;
    coutFlag(static_cast<std::bitset<8>>((unsigned int)i));
}

