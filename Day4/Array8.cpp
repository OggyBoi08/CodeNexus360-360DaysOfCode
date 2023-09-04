#include <iostream>


int best_time_to_buy(int box[], int length)
{
    int current_smallest=INT_MAX;
    int max_profit=0;
    for (int i=0; i<length; i++)
    {
        if (box[i]<current_smallest)
        {
            current_smallest=box[i];
        }
        if ((box[i]-current_smallest)>max_profit)
        {
            max_profit=box[i]-current_smallest;
        }
    }

    return max_profit;
}

int main()
{
    int box1[]={7,6,4,3,1};
    int box1_length=sizeof(box1)/sizeof(int);

    int box2[]={7,1,5,3,6,4};
    int box2_length=sizeof(box2)/sizeof(int);

    std::cout<<best_time_to_buy(box1,box1_length);


    return 0;
}
