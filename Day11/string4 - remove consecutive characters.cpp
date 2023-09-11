#include <iostream>
#include <string>


std::string remove_consecutive_chars(std::string x)
{
    std::string result;
    int n=0;
    for (int i=1; i<x.length(); i++)
    {
        if (x[i-1]==x[i])
        {
            result+=x[i-1];
            i++;

        }
        else
        {
            result+=x[i-1];
        }
    }

    return result;
}


int main()
{
    std::string x="aaggrriimm  ppuurriiyyaa";

    std::string y=remove_consecutive_chars(x);

    std::cout<<y;

    return 0;
}
