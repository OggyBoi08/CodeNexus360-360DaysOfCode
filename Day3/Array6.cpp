#include <iostream>

int search_peak(int box[], int length)
{
    if (length==1)
    {
        return 0;
    }
    if (length==2)
    {
        if (box[0]>box[1])
        {
            return 0;
        }
        if (box[1]>box[0])
        {
            return 1;
        }
    }
    int l=0;
    int r=length;
    int mid;
    while (l<r)
    {
        mid=(l+r)/2;
        if (mid==length-1 || box[mid]>box[mid+1])
        {
            return mid;
        }
        if (box[mid]>box[l])
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }

    return mid;
}

int Binary_Search(int box[], int l, int r, int target)
{
    int mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (box[mid]==target)
        {
            return mid;
        }
        if (box[mid]<target)
        {
            l=mid+1;
        }
        if (box[mid]>target)
        {
            r=mid-1;
        }

        //std::cout<<std::endl<<l<<" "<<r;
    }

    return -1;
}


int shifter_array_search(int box[], int length, int target)
{
    int peak=search_peak(box,length);
    int left_half=Binary_Search(box,0,peak,target);
    if (left_half!=-1)
    {
        return left_half;
    }
    int right_half=Binary_Search(box,peak+1,length-1,target);
    if (right_half!=-1)
    {
        return right_half;
    }

    return -1;
}

int main()
{
    int box[]={12,23,34,45,56,78,79,80,90,110};
    int box2[]={78,79,80,90,110,12,23,34,45,56};
    int box_length=sizeof(box)/sizeof(int);

    std::cout<<shifter_array_search(box2,box_length,45);
    return 0;
}
