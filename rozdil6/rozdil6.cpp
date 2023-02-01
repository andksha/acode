#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <cstring>
#include <ios>
#include <limits>

using std::cout, std::endl, std::cin, std::string;

void passVal(int val)
{
    val = 100;
    cout << val << endl;
}

void passArray(int arr[20])
{
    arr[0] = 100;
}

void printLesson78()
{
    int testResult[3]{25, 50, 75};

    cout << testResult[2] << endl;

    int arr[20]{200};
    int val{200};

    cout << "Size of arr param: " << sizeof(arr) / sizeof(arr[0]) << endl;

    cout << arr[0] << endl;
    passArray(arr);
    cout << arr[0] << endl;

    cout << val << endl;
    passVal(val);
    cout << val << endl;

    double temperatures[365] = { 5 };

    cout << temperatures[55] << endl;
}

void printLesson79()
{
    // int arr[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
    // int arrLength = sizeof(arr) / sizeof(int);

    // for (int i = 0; i < arrLength; ++i)
    // {
    //     cout << arr[i] << endl;
    // }


    int scores[] = { 73, 45, 84, 44, 78 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);
 
    int maxIndex = 0;
    for (int student = 0; student < numStudents; ++student)
        if (scores[student] > scores[maxIndex])
            maxIndex = student;
 
    std::cout << "The best score's index is " << maxIndex << '\n';
}

void printSwap()
{
    int a = 3;
    int b = 5;
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
    std::swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << '\n';
}

void printChoiceMethod()
{
    const int length = 5;
	int arr[length] = { 30, 50, 20, 10, 40 };
 
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int biggestIndex = startIndex;
 
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (arr[currentIndex] > arr[biggestIndex])
            {
				biggestIndex = currentIndex;
            }
		}
 
		std::swap(arr[startIndex], arr[biggestIndex]);
	}
 
	for (int index = 0; index < length; ++index)
    {
		std::cout << arr[index] << ' ';
    }
}

void printBubbleSort()
{
    const int length(9);
    int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
 
    for (int iteration = 0; iteration < length-1; ++iteration)
    {
        int endOfArrayIndex(length - iteration);
 
        bool swapped(false);
 
        for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }
 
        if (!swapped)
        {
            std::cout << "Early termination on iteration: " << iteration+1 << '\n';
            break;
        }
    }
 
    for (int index = 0; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }
}

void printBubbleSort2()
{
    const int length(9);
    int arr[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };

    for (int i = 0; i < length; i++)
    {
        bool swapped(false);
        
        for (int j = 0; j < length - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            cout << "Early termination on iteration: " << i + 1 << endl;
            break;
        }

        cout << "Iteration #" << i << endl;
    }

    for (int index = 0; index < length; ++index)
    {
        cout << arr[index] << endl;
    }
}

void printLesson80()
{
    // printSwap();
    // printChoiceMethod();
    // printBubbleSort();
    printBubbleSort2();
}

void printLesson82()
{
    // char str[] = "string";

    // cout << str << " has " << sizeof(str) << " characters." << endl;

    // for (size_t i = 0; i < sizeof(str); i++)
    // {
    //     cout << str[i] << " ";
    //     cout << static_cast<int>(str[i]) << " ";
    // }

    // cout << endl;
    

    // char name[5];
    // char test[5];

    // cin.getline(name, 5);
    // cout << "You entered: " << name << endl;

    // cin.getline(test, 5);
    // cout << "Test: " << test << endl;


    char text[] = "Print this!";
    char copy[225];
    strcpy(copy, text);
    char toAdd[] = " <this was added> ";
    strcat(copy, toAdd);
    cout << strcmp(copy, text) << endl;
    cout << strncmp(copy, text, strlen(text)) << endl;
    cout << copy << endl;
}

std::string_view askForName()
{
    std::cout << "What's your name?\n";
 
    std::string str{};
    std::cin >> str;
    
    std::string_view view{ str };
    
    std::cout << "Hello " << view << '\n';
    
    return view;
}

void printStringView()
{
    char gold[]{ 'G', 'o', 'l', 'd' };
    std::string_view str1{ gold, std::size(gold) };
    std::string_view str2 = str1;
    std::string_view str3 = str2;

    cout << str1 << endl;
    gold[3] = 'f';
    cout << gold << endl;
    cout << sizeof(gold) << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    // std::string_view view = askForName();
    // cout << "Your name is " << view << endl;

    std::string_view name{ "name123" };
    name.remove_suffix(1);

    const char* ch{(static_cast<string>(name)).c_str()};
    cout << ch << endl;
    cout << strlen(ch) << endl;
    cout << ".data() strlen: " << strlen(name.data()) << endl;
    cout << ".data(): " << name.data() << endl;
}

void printLesson83()
{
    printStringView();
}

void testNullPointer(int *p)
{
    cout << *p << endl;
    *p = 15;
}

void printLesson84()
{
    int a = 7;
    cout << a << endl;
    cout << &a << endl;
    cout << *&a << endl;

    int *ptr = &a;
    cout << *ptr << endl;
    *ptr = 10;
    cout << a << endl;

    // pointers always have the same size (4 bytes on 32-bit systems, 8 - on 64-bit) 
    // regardless of what they point to
    cout << "Size of pointer: " << sizeof(ptr) << endl;
    testNullPointer(&a);
    cout << a << endl;
}

void printArr(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }   
}

void printArrPointer(int *arr)
{
    int it = 5;

    for (int i = 0; i < it; i++)
    {
        cout << *(arr + i) << endl;
    }
}

