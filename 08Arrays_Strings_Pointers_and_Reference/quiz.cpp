#include <algorithm> // std::shuffle
#include <array>
#include <ctime>
#include <iostream>
#include <numeric> // std::reduce
#include <random>
#include <vector>
#include <array>
int main1()
{
    std::array arr{1, 2, 3, 4};

    //std::cout << std::reduce(arr.begin(), arr.end()) << '\n'; // 10

    // If you can't use std::reduce, use std::accumulate. The 0 is the initial value
    // of the result: 0 + (((1 + 2) + 3) + 4)
    std::cout << std::accumulate(arr.begin(), arr.end(), 0) << '\n'; // 10

    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(arr.begin(), arr.end(), mt);

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}

enum class item
{
    healthPotions,
    torches,
    arrows,
    max_items
};

using inventory_type = std::array<int, static_cast<int>(item::max_items)>;

//int countTotalItems(const inventory_type& items)
int countTotalItems(const std::array<int, 3> &items)
{
    return std::accumulate(items.begin(), items.end(), 0);
}

int main2()
{
    inventory_type items{10, 5, 2};
    std::cout << "The player has " << countTotalItems(items) << " item(s) in total.\n";
    std::cout << "The player has " << items[static_cast<int>(item::torches)] << " torch(es)\n";
    ;
    return 0;
}

struct Student
{
    std::string firstName{};
    int grade{};
};
bool greater(const Student &s1, const Student &s2)
{
    return (s1.grade > s2.grade);
}

void swap(int &n1, int &n2)
{
    auto temp{n1};
    n1 = n2;
    n2 = temp;
}
int main3()
{
    int numStudent{};
    std::cout << "Enter a number of student";
    std::cin >> numStudent;
    std::vector<Student> students(static_cast<std::vector<Student>::size_type>(numStudent));
    for (Student &student : students)
    {
        std::string firstName{};
        std::cin >> firstName;
        student.firstName = firstName;
        int grade{};
        std::cin >> grade;
        student.grade = grade;
    }
    std::sort(students.begin(), students.end(), greater);
    for (const Student &student : students)
    {
        std::cout << student.firstName << " got a grade of " << student.grade << '\n';
    }
    return 0;
}

void printChatacter(const char *ptr)
{
    while (*ptr != '\0')
    {
        std::cout << *ptr;
        ++ptr;
    }
}

int main4()
{
    int a{1};
    int b{3};
    swap(a, b);
    std::cout << a << b << '\n';
    printChatacter("Hello, world!");
    return 0;
}

int main5()
{
    int array[]{0, 1, 2, 3};

    for (std::size_t count{0}; count < std::size(array); ++count)
    {
        std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}

enum class CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,

    MAX_SUITS
};

enum class CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANKS
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

void printCard(const Card &card)
{
    switch (card.rank)
    {
    case CardRank::RANK_2:
        std::cout << '2';
        break;
    case CardRank::RANK_3:
        std::cout << '3';
        break;
    case CardRank::RANK_4:
        std::cout << '4';
        break;
    case CardRank::RANK_5:
        std::cout << '5';
        break;
    case CardRank::RANK_6:
        std::cout << '6';
        break;
    case CardRank::RANK_7:
        std::cout << '7';
        break;
    case CardRank::RANK_8:
        std::cout << '8';
        break;
    case CardRank::RANK_9:
        std::cout << '9';
        break;
    case CardRank::RANK_10:
        std::cout << 'T';
        break;
    case CardRank::RANK_JACK:
        std::cout << 'J';
        break;
    case CardRank::RANK_QUEEN:
        std::cout << 'Q';
        break;
    case CardRank::RANK_KING:
        std::cout << 'K';
        break;
    case CardRank::RANK_ACE:
        std::cout << 'A';
        break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
    case CardSuit::SUIT_CLUB:
        std::cout << 'C';
        break;
    case CardSuit::SUIT_DIAMOND:
        std::cout << 'D';
        break;
    case CardSuit::SUIT_HEART:
        std::cout << 'H';
        break;
    case CardSuit::SUIT_SPADE:
        std::cout << 'S';
        break;
    default:
        std::cout << '?';
        break;
    }
}

std::array<Card, 52> createDeck()
{
    std::array<Card, 52> deck{};
    auto suits{static_cast<int>(CardSuit::MAX_SUITS)};
    auto ranks{static_cast<int>(CardRank::MAX_RANKS)};
    std::array<Card, 52>::size_type card{0};
    for (int suit{0}; suit < suits; ++suit)
    {
        for (int rank{0}; rank < ranks; ++rank)
        {
            deck[card] = {static_cast<CardRank>(rank), static_cast<CardSuit>(suit)};
            // deck[card].suit = static_cast<CardSuit>(suit);
            // deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }
    return deck;
}
void printDeck(std::array<Card, 52> &deck)
{
    auto suits{static_cast<int>(CardSuit::MAX_SUITS)};
    auto ranks{static_cast<int>(CardRank::MAX_RANKS)};
    std::array<Card, 52>::size_type card{0};
    for (int suit{0}; suit < suits; ++suit)
    {
        for (int rank{0}; rank < ranks; ++rank)
        {
            printCard(deck[card]);
            std::cout << "\t";
            ++card;
        }
        std::cout << '\n';
    }
}
void shuffleDeck(std::array<Card, 52> &deck)
{
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}
int getCardValue(Card card)
{
    if(card.rank<=CardRank::RANK_10)
    {
        return (static_cast<int>(card.rank)+2);
    }
    switch (card.rank)
    {
    case CardRank::RANK_JACK:
    case CardRank::RANK_QUEEN:
    case CardRank::RANK_KING:
        return 10;
    case CardRank::RANK_ACE:
        return 11;
    default:
        return 0;
    }
}
int main()
{
    //Card card{CardRank::RANK_2, CardSuit::SUIT_CLUB};
    auto deck{createDeck()};
    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);
    return 0;
}
