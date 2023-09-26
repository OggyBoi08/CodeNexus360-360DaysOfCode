#include <iostream>

int Partition(int x[], int left, int right)
{
    int key=x[right];
    int j=left;
    for (int i=left; i<=right; i++)
    {
        if (x[i]<=key)
        {
            int tmp=x[j];
            x[j]=x[i];
            x[i]=tmp;
            j++;
        }
    }

    return j-1;
}

void QuickSort(int box[], int left, int right)
{
    if (left<right)
    {
        int mid=Partition(box,left,right);
        QuickSort(box,left,mid-1);
        QuickSort(box,mid+1,right);
    }
}

typedef struct result
{
    int x;
    int y;
} RESULT;

RESULT find_pair_with_given_difference(int box[], int length, int k)
{
    RESULT ans={-1,-1};
    QuickSort(box,0,length-1);

    int l=0;
    int r=length-1;
    while (l<r)
    {
        if ((box[r]-box[l])==k)
        {
            ans.x=box[l];
            ans.y=box[r];
            return ans;
        }
        else if ((box[r]-box[l])<k)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    return ans;
}

int main()
{
    int box[]={5,20,3,2,50,80};
    int box_length=sizeof(box)/sizeof(int);

    RESULT ans=find_pair_with_given_difference(box,box_length,78);
    std::cout<<std::endl<<ans.x<<" "<<ans.y;

    int box2[]={90,70,20,80,50};
    int box2_length=sizeof(box2)/sizeof(int);

    ans=ans=find_pair_with_given_difference(box2,box2_length,40);
    std::cout<<std::endl<<ans.x<<" "<<ans.y;

    return 0;
}
