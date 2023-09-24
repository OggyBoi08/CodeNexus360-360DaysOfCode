#include <iostream>
#include <cmath>

int search_step_array(int box[], int length, int x, int k)
{
    int i=0;
    while (i<length)
    {
        if (box[i]==x)
        {
            return i;
        }
        i=i+std::max(1,abs(box[i]-x)/k);
    }

    return -1;
}

int main()
{
    int box[]={4,5,6,7,6};
    int box_length=sizeof(box)/sizeof(int);
    int k=1;
    int x=5;

    std::cout<<search_step_array(box,box_length,x,k);

    return 0;
}
