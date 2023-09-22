#include <iostream>
#include <string>
#include <unordered_map>


void duplicates(std::string str)
{
    std::unordered_map<char,int> box;

    for (int i=0; i<str.length(); i++)
    {
        box[str[i]]++;
    }

    for (auto i : box)
    {
        if (i.second>1)
        {
            std::cout<<std::endl<<i.second<<" "<<i.first;
        }
    }
}

int main()
{
    duplicates("Agrim Puriya");

    return 0;
}
