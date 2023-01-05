#include <fstream>
#include <iostream>
 
int main()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.dat
    std::ofstream outf{ "Sample.dat" };
 
    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.dat could not be opened for writing!" << std::endl;
        return 1;
    }
 
    // We'll write two lines into this file
    outf << "This is line 1" << '\n';
    outf << "This is line 2" << '\n';
 
    return 0;
	
    // When outf goes out of scope, the ofstream
    // destructor will close the file
}