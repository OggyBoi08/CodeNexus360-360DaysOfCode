#include <iostream>

/*
void permu1(int box[], int length)
{
    for (int i=0; i<length; i++)
    {
        for (int j=i+1; j<length; j++)
        {
            for (int k=j+1; k<length; k++)
            {
                std::cout<<box[i]<<" "<<box[j]<<" "<<box[k]<<std::endl;
            }
        }
    }
}
*/


void print(int box[], int length)
{
    for (int i=0; i<length; i++)
    {
        std::cout<<box[i]<<" ";
    }
    std::cout<<std::endl;
}




void permu(int box[],int start, int finish, int tmp[], int tmp_length, int r)
{
    //tmp[tmp_length]=box[i];
    if (tmp_length==r)
    {
        print(tmp,r);
        return;
        //std::cout<<std::endl<<tmp_length;
    }
    for (int i=start; i<=finish && finish - i + 1 >= r - tmp_length; i++)
    {
        tmp[tmp_length]=box[i];
        permu(box,i+1,finish,tmp,tmp_length+1,r);
    }
}

void find_permutation(int box[], int length, int r)
{
    int tmp[r];
    permu(box,0,length-1,tmp,0,r);
}


int main()
{
    int box[]={1,2,3,4,5,6,7};
    int box_length=sizeof(box)/sizeof(int);

    find_permutation(box,box_length,4);

    return 0;
}
