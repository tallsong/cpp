#include <memory> // for std::unique_ptr
#include <iostream>
int main()
{ /*

    try
    {
        auto *john{new Person("John", 18, PERSON_MALE)};
        std::unique_ptr<Person> upJohn{john}; // upJohn now owns john

        ProcessPerson(john);

        // when upJohn goes out of scope, it will delete john
    }
    catch (const PersonException &exception)
    {
        std::cerr << "Failed to process person: " << exception.what() << '\n';
    }

*/
    return 0;
}
