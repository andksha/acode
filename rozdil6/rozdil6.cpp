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

using std::cout, std::endl, std::cin, std::string, std::array, std::vector;

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
    int array1[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
 
    for (int iteration = 0; iteration < length-1; ++iteration)
    {
        int endOfArrayIndex(length - iteration);
 
        bool swapped(false);
 
        for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            if (array1[currentIndex] > array1[currentIndex + 1])
            {
                std::swap(array1[currentIndex], array1[currentIndex + 1]);
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
        std::cout << array1[index] << ' ';
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

    int *array1 = new int[length];
    cout << "Array size: " << sizeof(*array1) << endl;
    delete[] array1;
    array1 = nullptr;
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

void printStruct(Man &m)
{
    cout << m.earsNumber << endl;
}

void printLesson94()
{
    Man m{2};
    Man *mPtr = &m;

    cout << m.earsNumber << endl;
    cout << (*mPtr).earsNumber << endl;
    cout << mPtr->earsNumber << endl;

    printStruct(m);
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

// void pointers can point to any types, but pointer arithmetic does not work with them since 
// pointer has to know exact data length in order to perform correct increment/decrement;
// they also have to be casted to corresponding type before usage
void printLesson96()
{
    int a = 10;
    void *pointer = &a;

    cout << *(static_cast<int*>(pointer)) << endl;
}

void changeAB(int *&a, int **&b)
{
    *a = 10;
    **b = 20;
}

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
    return (row * numberOfColumnsInArray) + col;
}

void printLesson97()
{
    int val = 1;
    int *a = &val;
    int **b = &a;

    changeAB(a, b);

    cout << val << endl;

    // int arr1[]{ 1, 2 }; // regular fixed-sized array

    int *arr2 = new int[20]; // non-fixed-sized array
    delete[] arr2;
    arr2 = nullptr;

    int **arr3 = new int*[20]; // dynamic array of pointers
    delete[] arr3;
    arr3 = nullptr;

    int arr4[25]{};

    int middleIndex = getSingleIndex(4, 3, 5);

    for (int i = 0; i < 25; i++)
    {
        if (i == middleIndex)
            cout << 1;
        else
            cout << arr4[i];

        if ((i + 1) % 5 != 0)
            cout << " ";
        else
            cout << endl;
    }
}

void printLesson98()
{
    array<int, 4>arr{ 100, 2, 3, 45};

    std::sort(arr.begin(), arr.end());

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
}

void printLesson99()
{
    vector<int> v{ 2, 3, 4 };
    cout << v.at(2) << endl;

    v.resize(5);
    cout << v.size() << endl;
    v.resize(1);
    cout << v.size() << endl;
}

bool containsNut(std::string_view str)
{
    return str.find("nut") != std::string_view::npos;
}

void printLesson101()
{
    array<int, 6> arr{ 1, 2, 3, 4, 5, 6};
    int search{};
    int replace{};

    cin >> search >> replace;

    auto found{ std::find(arr.begin(), arr.end(), search) };

    cout << typeid(found).name() << endl;
    cout << *found << endl;
    cout << replace << endl;

    std::array<std::string_view, 4> arr2{ "apple", "banana", "wall", "lemonuts" };

    auto found2 = std::find_if(arr2.begin(), arr2.end(), containsNut);

    if (found2 == arr2.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found2 << '\n';

    auto totalNuts = std::count_if(arr2.begin(), arr2.end(), containsNut);
    cout << "Total nuts: " << totalNuts << endl;
}

enum Item
{
    HP,
    TORCH,
    ARROW,
    MAX_ITEMS
};

int countTotalItems(int *arr)
{
    int totalItems = 0;

    for (int i = 0; i < Item::MAX_ITEMS; ++i)
    {
        totalItems += arr[i];
    }
    
    return totalItems;
}

void printTest1()
{
    int bag[Item::MAX_ITEMS]{ 3, 6, 12};
    int totalItems = countTotalItems(bag);

    cout << totalItems << endl;
}

struct Pupil
{
    string name{""};
    int mark{0};
};

Pupil enterPupil()
{
    Pupil p{};

    while (true)
    {
        cout << "Enter name: " << endl;
        cin >> p.name;
        cout << "Enter mark: " << endl;
        cin >> p.mark;

        if (cin.fail() || p.mark < 0 || p.mark > 100)
        {
            cout << "Wrong mark. Mark has to be from 0 to 100" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            return p;
        }
    }
}

bool sortPupils(Pupil a, Pupil b)
{
    return a.mark > b.mark;
}

void printTest2()
{
    int numberOfPupils;
    cout << "Enter number of pupils you want to enter: " << endl;
    cin >> numberOfPupils;

    Pupil *p = new (std::nothrow) Pupil[numberOfPupils];

    for (int i = 0; i < numberOfPupils; i++)
    {
        p[i] = enterPupil();
    }

    std::sort(p, p + numberOfPupils, sortPupils);

    for (int i = 0; i < numberOfPupils; i++)
    {
        cout << "Name: " << p[i].name
            << ", mark: " << p[i].mark << endl;
    }
    
    delete[] p;
    p = nullptr;
}

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void printTest3()
{
    int a{5};
    int b{10};

    swap(a, b);

    cout << "a: " << a << ", b: " <<  b << endl;
}

void printCStyleString(const char *c)
{
    while (*c != '\0')
    {
        cout << *c << endl;
        ++c;
    }
}

void printTest4()
{
    printCStyleString("Hello, world!");
}

enum class CardSuit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    NUM_OF_SUITS
};

enum class CardRank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    NUM_OF_RANKS
};

struct Card
{
    CardSuit suit;
    CardRank rank;
};

void printCard(const Card &card)
{
    switch (card.rank)
    {
        case CardRank::TWO: cout << "2"; break;
        case CardRank::THREE: cout << "3"; break;
        case CardRank::FOUR: cout << "4"; break;
        case CardRank::FIVE: cout << "5"; break;
        case CardRank::SIX: cout << "6"; break;
        case CardRank::SEVEN: cout << "7"; break;
        case CardRank::EIGHT: cout << "8"; break;
        case CardRank::NINE: cout << "9"; break;
        case CardRank::TEN: cout << "10"; break;
        case CardRank::JACK: cout << "J"; break;
        case CardRank::QUEEN: cout << "Q"; break;
        case CardRank::KING: cout << "K"; break;
        case CardRank::ACE: cout << "A"; break;
        default: break;
    }

    switch (card.suit)
    {
        case CardSuit::CLUBS: cout << "C"; break;
        case CardSuit::DIAMONDS: cout << "D"; break;
        case CardSuit::HEARTS: cout << "H"; break;
        case CardSuit::SPADES: cout << "S"; break;
        default: break;
    }

    cout << " ";
}

std::array<Card, 52> initDeck()
{
    std::array<Card, 52> deck{};
    size_t kk = 0;

    for (int ii = 0; ii < int(CardSuit::NUM_OF_SUITS); ++ii)
    {
        for (int jj = 0; jj < int(CardRank::NUM_OF_RANKS); ++jj)
        {
            deck[kk] = Card {static_cast<CardSuit>(ii), static_cast<CardRank>(jj)};
            ++kk;
        }   
    }
    
    return deck;
}

void printDeck(const std::array<Card, 52> &deck)
{
    for (Card card: deck)
    {
        printCard(card);
    }
    cout << endl;
}

void swapCards(Card &c1, Card &c2)
{
    Card tmpCard = c1;
    c1 = c2;
    c2 = tmpCard;
}

int getRandomI(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 

    return static_cast<size_t>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
    for (size_t i = 0; i < deck.size(); i++)
    {
        swapCards(deck[i], deck[(unsigned int) getRandomI(0, 51)]);
    }
}

int getCardValue(const Card &card)
{
    if (card.rank < CardRank::JACK)
        return ((int)card.rank) + 2;
    else if (card.rank == CardRank::ACE) 
        return 11;
    else 
        return 10;
}

void printTest6()
{
    Card c1{ CardSuit::DIAMONDS, CardRank::KING };
    Card c2{ CardSuit::SPADES, CardRank::ACE };
    Card c3{ CardSuit::SPADES, CardRank::FIVE };
    swapCards(c1, c2);

    cout << (int) c1.rank << " - " << (int) c2.rank << endl;

    std::array<Card, 52> deck = initDeck();

    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);

    cout << "Card value: " << getCardValue(c1) << endl;
    cout << "Card value: " << getCardValue(c2) << endl;
    cout << "Card value: " << getCardValue(c3) << endl;
}

bool wantsToDrawCard()
{
    char answer{};
    int attempts = 1;

    cout << "Do you want to take another card? y/n (n)";
    while (attempts <= 5)
    {
        cin >> answer;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (cin.fail() || (answer != 'y' && answer != 'n'))
        {
            cout << "Answer must be 'y' or 'n'! " << 5 - attempts << " attempts left. Default is n" << endl;
            ++attempts;
            continue;
        }
        
        return answer == 'y';
    }

    return false;
}

void printCurrentCardsValue(const int value)
{
    cout << "Current cards value: " << value << endl;
}

/**
 * card points to card deck array
*/
Card const * drawCard(Card const *&card)
{
    ++card;
    cout << "You drew ";
    printCard(*card);
    cout << endl;

    return card;
}

int startDrawingSequence(string playerName, Card const *&currCard)
{
    int playerResult{};

    playerResult += getCardValue(*currCard);
    playerResult += getCardValue(*drawCard(currCard));
    printCurrentCardsValue(playerResult);

    while (wantsToDrawCard())
    {
        playerResult += getCardValue(*drawCard(currCard));
        
        if (playerResult == 21)
        {
            cout << "Player " << playerName << " has 21! Congratulations!" << endl;
            return 21;
        }
        else if (playerResult > 21)
        {
            cout << "Player " << playerName << " lost with result " << playerResult << " :(" << endl;
            return 0;
        }

        printCurrentCardsValue(playerResult);
    }

    return playerResult;
}

bool playBlackJack(const std::array<Card, 52> &deck)
{
    int clientResult{};
    int dealerResult{};

    Card const *currCard = &deck[0];

    cout << "Client's turn!" << endl;
    clientResult = startDrawingSequence("Client", currCard);

    cout << "Dealer's turn!" << endl;
    ++currCard;
    dealerResult = startDrawingSequence("Dealer", currCard);
    
    if (clientResult > dealerResult)
    {
        cout << "Client won!" << endl;
    }
    else if (clientResult < dealerResult)
    {
        cout << "Client lost." << endl;
    }
    else 
    {
        cout << "Tie." << endl;
    }

    return false;
}

void printTest7()
{
    srand(static_cast<unsigned int>(time(0)));
    getRandomI(0, 51);
    std::array<Card, 52> deck = initDeck();
    
    shuffleDeck(deck);
    printDeck(deck);
    playBlackJack(deck);
}

void printTests()
{
    // printTest1();
    // printTest2();
    // printTest3();
    // printTest4();
    // printTest6();
    printTest7();
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
    // printLesson95(); // foreach
    // printLesson96(); // void pointers
    // printLesson97(); // pointers to pointers
    // printLesson98(); // std::array
    // printLesson99(); // std::vector
    // printLesson101(); // algorithm
    printTests();
}