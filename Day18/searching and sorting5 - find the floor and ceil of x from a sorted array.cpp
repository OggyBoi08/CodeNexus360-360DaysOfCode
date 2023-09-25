#include <iostream>

typedef struct floor_ceil
{
    int floor;
    int ceil;
} FC;

FC binary_s(int box[], int start, int finish, int target)
{
    FC tmp;
    if (target<box[start])
    {
        tmp.floor=INT_MIN;
        tmp.ceil=box[start];
        return tmp;
    }
    if (target>box[finish])
    {
        tmp.floor=box[finish];
        tmp.ceil=INT_MAX;
        return tmp;
    }

    int mid;
    while (start<finish)
    {
        //std::cout<<std::endl<<start<<" "<<finish;
        mid=(start+finish)/2;
        if (box[mid]==target)
        {
            tmp.floor=box[mid];
            tmp.ceil=box[mid];
            return tmp;
        }
        if (finish==start+1)
        {
            tmp.floor=box[start];
            tmp.ceil=box[finish];
            return tmp;
        }
        if (box[mid]<target)
        {
            start=mid;
        }
        if (box[mid]>target)
        {
            finish=mid;
        }
    }

    tmp.floor=box[start];
    tmp.ceil=box[finish];
    return tmp;
}

int main()
{
    int box[]={1,2,8,10,10,12,19};
    int box_length=sizeof(box)/sizeof(int);

    FC result1=binary_s(box,0,box_length-1,15);

    std::cout<<result1.floor<<" "<<result1.ceil;

    return 0;
}
