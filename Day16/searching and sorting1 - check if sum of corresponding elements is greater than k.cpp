#include <iostream>


bool corresponding(int box1[], int box2[], int length, int k)
{
    for (int i=0; i<length; i++)
    {
        if (box1[i]+box2[i]>=k)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int box1[]={1,1,1,1,1,1,1};
    int box2[]={2,2,2,2,2,2,2};
    int length=sizeof(box1)/sizeof(int);

    int check=3;

    if (corresponding(box1,box2,length,check))
    {
        std::cout<<std::endl<<"yes";
    }
    else
    {
        std::cout<<std::endl<<"no";
    }

    return 0;
}
