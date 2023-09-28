#include <iostream>
#include <unordered_map>
#include <vector>

int Partition(std::string& x, int left, int right)
{
    char key=x[right];
    int j=left;
    for (int i=left; i<=right; i++)
    {
        if (x[i]<=key)
        {
            char tmp=x[j];
            x[j]=x[i];
            x[i]=tmp;
            j++;
        }
    }

    return j-1;
}

void QuickSort(std::string& box, int left, int right)
{
    if (left<right)
    {
        int mid=Partition(box,left,right);
        QuickSort(box,left,mid-1);
        QuickSort(box,mid+1,right);
    }
}


void group_anagrams(std::vector<std::string> box)
{
    std::unordered_map<std::string,std::vector<std::string>> result;
    for (auto x : box)
    {
        std::string tmp=x;
        QuickSort(tmp,0,tmp.length()-1);
        result[tmp].push_back(x);
    }

    for (auto x : result)
    {
        std::cout<<x.first<<" : ";
        for (auto i : x.second)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
}



int main()
{
    std::vector<std::string> box={"eat","tea","tan","ate","nat","bat"};

    group_anagrams(box);

    return 0;
}
