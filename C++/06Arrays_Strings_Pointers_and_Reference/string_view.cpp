#include <iostream>
#include <string>
#include <string_view>
#include <cstring>
int remove()
{
    std::string_view str{"Peach"};

    std::cout << str << '\n';

    // Ignore the first characters.
    str.remove_prefix(1);

    std::cout << str << '\n';

    // Ignore the last 2 characters.
    str.remove_suffix(2);

    std::cout << str << '\n';

    return 0;
}

std::string_view askForName()
{
    std::cout << "What's your name?\n";

    // Use a std::string, because std::cin needs to modify it.
    std::string str{};
    std::cin >> str;

    // We're switching to std::string_view for demonstrative purposes only.
    // If you already have a std::string, there's no reason to switch to
    // a std::string_view.
    std::string_view view{str};

    std::cout << "Hello " << view << '\n';

    return view;
}
int main()
{
    std::string_view text{"hello"}; // view the text "hello", which is stored in the binary
    std::string_view str2{text};    // view of the same "hello"
    std::string_view more{str2};    // view of the same "hello"

    std::cout << text << ' ' << str2 << ' ' << more << '\n';

    std::string_view str{"Trains are fast!"};

    std::cout << str.length() << '\n'; // 16

    std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
    std::cout << (str == "Trains are fast!") << '\n';  // 1

    // Since C++20
    std::cout << str.starts_with("Boats") << '\n'; // 0
    std::cout << str.ends_with("fast!") << '\n';   // 1

    std::cout << str << '\n'; // Trains are fast!

    return 0;
}

void print(std::string s)
{
    std::cout << s << '\n';
}

int main2()
{
    std::string bal{"balloon"};
    std::string_view sv{bal};

    sv.remove_suffix(3);
    print(bal);
    // print(sv); // compile error: won't implicitly convert

    std::string str{sv}; // explicit conversion
        // Get the null-terminated C-style string.
    auto szNullTerminated{str.c_str()};  // expensive, so this should be avoided if possible.
    print(str); // okay
    
    print(static_cast<std::string>(sv)); // okay

    return 0;
}