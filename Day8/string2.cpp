#include <iostream>
#include <string>

bool is_anagram(std::string s, std::string t)
{
    if (s.length()!=t.length())
    {
        return false;
    }
    bool is_present;
    for (char i : s)
    {
        is_present=false;
        for (char j : t)
        {
            if (i==j)
            {
                is_present=true;
            }
        }

        if (!is_present)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string x="agria";
    std::string y="migra";

    std::cout<<std::endl<<is_anagram(x,y);
    return 0;
}
