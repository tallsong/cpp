#include<iostream>

int printLetter()
{
    int letter{static_cast<int>('a')};

    while (letter!=static_cast<int>('z'))
    {
        std::cout<<static_cast<char>(letter);
        ++letter;
    }
    std::cout<<'z';
    

    return 0;
}

int mprintLetterain2()
{
    char mychar{ 'a' };
    while (mychar <= 'z')
    {
        //std::cout << mychar  << ' ' << static_cast<int>(mychar) << '\n';
        std::cout << mychar  << ' ' << '\t';
        ++mychar;
    }
 
    return 0;
}

int main2()
{
    int outer{5};
    while (outer>0)
    {
        int inner{outer};
        while (inner>0)
        {
            // std::cout<<inner<<'\t';
            // --inner;
            std::cout << inner-- << ' ';
        }
        
        std::cout<<'\n';
        --outer;
    }
    
    return 0;
}
int main()
{
    int outer{1};
    while (outer<=5)
    {
        int inner{5};
        
        while (inner>0)
        {   
            
            if(inner>outer)
                std::cout<<"  ";
            else
            {
                std::cout<<inner<<' ';
            }
            --inner;
        }
        ++outer;
        std::cout<<'\n';
        
    }
    
    return 0;
}