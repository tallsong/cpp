#include <algorithm> // std::generate, std::find, std::min_element
#include <cmath>     // std::abs
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using list_type = std::vector<int>;

namespace config
{
    constexpr int multiplierMin{2};
    constexpr int multiplierMax{4};
    constexpr int maximumWrongAnswer{4};
} // namespace config

int getRandomInt(int min, int max)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    return std::uniform_int_distribution{min, max}(mt);
}

// Generates @count numbers starting at @start*@start and multiplies
// every square number by multiplier.
list_type generateNumbers(int start, int count, int multiplier)
{
    list_type numbers(static_cast<list_type::size_type>(count));

    int i{start};

    for (auto &number : numbers)
    {
        number = ((i * i) * multiplier);
        ++i;
    }

    return numbers;
}

// Asks the user to input start and amount, then calls @generateNumbers.
list_type generateUserNumbers(int multiplier)
{
    int start{};
    int count{};

    std::cout << "Start where? ";
    std::cin >> start;

    std::cout << "How many? ";
    std::cin >> count;

    // Input validation omitted. All functions assume valid input.

    return generateNumbers(start, count, multiplier);
}

int getUserGuess()
{
    int guess{};

    std::cout << "> ";
    std::cin >> guess;

    return guess;
}

// Searches for the value @guess in @numbers and removes it.
// Returns true if the value was found. False otherwise.
bool findAndRemove(list_type &numbers, int guess)
{
    if (auto found{std::find(numbers.begin(), numbers.end(), guess)};
        found == numbers.end())
    {
        return false;
    }
    else
    {
        numbers.erase(found);
        return true;
    }
}

// Finds the value in @numbers that is closest to @guess.
int findClosestNumber(const list_type &numbers, int guess)
{
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) {
        return (std::abs(a - guess) < std::abs(b - guess));
    });
}

void printTask(list_type::size_type count, int multiplier)
{
    std::cout << "I generated " << count
              << " square numbers. Do you know what each number is after multiplying it by "
              << multiplier << "?\n";
}

// Called when the user guesses a number correctly.
void printSuccess(list_type::size_type numbersLeft)
{
    std::cout << "Nice! ";

    if (numbersLeft == 0)
    {
        std::cout << "You found all numbers, good job!\n";
    }
    else
    {
        std::cout << numbersLeft << " number(s) left.\n";
    }
}

// Called when the user guesses a number that is not in the numbers.
void printFailure(const list_type &numbers, int guess)
{
    int closest{findClosestNumber(numbers, guess)};

    std::cout << guess << " is wrong!";

    if (std::abs(closest - guess) <= config::maximumWrongAnswer)
    {
        std::cout << " Try " << closest << " next time.\n";
    }
    else
    {
        std::cout << '\n';
    }
}

// Returns false if the game is over. True otherwise.
bool playRound(list_type &numbers)
{
    int guess{getUserGuess()};

    if (findAndRemove(numbers, guess))
    {
        printSuccess(numbers.size());

        return !numbers.empty();
    }
    else
    {
        printFailure(numbers, guess);
        return false;
    }
}

int main()
{
    int multiplier{getRandomInt(config::multiplierMin, config::multiplierMax)};
    list_type numbers{generateUserNumbers(multiplier)};

    printTask(numbers.size(), multiplier);

    while (playRound(numbers))
        ;

    return 0;
}

double max(const double a, const double b);

void swap(int &x, int &y);
int &getLargestElement(const int length, int *array);