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

int* product_except_self(int box[], int length)
{
    int* result=new int[length];
    result[0]=1;
    for (int i=1; i<length; i++)
    {
        result[i]=result[i-1]*box[i-1];
    }
    int tmp=1;
    for (int i=length-1; i>=0; i--)
    {
        result[i]*=tmp;
        tmp*=box[i];
    }

    return result;
}

int main()
{
    int box[]={1,2,3,4};
    int box_length=sizeof(box)/sizeof(int);

    int box2[]={-1,1,0,-3,3};
    int box2_length=sizeof(box2)/sizeof(int);

    int* result=product_except_self(box2,box2_length);

    print_array(box2,box2_length);
    print_array(result,box2_length);


    return 0;
}
