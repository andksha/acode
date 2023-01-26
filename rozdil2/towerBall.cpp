#include <iostream>
#include "constants.h"

int getInput()
{
    int i;

    std::cin >> i;

    return i;
}

float calculateHeight(int seconds)
{
    return rozdil2::g * seconds * seconds / 2;
}

void run()
{
    const int towerHeight = getInput();
    float resultHeight{};

    for (size_t i = 0; i < 6; i++)
    {
        resultHeight = towerHeight - calculateHeight(i);

        if (resultHeight > 0) {
            std::cout << resultHeight << std::endl;
        } else {
            std::cout << "The ball is on the ground at " << i << " seconds." << std::endl;
        }
    }
}
