#include <iostream>


void print_common(int box1[], int length1, int box2[], int length2, int result[], int& result_length)
{
    int n=0;
    int m=0;
    while (n<length1 && m<length2)
    {
        if (box1[n]<box2[m])
        {
            n++;
        }
        else if (box2[m]<box1[n])
        {
            m++;
        }
        else
        {
            result[result_length]=box1[n];
            n++;
            m++;
            result_length++;
        }
    }
}

int main()
{
    int box1[]={1,2,3,4,5,6,7,8};
    int box1_length=sizeof(box1)/sizeof(int);
    int box2[]={1,1,1,2,3,4};
    int box2_length=sizeof(box2)/sizeof(int);
    int box3[]={2,3,4};
    int box3_length=sizeof(box3)/sizeof(int);

    int tmp1_length=std::min(box1_length,box2_length);
    int tmp1[tmp1_length];
    int result_length=0;

    print_common(box1,box1_length,box2,box2_length,tmp1,result_length);

    int ans[tmp1_length];
    int ans_length=0;

    print_common(tmp1,result_length,box3,box3_length,ans,ans_length);

    for (int i=0; i<ans_length; i++)
    {
        std::cout<<ans[i]<<" ";
    }

    return 0;
}
