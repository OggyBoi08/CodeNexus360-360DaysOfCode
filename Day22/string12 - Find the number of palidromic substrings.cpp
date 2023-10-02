#include <iostream>
#include <string>

bool is_palindrome(std::string str, int start, int finish)
{
    int len=finish-start+1;
    for (int i=0; i<len/2; i++)
    {
        if (str[start+i]!=str[finish-i])
        {
            return false;
        }
    }
    return true;
}

int number_of_palindromic_substrings(std::string str)
{
    int result=0;
    for (int i=0; i<str.length(); i++)
    {
        for (int j=i; j<str.length(); j++)
        {
            if (is_palindrome(str,i,j))
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    std::string x="Agrim Puriya";
    std::string y="abaab";
    std::cout<<x<<" "<<number_of_palindromic_substrings(x);
    std::cout<<std::endl<<y<<" "<<number_of_palindromic_substrings(y);

    return 0;
}
