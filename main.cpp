#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>
 
namespace a::b::c
{
    inline constexpr std::string_view str{ "hello" };
}
 
template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
    return { sizeof...(T), (args + ...) };
}
 
int f(int n)
{
    if(n<=2)
        return n;
    return f(n-1)+f(n-2);
}
int main()
{
    auto [iNumbers, iSum]{ sum(1, 2, 3) };
    std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';
 
    std::array arr{ 1, 2, 3 };
 
    std::cout << std::size(arr) << '\n'<<f(55)<<'\n';
    
    return 0;
}
