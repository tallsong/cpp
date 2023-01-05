#include <iostream>
#include <vector>
#include<string>
#include<string_view>
int main2()
{
    constexpr int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    for (auto element : fibonacci)
    {
        std::cout << element << '\t';
    }
    std::string array[]{"peter", "likes", "frozen", "yogurt"};
    for (const auto &element : array) // read only
    {
        std::cout << element << ' ';
    }
    std::vector fib{"dfs", "dfd", "sdfhsdkj", "我是一只猪"};
    for (const auto element : fib)
    {
        std::cout << element << '\t';
    }
    return 0;
}

int main()
{
   constexpr std::string_view names[8]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg","Holly"};
    while (true)
    {
        std::cout<<"Enter a name: ";
        std::string enterName{};
        std::cin>>enterName;
        bool isFound{false};
        for(auto name:names)
        {
            if(name==enterName)
            {
                std::cout<<enterName<<" was found.\n";
                isFound=true;
                break;
            }
            
        }
        if(!isFound)
            std::cout<<enterName<<" was not found.\n";

    }
    return 0;
    
    
}
