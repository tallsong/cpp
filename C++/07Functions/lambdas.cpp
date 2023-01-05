#include <iostream>
#include <array>
#include <algorithm>
#include <string_view>
#include <functional>

int main1()
{
    constexpr std::array<std::string_view, 4> array{"apple", "naut", "banana", "lemon"};
    const auto find{std::find_if(array.begin(), array.end(),
                                 [](std::string_view str) -> bool {
                                     return (str.find("aut") != std::string_view::npos);
                                 })};
    if (find != array.end())
    {
        std::cout << *find;
    }
    else
    {
        std::cout << "not found!";
    }

    return 0;
}

int main2()
{
    // A regular function pointer. Only works with an empty capture clause.
    double (*addNumbers1)(double, double){
        [](double a, double b) {
            return (a + b);
        }};

    addNumbers1(1, 2);

    // Using std::function. The lambda could have a non-empty capture clause (Next lesson).
    std::function addNumbers2{// note: pre-C++17, use std::function<double(double, double)> instead
                              [](double a, double b) {
                                  return (a + b);
                              }};

    addNumbers2(3, 4);

    // Using auto. Stores the lambda with its real type.
    auto addNumbers3{
        [](double a, double b) {
            return (a + b);
        }};

    addNumbers3(5, 6);

    return 0;
}

int main3()
{
    constexpr std::array months{
        // pre-C++17 use std::array<const char*, 12>
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };
    const auto sameLetter{std::adjacent_find(months.begin(), months.end(), [](const auto &mon1, const auto &mon2) {
        return (mon1[0] == mon2[0]);
    })};
    if (sameLetter != months.end())
    {
        std::cout << *sameLetter << " and " << *std::next(sameLetter) << " has same letter";
    }
    return 0;
}

struct Student
{
    std::string name{};
    int points{};
};

int main4()
{
    std::array<Student, 8> arr{
        {{"Albert", 3},
         {"Ben", 5},
         {"Christine", 2},
         {"Dan", 8}, // Dan has the most points (8).
         {"Enchilada", 4},
         {"Francis", 1},
         {"Greg", 3},
         {"Hagrid", 5}}};

    const Student *student{
        std::max_element(arr.begin(), arr.end(), [](const auto &stu1, const auto &stu2) {
            return (stu1.points < stu2.points);
        })};
    const auto best{
        std::max_element(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
            return (a.points < b.points);
        })};
    std::cout << best->name << "is best student";
    return 0;
}

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main5()
{
    std::array<Season, 4> seasons{
        {{"Spring", 285.0},
         {"Summer", 296.0},
         {"Fall", 288.0},
         {"Winter", 263.0}}};

    /*
   * Use std::sort here
   */
    std::sort(seasons.begin(), seasons.end(), [](const auto &s1, const auto &s2) {
        return (s1.averageTemperature < s2.averageTemperature);
    });

    for (const auto &season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}

int main6()
{
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    // Ask the user what to search for.
    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    auto found{std::find_if(arr.begin(), arr.end(), [search](std::string_view str) mutable {
        return (str.find(search) != std::string_view::npos);
    })};

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}

void invoke(const std::function<void(void)> &fn)
{
    
    std::cerr << "*****************";
    fn();
    std::cerr << &fn<<'\n';
}

int main7()
{
    int i{0};
    auto count{[i]() mutable {
        
        std::cout << ++i << '\n';
    }};
    

    invoke((count));
    invoke((count));
    invoke((count));



    auto *p = &count;
    std::cerr << "count \n";
    std::cerr << p;

    return 0;
}

int main()
{
    int i{0};

    // Increments and prints its local copy of @i.
    auto count{[i]() mutable {
        std::cout << ++i << '\n';
    }};

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    invoke(std::ref(count));
    invoke(std::ref(count));
    invoke(std::ref(count));

    return 0;
}
