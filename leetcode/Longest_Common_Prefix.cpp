#include<string>
#include<vector> 
#include<iostream>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size()==1)
            return strs.at(0);
        std::string result{strs.at(0)};
        for(size_t index{1};index<strs.size();++index)
        {
            if(!strs.at(index).size())
                return "";
            size_t min_size{min(result.size(),strs.at(index).size())};
            for(size_t  t{0};t<min_size;++t)
            {
                if(result.at(t)!=strs.at(index).at(t))
                {

                    result = result.substr(0,t);
                    break;
                }
            }
            result = result.substr(0,min_size);

            if(!result.size())
                return "";
            
        }
        
        return result; 
    }
};


int main()
{
    Solution s;
    vector<string>  arg{"dfds","df"};
    std::cerr<<s.longestCommonPrefix(arg);
    
    return 0;

}