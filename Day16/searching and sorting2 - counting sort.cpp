#include <iostream>
#include <cmath>


int digit(int num, int n)
{
    int div=num/pow(10,n-1);
    return div%10;
}

template <typename TYPE>
void print_array(TYPE box, int length)      //Print 1D array given array and length. Except string array
{
    std::cout<<"{";
    for (int n=0; n<length; n++)
    {
        std::cout<<box[n];
        if (n<length-1)
        {
            std::cout<<",";
        }
    }

    std::cout<<"}\n";

}

void counting_sort(int box[], int length, int d)
{
    int tmp[10]={0};
    int box2[length];

    for (int i=0; i<length; i++)
    {
        tmp[digit(box[i],d)]++;
    }

    //print_array(tmp,10);

    for (int i=1; i<10; i++)
    {
        tmp[i]=tmp[i-1]+tmp[i];
    }

    //print_array(tmp,10);

    for (int i=length-1; i>=0; i--)
    {
        box2[--tmp[digit(box[i],d)]]=box[i];
    }

    //print_array(box2,length);

    for (int i=0; i<length; i++)
    {
        box[i]=box2[i];
    }
}


int main()
{
    int box[]={9,8,7,7,6,5,4,3,3,3,1,1,2};
    int box_length=sizeof(box)/sizeof(int);

    print_array(box,box_length);
    counting_sort(box,box_length,1);
    print_array(box,box_length);
    return 0;
}
