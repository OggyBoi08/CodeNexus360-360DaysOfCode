#include <iostream>
#include <string>


bool is_palindrome(std::string str)
{
    std::string tmp="";
    for (char i : str)
    {
        if (isalpha(i))
        {
            tmp+=tolower(i);
        }
    }

    int len=tmp.length();
    for (int i=0; i<(len/2); i++)
    {
        //std::cout<<std::endl<<tmp[i]<<" "<<tmp[len-1-i];
        if (tmp[i]!=tmp[len-1-i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string x="Agrim Puriya";
    std::string y="Sit on a potato pan, Otis.";
    std::string z="Madam in Eden, I'm Adam.";

    std::cout<<std::endl<<is_palindrome(x);
    std::cout<<std::endl<<is_palindrome(y);
    std::cout<<std::endl<<is_palindrome(z);

    return 0;
}