void printLesson85()
{
    int arr[]{ 1, 2, 10, 20};

    cout << "Arr address: " << arr << endl;
    cout << "Arr's first element address: " << &arr[0] << endl;

    int i = 10;
    int *ptr = &i;
    int **ptr2 = &ptr;

    cout << ptr << endl; // ptr stores arr memory address
    cout << &ptr << endl; // &ptr returns memory address of ptr itself
    cout << ptr2 << endl; // ptr2 stores ptr memory address
    cout << *ptr2 << endl; // *ptr2 points to value of ptr, which is arr memory address
    cout << **ptr2 << endl; // **ptr2 points to i through ptr

    // printArr(arr, std::size(arr));
    printArrPointer(arr);
}

void printLesson86()
{
    char ch[]{ 'G', 'O', 'L', 'D', '\0'};
    ch[3] = 'F';
    char ch1[] = "GOLD";
    ch1[3] = 'L';
    const char *name = "JOHN";

    cout << ch << endl;
    cout << ch1 << endl;
    cout << name << endl;
}

void printDynamicPointer(int *p)
{
    if (!p) {
        cout << "Can not print nullpointer" << endl;
        return;
    }
    cout << "Address: " << p << '\n';
    cout << "Value: " << *p << '\n';
    cout << "Size of address: " << sizeof(p) << '\n';
    cout << "Size of value: " << sizeof(*p) << '\n';
}

void printLesson89()
{
    int *ptr = new (std::nothrow) int {25};
    printDynamicPointer(ptr);
    delete ptr;
    ptr = nullptr;
    printDynamicPointer(ptr);
}

void printLesson90()
{
    cout << "Enter array length:\n";
    int length;
    cin >> length;

    int *array = new int[length];
    cout << "Array size: " << sizeof(*array) << endl;
    delete[] array;
    array = nullptr;
}

void sortNames(string *arr, int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int biggestIndex = startIndex;
 
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (arr[currentIndex] < arr[biggestIndex])
            {
				biggestIndex = currentIndex;
            }
		}
 
		std::swap(arr[startIndex], arr[biggestIndex]);
	}
}

string * allocateStrArr(int length)
{
    int maxAttempts = 10;
    cout << length << endl;

    for (int i = 0; i < maxAttempts; i++)
    {
        string *s = new (std::nothrow) string[length];
        if (s)
        {
            return s;
        }
        else
        {
            continue;
        }
    }

    cout << "Could not allocate memory from heap." << endl;
    exit(0);
}

void printLesson90Test()
{
    int numberOfNames;
    cout << "Enter number of names: \n";
    cin >> numberOfNames;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string *names = allocateStrArr(numberOfNames);

    for (int i = 0; i < numberOfNames; ++i)
    {
        cin >> names[i];
    }
    
    sortNames(names, numberOfNames);
    for (int i = 0; i < numberOfNames; ++i)
    {
        cout << names[i] << '\n';
    }
    cout << endl;

    delete[] names;
    names = nullptr;
}

void printLesson91()
{
    cout << "pointer to const\n";
    int val{8};
    const int *p1 = &val;
    cout << val << '\n'; // 8
    cout << *p1 << '\n'; // 8

    cout << "value can not be changed through pointer itself, but throught val variable it is possible:\n";
    cout << "*p = 10; - invalid\n";
    val = 10; // valid
    cout << val << '\n'; // 10
    cout << *p1 << '\n'; // 10

    cout << "pointer to const can point to a different variable\n";
    int val2{3};
    p1 = &val2;
    cout << val2 << '\n';
    cout << *p1 << '\n';

    cout << "const pointer to non-const variable\n";
    int val3{15};
    int val4{20};
    int *const p2 = &val3;
    cout << val3 << '\n';
    cout << val4 << '\n';
    cout << *p2 << '\n';

    cout << "can be used to change value of original variable\n";
    *p2 = 25;
    cout << val3 << '\n';
    cout << *p2 << '\n';

    cout << "can not be used to change address, this is invalid:\n";
    cout << "p2 = &val4\n";

}

void printLesson92()
{
    int a = 10;
    int &r = a;

    r = 5;
    cout << a << '\n';

    int val1 = 5;
    int val2 = 10;
    int &ref = val1;

    ref = val2;
    cout << ref << '\n';
    cout << val1 << '\n';
}

void printIt(const int &a)
{
    std::cout << a;
}

void printLesson93()
{
    int x = 3;
    printIt(x); // неконстантне l-value
 
    const int y = 4;
    printIt(y); // константне l-value
 
    printIt(5); // літерал в якості r-value
 
    printIt(3+y); // вираз в якості r-value
}

struct Man
{
    int earsNumber = 2;
};

void printLesson94()
{
    Man m{2};
    Man *mPtr = &m;

    cout << m.earsNumber << endl;
    cout << (*mPtr).earsNumber << endl;
    cout << mPtr->earsNumber << endl;
}

void printLesson95()
{
    string a[]{ "Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly"};
    string inputName;

    cin >> inputName;

    for (string i: a)
    {
        if (i == inputName)
        {
            cout << i << " was found." << endl;
        }
    }
}

void printArrays()
{
    // printLesson78();
    // printLesson79();
    // printLesson80();
    // printLesson82();
    // printLesson83();
    // printLesson84(); // pointers
    // printLesson85(); // array pointers
    // printLesson86(); 
    // printLesson89(); // dynamic memory allocation
    // printLesson90(); // dynamic array memory allocation
    // printLesson90Test();
    // printLesson91(); // const pointers
    // printLesson92(); // references
    // printLesson93(); // const references
    // printLesson94(); // accessing strut member using pointer
    printLesson95(); // foreach
}