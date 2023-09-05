#include <iostream>

struct result
{
    int repeated_element;
    int missing_element;
};


struct result return_missing_element(int box[], int length)
{
    for (int i=0; i<length; i++)
    {
        box[box[i]%length]=box[box[i]%length]+length;
    }

    struct result tmp;
    for (int i=0; i<length; i++)
    {
        if (box[i]>=length*2)
        {
            tmp.repeated_element=i;
        }
        if (box[i]<=length)
        {
            tmp.missing_element=i;
        }
    }

    return tmp;
};

int main()
{
    int box[]={3,1,2,5,3};
    int box_length=sizeof(box)/sizeof(int);

    struct result answer=return_missing_element(box,box_length);

    std::cout<<std::endl<<"Missing Element: "<<answer.missing_element;
    std::cout<<std::endl<<"Repeated Element: "<<answer.repeated_element;

    return 0;
}
