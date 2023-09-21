#include <iostream>
#include <cmath>

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



/*
int digit(int num, int n)
{
    int div=num/pow(10,n-1);
    return div%10;
}
*/

int power(int num, int n)
{
    int result=1;
    for (int i=0; i<n; i++)
    {
        result*=num;
    }

    return result;
}


bool lesser(int num1, int num2)
{
    int digit1=log10(num2)+1;
    int digit2=log10(num1)+1;
    int mult1=power(10,digit1);
    int mult2=power(10,digit2);

    //std::cout<<digit1<<" "<<mult1<<" "<<digit2<<" "<<mult2;

    num1*=mult1;
    num2*=mult2;

    num1+=(mult1-1);
    num2+=(mult2-1);


    return num1<num2;
}

void insertion_sort(int box[], int box_length)
{
    int j;
    for (int i=0; i<box_length; i++)
    {
        j=i;
        while (j>0 && lesser(box[j-1],box[j]))
        {
            //std::cout<<std::endl<<box[j-1]<<" "<<box[j];
            int tmp=box[j];
            box[j]=box[j-1];
            box[j-1]=tmp;
            j--;
        }
        //std::cout<<std::endl<<box[i];
    }
}


int main()
{
    int box2[]={18, 66, 38, 83, 73, 80, 27, 93, 94, 13,
                28, 59, 2,  22, 3,  87, 88, 25, 44, 43,
                51, 34, 96, 10, 48, 5,  91, 70, 17, 29,
                14, 21, 58, 68, 33, 90, 84, 53, 41, 55,
                79, 89, 11, 100, 1, 72, 31, 40, 15, 4,
                61, 62, 19, 69, 12, 49, 98, 82, 32, 74,
                76, 63, 52, 7,  35, 85, 57, 77, 60, 36,
                71, 45, 39, 24, 6,  56, 42, 67, 65, 8,
                50, 23, 92, 54, 95, 75, 37, 64, 20, 86,
                30, 47, 26, 97, 9,  46, 16, 81, 99, 78};
    int box2_length=sizeof(box2)/sizeof(int);


    print_array(box2,box2_length);
    insertion_sort(box2,box2_length);
    print_array(box2,box2_length);




    //lesser(9,98);

    return 0;
}
