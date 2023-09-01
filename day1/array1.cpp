#include <iostream>

struct result
{
    int maximum;
    int minimum;
};

struct result min_max(int box[], int length)
{
    int minimum=box[0];
    int maximum=box[0];
    for (int i=0; i<length; i++)
    {
        if (box[i]<minimum)
        {
            minimum=box[i];
        }
        if (box[i]>maximum)
        {
            maximum=box[i];
        }
    }

    struct result tmp;
    tmp.maximum=maximum;
    tmp.minimum=minimum;

    return tmp;
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

    struct result obj=min_max(box,box_length);

    std::cout<<"Max Element: "<<obj.maximum<<std::endl;
    std::cout<<"Min Element: "<<obj.minimum<<std::endl;


    return 0;
}
