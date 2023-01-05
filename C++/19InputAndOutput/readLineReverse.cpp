#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string filename = "/home/cedar/dynamic_measure_file";
    ifstream fin;
    fin.open(filename);

    fin.seekg(-1, ios_base::end); // go to one spot before the EOF

    //试图记录每行的行尾，先移动到文件末尾
    auto lineHead = fin.tellg()+1;
    int i{1};
    while (fin.tellg() > 0)
    {
//        cout << "====" << fin.tellg() << "====" << endl;
        bool keepLooping = true;

        while (keepLooping) //一行
        {
            char ch;
            fin.get(ch); // Get current byte's data
            if(ch=='\n')
            {
                fin.seekg(-2, ios_base::cur); 
            }

            //当前读的字符位置
            lineHead = fin.tellg()-1;

            if ((int)fin.tellg() <= 1)
            {                        // If the data was at or before the 0th byte
                fin.seekg(0);        // The first line is the last line
                keepLooping = false; // So stop there
            }
            else if (ch == '\n')
            {                        // If the data was a newline
                keepLooping = false; // Stop at the current position.

                break;
            }
            else
            {                                 // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2, ios_base::cur); // Move to the front of that data, then to the front of the data before it
            }
        }
        string lastLine;

        getline(fin, lastLine);                 // Read the current line

        cout << "Result"<<i++<<": " << lastLine << '\n'; // Display it

        if(!fin.good()){
            fin.clear();
        }
        //一行执行完毕，移动文件指针到上一行最后一个字符
        fin.seekg(lineHead-1);
    }
    fin.close();
    return 0;
}