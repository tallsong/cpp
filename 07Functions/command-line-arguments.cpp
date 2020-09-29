#include <iostream>
#include <sstream> // for std::stringstream
#include <string>
//  argc = argument count    argv = argument values    though the proper name is “argument vectors”
int main(int argc, char *argv[])
{
    std::cout << "argument count :" << argc << '\n';
    for (int count{0}; count < argc; ++count)
    {
        std::cout << count << " " << argv[count] << '\n';
    }

    if (argc <= 1)
    {
        // On some operating systems, argv[0] can end up as an empty string instead of the program's name.
        // We'll conditionalize our response on whether argv[0] is empty or not.
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';

        return 1;
    }

    std::stringstream convert{argv[1]}; // set up a stringstream variable named convert, initialized with the input from argv[1]

    int myint{};
    if (!(convert >> myint)) // do the conversion
        myint = 0;           // if conversion fails, set myint to a default value

    std::cout << "Got integer: " << myint << '\n';
    return 0;
}