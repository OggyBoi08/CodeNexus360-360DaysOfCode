#include <iostream>
#include <cmath>


bool checkbit(int box[], int index)
{
    return box[index>>5]|=(1<<(index&31));
}
void setbit(int box[], int index)
{
    box[index>>5]|=(1<<(index&31));
}


int main()
{
    int x=2;
    int y=10;
    int sized=abs(y-x)+1;
    sized=ceil((double)sized/32);
    int box[sized];

    for (int i=x; i<=y; i++)
    {
        if (i%2==0 || i%5==0)
        {
            setbit(box,i-x);
        }
    }

    for (int i=x; i<=y; i++)
    {
        if (checkbit(box,i-x))
        {
            std::cout<<i<<" ";
        }
    }
    return 0;
}
