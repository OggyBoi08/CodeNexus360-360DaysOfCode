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

int return_kth_smallest_element(int box[], int length, int k)
{
    if (k>length)
    {
        return -1;
    }
    int box_copy[length];
    for (int i=0; i<length; i++)
    {
        box_copy[i]=box[i];
    }

    QuickSort(box_copy,0,length-1);

    return box_copy[k-1];
}

int main()
{
    int box[]={90,80,70,10,20,30,40,100,99,98,97};
    int box_length=sizeof(box)/sizeof(box_length);

    std::cout<<return_kth_smallest_element(box,box_length,10);
    return 0;
}
