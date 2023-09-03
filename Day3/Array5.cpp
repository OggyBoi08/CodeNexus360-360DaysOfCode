#include <iostream>

template <typename TYPE>
void print_array(TYPE box, int length)      //Print 1D array given array and length. Except string array
{
    std::cout<<"{";
    for (int n=0; n<length; n++)
    {
        std::cout<<box[n];
        if (n<length-1)
        {
            std::cout<<",";
        }
    }

    std::cout<<"}\n";

}

void Merge(int box[], int start, int mid, int finish)
{
    int tmp1[mid-start+1];
    int tmp2[finish-mid];

    int tmp1_length=0;              //Putting values in tmp1
    for (int i=start; i<=mid; i++)
    {
        tmp1[tmp1_length]=box[i];
        tmp1_length++;
    }

    int tmp2_length=0;             //Putting values in tmp2
    for (int i=mid+1; i<=finish; i++)
    {
        tmp2[tmp2_length]=box[i];
        tmp2_length++;
    }

    int i=0;
    int j=0;
    int k=start;
    while (true)
    {
        if (i==tmp1_length)
        {
            for (j; j<tmp2_length; j++)
            {
                box[k]=tmp2[j];
                k++;
            }
            break;
        }
        if (j==tmp2_length)
        {
            for (i; i<tmp1_length; i++)
            {
                box[k]=tmp1[i];
                k++;
            }
            break;
        }

        if (tmp1[i]<tmp2[j])
        {
            box[k]=tmp1[i];
            i++;
            k++;
        }
        else if (tmp2[j]<tmp1[i])
        {
            box[k]=tmp2[j];
            j++;
            k++;
        }
        else
        {
            box[k]=tmp1[i];
            i++;
            k++;
            box[k]=tmp2[j];
            j++;
            k++;
        }
    }
}

void MergeSort(int box[], int start, int finish)
{
    if (start<finish)
    {
        int mid=(start+finish)/2;
        MergeSort(box,start,mid);
        MergeSort(box,mid+1,finish);
        Merge(box,start, mid, finish);
    }
}


int distribute_chocolate(int box[], int N, int m)
{
    if (N==0 || m==0)
    {
        return 0;
    }
    if (N<m)
    {
        return -1;
    }
    int box_copy[N];
    for (int i=0; i<N; i++)
    {
        box_copy[i]=box[i];
    }

    MergeSort(box_copy,0,N);

    int min_diff=INT_MAX;
    int j=0;
    for (int i=m-1; i<N; i++)
    {
        if ((box_copy[i]-box_copy[j])<min_diff)
        {
            min_diff=box_copy[i]-box_copy[j];
        }
        j++;
    }

    return min_diff;
}

int main()
{
    int box[]={18, 66, 38, 83, 73, 80, 27, 93, 94, 13,
                28, 59, 2,  22, 3,  87, 88, 25, 44, 43,
                51, 34, 96, 10, 48, 5,  91, 70, 17, 29,
                14, 21, 58, 68, 33, 90, 84, 53, 41, 55,
                79, 89, 11, 100, 1, 72, 31, 40, 15, 4,
                61, 62, 19, 69, 12, 49, 98, 82, 32, 74,
                76, 63, 52, 7,  35, 85, 57, 77, 60, 36,
                71, 45, 39, 24, 6,  56, 42, 67, 65, 8,
                50, 23, 92, 54, 95, 75, 37, 64, 20, 86,
                30, 47, 26, 97, 9,  46, 16, 81, 99, 78};
    int box_length=sizeof(box)/sizeof(int);

    print_array(box,box_length);

    std::cout<<std::endl<<distribute_chocolate(box,box_length,45);

    return 0;
}
