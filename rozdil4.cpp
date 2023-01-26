#include <iostream>
#include <typeinfo>
#include <string>

int t = 10;
int g_myglobe1{4};

using std::cout, std::endl, std::cin;

void printGlobal()
{
    std::cout << t << std::endl;
}

void printTypeId()
{
    float a{3.0};
    float b{6.3};

    std::cout << typeid(a + b).name() << " " << a + b << std::endl;

    unsigned int c = 5;
    int d = 10;

    std::cout << ((int)c) - d << std::endl;
}

void printStrings()
{
    std::string s = "34";
    std::string t = "35";

    std::cout << std::stoi(s) + std::stoi(t) << std::endl;

    std::cout << "Enter your age:" << std::endl;
    int age;
    std::cin >> age;
    std::cin.ignore(32767, '\n');

    std::cout << "Enter your full name:" << std::endl;
    std::string fullName;
    std::getline(std::cin, fullName);

    std::cout << "You've lived " << float(age) / fullName.length() << " years for each letter in your name" << std::endl;
}


void printEnums()
{
    enum class Colours {
        COLOR_RED,
        COLOR_GREEN,
        COLOR_BLUE
    };

    enum class Fruits {
        FRUIT_BANANA,
        FRUIT_APPLE
    };

    Colours c1 = Colours::COLOR_RED;
    Fruits f1 = Fruits::FRUIT_BANANA;

    if (static_cast<int>(c1) == static_cast<int>(f1)) {
        std::cout << "Color and fruit are equal" << std::endl;
    }

    int inputC;
    std::cin >> inputC;
    Colours c3 = static_cast<Colours>(inputC);
    std::cout << static_cast<int>(c3) << std::endl;
}

void printTypedef()
{
    typedef int hp_t;
    typedef int time_t;
    using mana_t = int;

    time_t timeInLava = 20;
    hp_t playerHP;
    mana_t playerMana;

    cout << "Input your hp" << endl;
    cin >> playerHP;
    cout << "Input your mana" << endl;
    cin >> playerMana;

    if (playerHP <= timeInLava) {
        cout << "You are not strong enough, you will die in lava." << endl;
    } else {
        cout << "You are strong! You will survive in lava!" << endl;
    }
}

struct Employee
{
    short id = 35;
    int age;
    double salary;
};

void printStructs()
{
    // Employee john = {25, 35, 5000};
    Employee james{};
    james = {26, 35, 6000};

    cout << "James id is " << james.id << endl;
    cout << "James age is " << james.age << endl;
    cout << "James salary is " << james.salary << endl;

    cout << "Size of James is " << sizeof(james) << endl;
}

struct Advertising
{
    int viewCount;
    double visitedPercentage;
    double averageProfitPerClick;
};

void printAdInfo(Advertising ad)
{
    cout << "View count: " << ad.viewCount << endl;
    cout << "Visited percentage: " << ad.visitedPercentage << endl;
    cout << "Average profit per click: " << ad.averageProfitPerClick << endl;

    cout << "Total profit: " << ad.viewCount * ad.visitedPercentage / 100 * ad.averageProfitPerClick << endl;
}

void lesson64PracticeTask1()
{
    Advertising ad;

    cout << "Enter view count:" << endl;
    cin >> ad.viewCount;
    cout << "Enter visited percentage:" << endl;
    cin >> ad.visitedPercentage;
    cout << "Enter average profit per click:" << endl;
    cin >> ad.averageProfitPerClick;

    printAdInfo(ad);
}

struct Drib
{
    int numerator;
    int denominator;
};

void multiplyAndPrint(Drib d1, Drib d2)
{
    std::cout << "Result: " << static_cast<double>(d1.numerator * d2.numerator) /
        (d1.denominator * d2.denominator) << std::endl;
}

void lesson64PracticeTask2()
{
    Drib d1;
    Drib d2;

    cout << "Enter drib1: " << endl;
    cin >> d1.numerator;
    cin >> d1.denominator;
    cout << "Enter drib2: " << endl;
    cin >> d2.numerator;
    cin >> d2.denominator;

    multiplyAndPrint(d1, d2);
}

void printAuto()
{
    auto a = 3.5;

    cout << typeid(a).name() << endl;
}

enum class MonsterType
{
    GOBLIN,
    ORC
};

struct Monster
{
    MonsterType type;
    std::string name;
    int hp;
};

void printMonster(Monster monster)
{
    std::string type = monster.type == MonsterType::GOBLIN ? "Goblin" : "Orc";

    cout << "This " << type << " is named " << monster.name <<
        " and has " << monster.hp << " health." << endl;
}

void printRozdil4FinalTest()
{
    Monster goblin{MonsterType::GOBLIN, "John", 170};
    Monster orc{MonsterType::ORC, "James", 35};

    printMonster(goblin);
    printMonster(orc);
}