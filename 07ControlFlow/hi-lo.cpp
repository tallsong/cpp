#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime>   // for std::time()
#include <random>  // for std::mt19937

int getRandomNumber()
{
    std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    const int minNumber{1};
    const int maxNumber{100};
    std::uniform_int_distribution die{minNumber, maxNumber};
    return die(mersenne);
}
int getInput()
{
    int inputNumber{};
    while (true)
    {
        std::cin >> inputNumber;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "error,input again:";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return inputNumber;
        }
    }
}

bool isWinGame()
{
    const int randomNumber{getRandomNumber()};
    std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";
    for (int counter = 0; counter < 7; ++counter)
    {
        std::cout << "Guess #" << counter + 1 << ": ";
        int inputNumber{getInput()};
        if (inputNumber < randomNumber)
        {
            std::cout << "Your guess is too low.\n";
        }
        else
        {
            if (inputNumber > randomNumber)
            {
                std::cout << "Your guess is too high.\n";
            }
            else
            {
                std::cout << "Correct! You win!\n";
                return true;
            }
        }
    }
    std::cout << "Sorry, you lose.  The correct number was " << randomNumber << ".";
    return false;
}

int main()
{
    isWinGame();
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        char answer{};
        std::cin >> answer;
        if (answer == 'y')
            isWinGame();
        else
        {
            if (answer == 'n')
            {
                break;
            }
        }

    } while (true);
    std::cout << "Thank you for playing.";

    return 0;
}