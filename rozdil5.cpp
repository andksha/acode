#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

using std::cout, std::endl, std::cin, std::string;

void calculateAndPrint(int a, int b, char oprtr)
{
    switch (oprtr)
    {
    case '+':
        cout << "+:" << a + b << endl;
        break;
    case '-':
        cout << "-:" << a - b << endl;
        break;
    case '*':
        cout << "*:" << a * b << endl;
        break;
    case '/':
        cout << "/:" << a / b << endl;
        break;
    case '%':
        cout << "%:" << a % b << endl;
        break;
    default:
        cout << "Error: unrecognized operator" << endl;
        break;
    }
}

void printLesson68Task1()
{
    calculateAndPrint(3, 4, '+');
    calculateAndPrint(3, 4, '-');
    calculateAndPrint(3, 4, '*');
    calculateAndPrint(3, 4, '/');
    calculateAndPrint(3, 4, '%');
    calculateAndPrint(3, 4, '7');
}

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH
};

enum class Mammal
{
    PIG
};


std::string getAnimalName(Animal animal)
{
    switch (animal)
    {
        case Animal::PIG:
            return "pig";
        case Animal::CHICKEN:
            return "chicken";
        case Animal::GOAT:
            return "goat";
        case Animal::CAT:
            return "cat";
        case Animal::DOG:
            return "dog";
        case Animal::OSTRICH:
            return "ostrich";
        default:
        {
            return  "<getAnimalName(" + std::to_string(static_cast<int>(animal)) + "): unhandled enumerator>";
        }
    }
}

int getNumberOfLegs(Animal animal)
{
    switch (animal)
    {
        case Animal::PIG:
        case Animal::GOAT:
        case Animal::CAT:
        case Animal::DOG:
            return 4;
        case Animal::CHICKEN:
        case Animal::OSTRICH:
            return 2;
        default:
        {
            return  -1;
        }
    }
}

void printLesson68Task2()
{
    Animal cat = Animal::CAT;
    Animal chicken = Animal::CHICKEN;

    cout << "A " << getAnimalName(cat) << " has " << getNumberOfLegs(cat) << " legs." << endl;
    cout << "A " << getAnimalName(chicken) << " has " << getNumberOfLegs(chicken) << " legs." << endl;
}

void printLatinAlphabetWithASCII()
{
    int ascii = 97;

    while (ascii < 123)
    {
        cout << static_cast<char>(ascii) << " - " << ascii << endl;
        ++ascii;
    }
}

void printReversePiramid()
{
    int lineCount = 5;

    while (lineCount > 0)
    {
        int numberCount = lineCount;
        while (numberCount > 0)
        {
            cout << numberCount << " ";
            --numberCount;
        }
        cout << endl;
        --lineCount;
    }
}

/**
 * Prints piramid that looks like this:
 *         1
 *       2 1
 *     3 2 1
 *   4 3 2 1
 * 5 4 3 2 1
*/
void printRightAlignedPiramid()
{
    // current line
    int lineCount = 1;

    // there must be 5 lines
    while (lineCount <= 5)
    {
        int numberCount = 5;
        while (numberCount >= 1)
        {
            // numbers that must be printed are less than or equal to current line, e.g.:
            // line 1 has  "    1", line 2 has "   2 1", line 3 has "  3 2 1" etc 
            if (numberCount <= lineCount)
            {
                // extra space to make it look better
                cout << " " << numberCount;
            }
            else
            {
                cout << "  ";
            }
            --numberCount;
        }

        cout << endl;
        ++lineCount;
    }
    
}

void printLesson70()
{
    // printLatinAlphabetWithASCII();
    // printReversePiramid();
    printRightAlignedPiramid();
}

void printLesson71()
{
    int choice;
    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> choice;
    }
    while (choice != 1 && choice != 2 &&
        choice != 3 && choice != 4);

    cout << "You selected option #" << choice << endl;
}

int sumTo(int value)
{
    int sum{0};

    for (int i = 1; i <= value; ++i)
    {
        sum += i;
    }

    return sum;
}

