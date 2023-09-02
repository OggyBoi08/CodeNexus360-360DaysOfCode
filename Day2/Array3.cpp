#include <iostream>


int max_subarrays(int box[], int length)      //Brute force
{
    int cur_sum;
    int result=INT_MIN;
    for (int i=0; i<length; i++)
    {
        for (int j=i; j<length; j++)
        {
            cur_sum=0;
            for (int k=i; k<j; k++)
            {
                cur_sum+=box[k];
            }
            if (cur_sum>result)
            {
                result=cur_sum;
            }
        }
    }

    return result;
}

int max_subarrays2(int box[], int length)      //optimized Brute force
{
    int cur_sum;
    int result=INT_MIN;
    for (int i=0; i<length; i++)
    {
        cur_sum=0;
        for (int j=i; j<length; j++)
        {
            cur_sum+=box[j];

            if (cur_sum>result)
            {
                result=cur_sum;
            }
        }
    }

    return result;
}

int kadanes_algorithm(int box[], int length)
{
    int result=INT_MIN;
    int sum=0;
    for (int i=0; i<length; i++)
    {
        sum+=box[i];
        if (sum>result)
        {
            result=sum;
        }
        if (sum<0)
        {
            sum=0;
        }
    }

    return result;
}

int kadanes_algorithm2(int box[], int length)
{
    int result=INT_MIN;
    int sum=0;

    int start=-1;
    int ans_start=-1;
    int ans_finish=-1;
    for (int i=0; i<length; i++)
    {
        if (sum==0)
        {
            start=i;
        }
        sum+=box[i];
        if (sum>result)
        {
            result=sum;
            ans_start=start, ans_finish=i;
        }
        if (sum<0)
        {
            sum=0;
        }
    }


    std::cout<<std::endl<<"{";
    for (int i=ans_start; i<=ans_finish; i++)
    {
        std::cout<<box[i];
        if (i!=ans_finish)
        {
            std::cout<<",";
        }
    }
    std::cout<<"}"<<std::endl;

    return result;
}
int main()
{
    int num[]={-2,-3,4,-1,-2,1,5,-3};
    int num_length=sizeof(num)/sizeof(int);
    std::cout<<kadanes_algorithm2(num,num_length);
    return 0;
}
