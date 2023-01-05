#include "io.h"
int main()
{
    int x{readNumber()};
    int y{readNumber()};
    writeAnswer(x+y);
    return 0;
}