#include <iostream>

bool if_sum_k(int box[], int length, int k)
{
    for (int i=0; i<length; i++)
    {
        for (int j=0; j<length; j++)
        {
            if (box[i]!=box[j])
                {
                    if (box[i]+box[j]==k)
                    {
                        return true;
                    }
                }
        }
    }

    return false;
}

int main()
{
    int box[]={5,6,7,8,9,0,1,2,3,4};
    int box_length=sizeof(box)/sizeof(int);

    std::cout<<if_sum_k(box,box_length,35);

    return 0;
}
