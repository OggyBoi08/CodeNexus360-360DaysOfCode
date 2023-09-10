#include <iostream>

typedef struct result
{
    int x;
    int y;
} RESULT;

int find_peak(int box[], int length)
{
    int l=0;
    int r=length-1;
    int mid;

    while (l<r)
    {
        mid=(l+r)/2;
        if (box[mid]>box[mid+1])
        {
            return mid;
        }
        else if (box[mid]>box[l])
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }

    std::cout<<std::endl<<"flag";

    return (length-1);
}

int bin_search(int box[], int l, int r, int k)
{
    int mid;
    while (l<=r)
    {
        mid=l+(r-l)/2;
        if (box[mid]==k)
        {
            return mid;
        }
        else if (box[mid]<k)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

        //std::cout<<std::endl<<l<<" "<<r;
    }

    return -1;
}


RESULT if_two_numbers_add_up_to_k(int box[], int length, int k)
{
    RESULT tmp={-1,-1};
    int peak=find_peak(box,length);
    int left;
    int right;
    for (int i=0; i<length; i++)
    {
        left=bin_search(box,0,peak,k-box[i]);
        if (left!=-1)
        {
            tmp.x=box[i];
            tmp.y=box[left];
            return tmp;
        }
        right=bin_search(box,peak+1,length-1,k-box[i]);
        if (right!=-1)
        {
            tmp.x=box[right];
            tmp.y=box[i];
            return tmp;
        }
    }

    return tmp;
}


int main()
{
    int box[]={5,6,7,8,9,10,1,2,3,4};
    int box_length=sizeof(box)/sizeof(int);

   // std::cout<<bin_search(box,find_peak(box,box_length)+1,box_length-1,1);

    RESULT ans=if_two_numbers_add_up_to_k(box,box_length,9);

    std::cout<<ans.x<<" "<<ans.y;


    return 0;
}
