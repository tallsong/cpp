#include <algorithm> // std::equal
#include <cctype>    // std::isdigit, std::isspace, std::isalpha
#include <iostream>
#include <map>
#include <string>
#include <string_view>

bool inputMatches(std::string_view input, std::string_view pattern)
{
    if (input.length() != pattern.length())
    {
        return false;
    }

    // We have to use a C-style function pointer, because std::isdigit and friends
    // have overloads and would be ambiguous otherwise.
    static const std::map<char, int (*)(int)> validators{
        {'#', &std::isdigit},
        {'_', &std::isspace},
        {'@', &std::isalpha},
        {'?', [](int) { return 1; }}};

    // Before C++20, use
    // return std::equal(input.begin(), input.end(), pattern.begin(), [](char ch, char mask) -> bool {
    // ...

    return std::ranges::equal(input, pattern, [](char ch, char mask) -> bool {
        if (auto found{validators.find(mask)}; found != validators.end())
        {
            // The pattern's current element was found in the validators. Call the
            // corresponding function.
            return (*found->second)(ch);
        }
        else
        {
            // The pattern's current element was not found in the validators. The
            // characters have to be an exact match.
            return (ch == mask);
        }
    });
    
}

int main()
{
    std::string phoneNumber{};

    do
    {
        std::cout << "Enter a phone number (###) ###-####: ";
        std::getline(std::cin, phoneNumber);
    } while (!inputMatches(phoneNumber, "(###) ###-####"));

    std::cout << "You entered: " << phoneNumber << '\n';
}