#include <iostream>
#include "constants.h"

double getHeight()
{
    std::cout<<"Enter the height of the tower in meters: ";
    double height{};
    std::cin>>height;
    return height;
}

void printHeight(double height)
{
    int second{0};
    while (height>0)
    {
        height=height-0.5*constants::my_gravity*second*second;
        if(height<0)
            std::cout<<"At "<<second<<" seconds, the ball is on the ground."<<'\n';
        else
            std::cout<<"At "<<second<<" seconds, the ball is at height: "<<height<<" meters"<<'\n';
        second++;
    }
    
}


int main()
{
    double height{getHeight()};
    printHeight(height);
    return 0;
}