#include <iostream>


int min_num(int x, int y)
{
    if (x>y)
    {
        return y;
    }
    else
    {
        return x;
    }
}


//Brute force method
/*
int max_container(int box[], int length)
{
    int water=0;
    int max_water=0;
    int l=0;
    int r;

    for (int i=0; i<length; i++)
    {
        for (int j=i+1; j<length; j++)
        {
            water=min_num(box[i],box[j])*(j-i);
            if (water>max_water)
            {
                max_water=water;
            }
        }
    }
    //std::cout<<std::endl<<box[l]<<" "<<box[r]<<" "<<max_water;


    return max_water;
}
*/

int max_container(int box[], int length)
{
    int l=0;
    int r=length-1;
    int water=0;
    int max_water=0;

    while (l<length-1)
    {
        water=min_num(box[l],box[r])*(r-l);
        if (water>max_water)
        {
            max_water=water;
            l++;
        }
        else
        {
            break;
        }
    }

    while (r>0)
    {
        water=min_num(box[l],box[r])*(r-l);
        if (water>max_water)
        {
            max_water=water;
            r--;
        }
        else
        {
            break;
        }
    }

    return max_water;
}


int main()
{
    int box[]={1,2,3,4,5,6,7,8};
    int box_length=sizeof(box)/sizeof(int);

    int box2[]={1,8,6,2,5,4,8,3,7};
    int box2_length=sizeof(box2)/sizeof(int);

    int box3[]={1,1};
    int box3_length=sizeof(box3)/sizeof(int);

    int box4[]={46,72,24,79,99,30,54,61,51,91,
                77,46,71,46,92,84,62,33,2,16,
                96,4,57,59,99,79,55,68,98,20,
                78,31,43,22,100,45,93,1,43,45,
                97,76,39,29,30,70,3,83,55,87,
                71,67,61,21,40,19,69,4,28,13,
                52,65,96,28,12,15,61,15,83,19,
                33,25,1,74,17,11,58,50,35,83,
                97,43,1,15,100,55,5,63,85,49,
                81,96,73,28,48,38,76,37,9,73};
    int box4_length=sizeof(box2)/sizeof(int);


    std::cout<<max_container(box4,box4_length);

    return 0;
}
