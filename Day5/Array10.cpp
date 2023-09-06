#include <iostream>

int kth_largest(int box[], int length, int k)
{
    int result[k];
    int top=0;
    int box2[length];
    for (int i=0; i<length; i++)
    {
        box2[i]=box[i];
    }

    int cur_max=INT_MIN;
    int cur_max_index;
    for (int i=0; i<k; i++)
    {
        cur_max=INT_MIN;
        cur_max_index=-1;
        for (int j=0; j<length; j++)
        {
            if (box2[j]>cur_max)
            {
                cur_max=box2[j];
                cur_max_index=j;
            }
        }

        result[top]=box2[cur_max_index];
        top++;
        box2[cur_max_index]=INT_MIN;
    }

    return result[k-1];
}

int main()
{
    int box[]={1,9,2,8,3,7,4,6,5};
    int box_length=sizeof(box)/sizeof(int);


    //std::cout<<INT_MIN<<std::endl;
    std::cout<<kth_largest(box,box_length,5);


    return 0;
}
