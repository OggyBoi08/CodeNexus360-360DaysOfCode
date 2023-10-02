#include <iostream>
#include <string>


std::string range(std::string str, int start, int finish)
{
    std::string result="";
    for (int i=start; i<=finish; i++)
    {
        result+=str[i];
    }
    return result;
}

std::string longest_palindromic_substring(std::string str)
{
    std::string result="";
    int result_length=0;
    for (int i=0; i<str.length(); i++)
    {
        int l=i;
        int r=i;
        while (l>=0 and r<str.length() and str[l]==str[r])
        {
            if ((r-l+1)>result_length)
            {
                result=range(str,l,r);
                result_length=r-l+1;
            }
            l--;
            r++;
        }

        l=i;
        r=i+1;
        while (l>=0 and r<str.length() and str[l]==str[r])
        {
            if ((r-l+1)>result_length)
            {
                result=range(str,l,r);
                result_length=r-l+1;
            }
            l--;
            r++;
        }
    }

    return result;
}

int main()
{
    std::string x="Agrim Puriya";
    std::string y="Agrim mrowlatemymetalworm Puriya sussy wusssy";
    std::cout<<longest_palindromic_substring(y);

    return 0;
}