void printLesson72()
{
    // for (int i = 0; i < 20; i+=2)
    // {
    //         cout << i << endl;
    // }
    cout << sumTo(6) << endl;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void printLesson74()
{
    // default C++ random number function
    // srand(static_cast<unsigned int>(time(0)));

    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << rand() << endl;
    // }

    std::random_device rd; 
    std::mt19937 mersenne(rd());

    for (int i = 0; i < 5; ++i)
    {
        cout << mersenne() << endl;
    }
}

double getValue()
{
    while (true)
    {
        cout << "Enter a double value: ";
        double a;
        cin >> a;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else 
        {
            cin.ignore(32767,'\n');
            return a;
        }
    }
}
 
char getOperator()
{
    while (true)
    {
        cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        cin >> sm;
 
        cin.ignore(32767,'\n');
 
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')    
            return sm;
        else
            cout << "Oops, that input is invalid.  Please try again.\n";
    }
}
 
void printResult(double a, char sm, double b)
{
    if (sm == '+')
        cout << a << " + " << b << " is " << a + b << '\n';
    else if (sm == '-')
        cout << a << " - " << b << " is " << a - b << '\n';
    else if (sm == '*')
        cout << a << " * " << b << " is " << a * b << '\n';
    else if (sm == '/')
        cout << a << " / " << b << " is " << a / b << '\n';
}
 
void printLesson75()
{
    double a = getValue();
    char sm = getOperator();
    double b = getValue();
 
    printResult(a, sm, b);
}

/** task 1
 * program for calculating and displaying height of ball after free fall for some time depending on initialHeight
 */
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}
 
double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen = (9.8 * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;
 
	return currentHeight;
}
 
void printHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void printTask1()
{
    double initialHeight = getInitialHeight();
    int seconds = 0;
    double currentHeight;

    do
    {
        currentHeight = calculateHeight(initialHeight, seconds);
        printHeight(currentHeight, seconds);
        ++seconds;
    } while (currentHeight > 0.0);
}

/**
 * task 2
*/

// generate num that user has to guess
int getRandomNum()
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
 
    return static_cast<int>(rand() * fraction * (100 - 1 + 1) + 1);
}

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(32767, '\n');
}

// get sanitized input num from user
int getInputNum()
{
    int input;

    while (true)
    {
        cin >> input;

        if (cin.fail() || input < 1 || input > 100)
        {
            clearInputBuffer();
            cout << "Invalid input, must be integer between 1 and 100" << endl;
        }
        else
        {
            return input;
        }
    }
}

bool wantsToKeepPlaying()
{
    cout << "Would you like to play again (y/n)?" << endl;
    char answer;

    while (true)
    {
        cin >> answer;

        if (cin.fail() || (answer != 'y' && answer != 'n'))
        {
            clearInputBuffer();
            cout << "Invalid input, must be y or n" << endl;
        }
        else if (answer == 'y')
        {
            return true;
        }
        else 
        {
            cout << "Thank you for playing." << endl;

            return false;
        }
    }
}

/**
 * runs a Hi Lo game:
 * - generates random number;
 * - user has numOfTries tries to guess said number;
 * - after finishing the game user is asked if they want to play again.
*/
bool run()
{
    int numToGuess = getRandomNum();
    int numOfTries = 7;
    int inputNum;

    cout << "Let's play a game. I'm thinking of a number. You have " << numOfTries << " tries to guess what it is." << endl;

    for (int i = 1; i <= numOfTries; ++i)
    {
        inputNum = getInputNum();
        cout << "Guess #" << i << ": " << inputNum << endl;

        if (inputNum < numToGuess)
        {
            cout << "You guess is too low." << endl;
        }
        else if (inputNum > numToGuess)
        {
            cout << "You guess is too high." << endl;
        }
        else
        {
            cout << "Correct! You win!" << endl;

            return wantsToKeepPlaying();
        }
    }

    cout << "Sorry, you lose. The correct number was " << numToGuess << endl;

    return wantsToKeepPlaying();
}

void hiLo()
{
    // configuring random numbers generator
    srand(time(0));
    rand();
    getRandomNum();

    bool wantsToKeepPlaying;

    do
    {
        wantsToKeepPlaying = run();
    } while (wantsToKeepPlaying);
}

void printLesson76()
{
    // printTask1();
    hiLo();
}