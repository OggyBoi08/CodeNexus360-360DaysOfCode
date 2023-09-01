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

template <typename TYPE>
void reverse_array(TYPE box[], int box_lenght)
{
    for (int i=0; i<box_lenght/2; i++)
    {
        TYPE tmp=box[i];
        box[i]=box[box_lenght-1-i];
        box[box_lenght-1-i]=tmp;
    }
}


int main()
{
    char box[]={'O','g','g','y','B','o','i','0','8'};
    int box_length=sizeof(box)/sizeof(char);

    print_array(box,box_length);
    reverse_array(box,box_length);
    print_array(box,box_length);

    return 0;
}
