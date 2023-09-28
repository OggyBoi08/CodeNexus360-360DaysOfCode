#include <iostream>
#include <string>
#include <unordered_map>


int largest_reapeating_character_replacement(std::string str, int k)
{
    std::unordered_map<char,int> chars;
    int result=0;

    for (int i=str.length()-1; i>=0; i--)
    {
        chars[str[i]]=i;
    }
    for (auto a : chars)
    {
        int cnt=0;
        int i=a.second;
        int j=0;
        while (i<str.length() && j<k)
        {
            if (str[i]!=a.first)
            {
                j++;
            }
            i++;
            cnt++;
        }
        if (cnt>result)
        {
            result=cnt;
        }
    }

    return result;
}


int main()
{
    std::string string1="AABABBA";
    std::string string2="ABAB";
    std::string string3="Agrim Puriya";

    int k=2;

    int result=largest_reapeating_character_replacement(string2,k);
    std::cout<<string2<<std::endl;
    std::cout<<result;

    return 0;
}
