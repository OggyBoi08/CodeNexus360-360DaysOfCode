#include <iostream>

template <typename TYPE>
void print_array(TYPE box, int l, int r)      //Print 1D array given array and length. Except string array
{
    std::cout<<"{";
    for (int n=l; n<r+1; n++)
    {
        std::cout<<box[n];
        if (n<r)
        {
            std::cout<<",";
        }
    }

    std::cout<<"}\n";

}

int merge_required_for_palindrome(int box[], int length)
{
    int result=0;
    int l=0;
    int r=length-1;
    while (l<r)
    {
        if (box[l]==box[r])
        {
            l++;
            r--;
        }
        else if (box[l]<box[r])
        {
            l++;
            box[l]+=box[l-1];
            result++;
        }
        else
        {
            r--;
            box[r]+=box[r+1];
            result++;
        }
    }
    return result;

}

int main()
{
    int box[]={15,4,15};
    int box_length=sizeof(box)/sizeof(int);

    int box2[]={1,4,5,1};
    int box2_length=sizeof(box2)/sizeof(int);

    int box3[]={11,14,15,99};
    int box3_length=sizeof(box3)/sizeof(int);

    std::cout<<merge_required_for_palindrome(box3,box3_length);

    return 0;
}
