#include <iostream>
#include <unordered_map>

int majority_element(int box[], int length)
{
    std::unordered_map<int,int> tmp;
    for (int i=0; i<length; i++)
    {
        tmp[box[i]]++;
    }

    for (auto i : tmp)
    {
        if (i.second>(length/2))
        {
            return i.first;
        }
    }

    return -1;
}


int main()
{
    int box[]={3,3,4,2,4,4,2,4,4};
    int box_length=sizeof(box)/sizeof(int);

    std::cout<<majority_element(box,box_length);

    return 0;
}
