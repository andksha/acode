#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <cstring>
#include <ios>
#include <limits>
#include <algorithm>
#include <vector>
#include <string_view>
#include <cmath>
#include <cassert>
#include <sstream>
#include <cstdarg>
#include <functional>

using std::cout, std::endl, std::cin, std::string, std::array, std::vector;

int printX()
{
    cout << "x" << endl;
    return 0;
}

int printY()
{
    cout << "Y" << endl;
    return 0;
}

void printXY(int x, int y)
{
    cout << x + y << endl;
}

void printLesson102()
{
    printXY(printX(), printY());
}

// returning by address (pointer)
int* allocateArray(int size)
{
    return new (std::nothrow) int[size];
}

// returning by reference
int& getElement(std::array<int, 20> &arr, size_t index)
{
    return arr[index];
}

void printLesson106()
{
    int *array = allocateArray(10);

    for (size_t i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    std::array<int, 20> arr{};
    getElement(arr, 5) = 10;
    cout << arr[5] << endl;

    delete[] array;
}

inline int max(int a, int b)
{
    return a < b ? b : a;
}

void printLesson107()
{
    cout << max(4, 5) << endl;
    cout << max(10, 4) << endl;
}

int sum(int a, int b)
{
    return a + b;
}

// this will not work because having parameters by default does not make function overloaded:
// int sum(int a, int b = 10);

// this will work 
double sum(double a, double b = 15)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void printLesson108()
{
    cout << max(4, 5) << endl;
    cout << max(10, 4) << endl;
}

typedef int (*operation)(int, int);
// since C++ 11
// using operation = int(*)(int, int);

// C++ 11 alternative way of defining function pointer
// #include <functional>
// void doOperation(int a, int b, std::function<int(int, int)> op)
 
void doOperation(int a, int b, operation op)
{
    cout << op(a, b) << endl;
}

void printLesson110()
{
    char answer{};
    cout << "Do you want to make a sum or substruct? ";
    cin >> answer;

    if (answer == 's')
        doOperation(2, 3, sum);
    else 
        doOperation(3, 2, sub);
}

// using operation = int(*)(int, int);

int mult(int a, int b)
{
    return a * b;
}

int divid(int a, int b)
{
    return a / b;
}

void printLesson110Test()
{
    int a{}, b{};
    char op;
    operation OP;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    do {
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    switch (op)
    {
        case '+': OP = sum; break;
        case '-': OP = sub; break;
        case '*': OP = mult; break;
        case '/': OP = divid; break;
    
        default: OP = sum; break;
    }

    cout << "Result: " << OP(a, b) << endl;

}

void printLesson112()
{
    std::vector<int> vect = { 0, 1, 2, 3, 4, 5 };
	std::cout << "size: " << vect.size() << "  cap: " << vect.capacity() << '\n';
	
	vect.push_back(6);
    vect.push_back(12);
    vect.push_back(13);
	std::cout << "size: " << vect.size() << "  cap: " << vect.capacity() << '\n';
}

int fibonacci(int n)
{
    int aa{ 0 };
    int bb{ 1 };
    int tmp{};

    for (int i = 0; i < n; ++i)
    {
        tmp = bb;
        bb = aa;
        aa = tmp + aa;
    }
    
    return aa;
}

int factorial(int n)
{
    if (n < 1)
        return 1;
    return n * factorial(n - 1);
}

int figureSum(int num)
{
    if (num < 10)
    {
        return num;
    }

    return figureSum(num / 10) + num % 10;
}

string getBinary(int n)
{
    if (n == 0)
        return "";

    return getBinary(std::ceil(n / 2)) + std::to_string(n % 2);
}

void printLesson113()
{
    // total number of fibonacci numbers to be displayed, but minus 2,
    // because the first 2 are already displayed
    // int nn{ 15 };
    
    // for (int i = 0; i < nn; i++)
    // {
    //     cout << fibonacci(i) << endl;
    // }

    // cout << "Factorial of 8 is " << factorial(8) << endl;
    // cout << "Figure sum of number 83569 is " << figureSum(83569) << endl;

    cout << "10 in binary is " << getBinary(10) << endl;
}

void testAssert(int n)
{
    // in release version #define NDEBUG must be at the top of the file in order to turn off debug;
    // static_assert works at the compilation stage
    assert(n > 0 && n < 8 && ("Assert failed" + std::to_string(n) != ""));
}

void printLesson115()
{
    testAssert(15);
}

bool isInt(string s)
{
    if (s.size() == 0)
        return false;
    
    for(size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;   
}

void printLesson116(int argc, char *argv[])
{
    
    int n;

    for (int i = 0; i < argc; i++)
    {
        if (isInt(argv[i]))
        {
            std::stringstream convert(argv[i]);
            if (!(convert >> n))
                n = 0;
            
            cout << n << " argument is numeric." << endl;
        }

        cout << i << " " << argv[i] << endl;
    }
}

double findAverage(string decoder, ...)
{
    int sum = 0;

    va_list list;
    va_start(list, decoder);

    int ii = 0;
    while(1)
    {
        char codetype = decoder[(unsigned int)ii];
        switch (codetype)
        {
            default:
            case '\0':
                va_end(list);
                return double(sum) / ii;
            case 'i':
                sum += va_arg(list, int);
                ++ii;
                break;
        }
    }
}

void printLesson117()
{
    cout << findAverage("iiii", 4, 3, 5, 7) << endl;
}

void findFood(std::function<bool(std::string_view)> findFunction)
{
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
 
    auto found{ std::find_if(
        arr.begin(),
        arr.end(),
        findFunction
    ) };
    
    if (found == arr.end())
    {
        std::cout << "No food found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }  
}

void printLesson118()
{
    findFood([](std::string_view str) -> bool {
        return (str.find("nut") != str.npos);
    });
}

struct Student
{
    std::string name;
    int points;
};

void printLesson118Test1()
{
    std::array<Student, 8> arr
    {{ 
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } 
    }};

    auto bestStudent = std::max_element(arr.begin(), arr.end(), [](const Student &s1, const Student &s2) -> bool {
        return s1.points < s2.points;
    });

    cout << bestStudent->name << " is the best student" << endl;
}

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

void printLesson118Test2()
{
    std::array<Season, 4> seasons{
        { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    std::sort(seasons.begin(), seasons.end(), [](const Season &s1, const Season &s2) -> bool {
        return s1.averageTemperature < s2.averageTemperature;
    });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }
}

auto makeWalrus(const std::string& name)
{
  // Захоплення змінної name по посиланню і повернення лямбди
  return [=]() {
    std::cout << "I am a walrus, my name is " << name << '\n'; // невизначена поведінка
  };
}
 
int printLesson119_1()
{
  // Створюємо новий об'єкт з ім'ям Roofus.
  // sayName є лямбдою, яка повертається функцією makeWalrus()
  auto sayName{ makeWalrus("Roofus") };
 
  // Виклик лямбди, яку повертає функція makeWalrus()
  sayName();
 
  return 0;
}

void invoke(const std::function<void(void)> &fn)
{
    fn();
}
 
int printLesson119_2()
{
    int i{ 0 };
 
    // Виконуємо інкремент і виводимо на екран локальну копію змінної i
    auto count{ [i]() mutable {
      std::cout << ++i << '\n';
    } };
 
    // std::ref(count) гарантує, що count розглядається, як посилання.
    // Таким чином, все, що намагається скопіювати count, фактично є посиланням,
    // гарантуючи тим самим існування тільки одного об'єкту count
    invoke(std::ref(count));
    invoke(std::ref(count));
    invoke(std::ref(count));
 
    return 0;
}

void printLesson119()
{
    // string search{};
    // cout << "Search for food: ";
    // cin >> search;

    // findFood([search](std::string_view str) -> bool {
    //     return (str.find(search) != str.npos);
    // });

    int ammo{ 10 };

    auto shoot{
        [&]() mutable {
            --ammo;
            cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };

    shoot();
    shoot();

    cout << ammo << " shot(s) left.\n";

    // printLesson119_1();
    printLesson119_2();
}

int getInputNum()
{
    int inputNum{};

    do {
        cin >> inputNum;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (inputNum <= 0);

    return inputNum;
}

int getRandomI(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 

    return static_cast<size_t>(rand() * fraction * (max - min + 1) + min);
}

using nums_list_t = std::vector<int>;

nums_list_t generateNums(int start, int count, int multiplicator)
{
    auto generateNum {
        [multiplicator](int num) -> int {
            return num * num * multiplicator;
        }
    };
    nums_list_t numbers(static_cast<size_t>(count));

    for (int &num : numbers)
    {
        num = generateNum(start); 
        ++start;
    }
    
    return numbers;
}

void makeAssumptions(nums_list_t nums)
{
    do {
        
    } while (nums.size() > 0);
}

void printLesson119Test()
{
    // needed to make getRandomI work correctly
    srand(static_cast<unsigned int>(time(0)));

    // prompting input
    cout << "Start where? ";
    int start{ getInputNum() };
    cout << "How many? ";
    int count{ getInputNum() };

    // generating numbers with multiplicator applied
    int multiplicator{ getRandomI(2, 4) };
    nums_list_t nums = generateNums(start, count, multiplicator);


    
}

void printChapter7(int argc, char *argv[])
{
    // printLesson102(); // demonstration of the order in which arguments are being passed to functions
    // printLesson106(); // returning by reference
    // printLesson107(); // inline functions
    // printLesson108(); // overloading functions
    // printLesson110(); // function pointers
    // printLesson110Test();
    // printLesson112(); // length and capacity of vectors
    // printLesson113(); // fibonacci with a loop
    // printLesson115(); // assert and static_assert
    printLesson116(argc, argv); // command line args
    // printLesson117(); // ellipsis
    // printLesson118(); // lambda
    // printLesson118Test1();
    // printLesson118Test2();
    // printLesson119(); // capture lambda
    printLesson119Test();
}