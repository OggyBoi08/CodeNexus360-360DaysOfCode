#include <iostream>

int find_min(int box[], int length)
{
    if (length==1)
    {
        return 0;
    }
    else if (length==2)
    {
        if (box[0]>box[1])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        int l=0;
        int r=length-1;
        int mid;
        while (l<r)
        {
            mid=(l+r)/2;
            if (mid==0 || box[mid]<box[mid-1])
            {
                return mid;
            }
            (box[mid]<box[r])?(r=mid):(l=mid);
            std::cout<<std::endl<<l<<" "<<r;
        }
    }

    return -1;

}

int main()
{
    int box[]={5,6,7,8,9,0,1,2,3,4};
    int box2[]={0,1,2,3,4,5,6,7,8,9};
    int box_length=sizeof(box)/sizeof(int);

    std::cout<<find_min(box2,box_length);
    return 0;
}
