#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;








int main()
{
    Solution s;
    vector<char> a{'1','d','f'};
    s.reverseString(a);
    for(char c:a)
    {
        std::cerr<<c;
    }
    return 0;
}