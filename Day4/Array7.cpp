#include <iostream>

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


void swapper(int* x, int* y)
{
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

void reverse_array(int box[], int start, int finish)
{
    int i=start;
    int j=finish;
    while (i<j)
    {
        swapper(&box[i],&box[j]);
        i++;
        j--;
    }
}


void permutation(int box[], int length)
{
    int break_point=-1;
    int right_peak=-1;

    for (int i=length-2; i>=0; i--)
    {
        if (box[i]<box[i+1])
        {
            break_point=i;
            break;
        }
    }


    if (break_point==-1)
    {
        reverse_array(box,0,length-1);
    }
    else
    {
        for (int i=length-1; i>=0; i--)
        {
            if (box[i]>box[break_point])
            {
                right_peak=i;
                break;
            }
        }
    }

    swapper(&box[right_peak],&box[break_point]);
    reverse_array(box,break_point+1,length-1);

    //std::cout<<break_point;


    //return result;
}


int main()
{
    int box[]={1,2,3,4,5,6,7};
    int box_length=sizeof(box)/sizeof(int);

    print_array(box,box_length);
    permutation(box,box_length);
    print_array(box,box_length);



    return 0;
}
