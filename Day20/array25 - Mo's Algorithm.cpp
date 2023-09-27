#include <iostream>
#include <cmath>

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

typedef struct range
{
    int x;
    int y;
} RANGE;

void mo_algorithm(int box[], int length, RANGE queries[], int q_length)
{
    int len=ceil(sqrt(length));
    int len2=floor(sqrt(length));
    //std::cout<<std::endl<<len;
    int sums[len]={0};
    for (int i=0; i<length; i++)
    {
        sums[i/len2]+=box[i];
    }

    print_array(sums,len);

    for (int i=0; i<q_length; i++)
    {
        int l=queries[i].x;
        int r=queries[i].y;
        int result=0;
        for (int j=l; j<=r;)
        {
            if (j%len2==0 && j+len2-1<=r)
            {
                result+=sums[j/len2];
                j+=len2;
            }
            else
            {
                result+=box[j];
                j++;
            }
        }

        std::cout<<std::endl<<"SUM BETWEEN ("<<l<<","<<r<<") is : "<<result;
    }
}

int main()
{
    int box[]={9,5,3,7,1,2,4,8,6,5};
    int box_length=sizeof(box)/sizeof(int);

    RANGE queries[]={{0,3},{1,5},{4,9}};
    int q_length=sizeof(queries)/sizeof(RANGE);

    mo_algorithm(box,box_length,queries,q_length);

    return 0;
}
