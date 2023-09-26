#include <iostream>
#include <string>
#include <unordered_map>

int longest_substring_length(std::string str)
{
    int len=str.length();

    int max_len=0;
    std::unordered_map<char,int> tmp;
    int l=0;
    for (int r=0; r<len; r++)
    {
        if (tmp.count(str[r])==0 || tmp[str[r]]<l)
        {
            tmp[str[r]]=r;
            max_len=std::max(max_len,r-l+1);
        }
        else
        {
            l=tmp[str[r]]+1;
            tmp[str[r]]=r;
        }
    }

    return max_len;
}

int main()
{
    std::string x="abcabcabc";
    std::string y="bbbb";
    std::string z="pwwkew";
    std::string name="agrim puriya";

    std::cout<<std::endl<<longest_substring_length(x);
    std::cout<<std::endl<<longest_substring_length(y);
    std::cout<<std::endl<<longest_substring_length(z);
    std::cout<<std::endl<<longest_substring_length(name);

    return 0;
}
