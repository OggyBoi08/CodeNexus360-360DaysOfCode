#include <iostream>

void print_array(int box[], int l, int r)
{
    std::cout<<"{";
    for (int i=l; i<=r; i++)
    {
        std::cout<<box[i];
        if (i!=r)
        {
            std::cout<<",";
        }
    }
    std::cout<<"}"<<std::endl;
}


int largest_subarray_sum_divisible_by_k(int box[], int length, int k)
{
    int sum;
    int max_length=0;
    for (int i=0; i<length; i++)
    {
        for (int j=i; j<length; j++)
        {
            sum=0;
            for (int z=i; z<=j; z++)
            {
                sum+=box[z];
            }
            if (sum%k==0 && (j-i+1)>max_length)
            {
                max_length=j-i+1;
            }
            //std::cout<<std::endl<<max_sum;
        }
    }

    return max_length;
}

int main()
{
    int box[]={2, 7, 6, 1, 4, 5};
    int box_length=sizeof(box)/sizeof(int);
    int box2[]={-2, 2, -5, 12, -11, -1, 7};
    int box2_length=sizeof(box2)/sizeof(int);
    std::cout<<largest_subarray_sum_divisible_by_k(box,box_length,3);

    return 0;
}
