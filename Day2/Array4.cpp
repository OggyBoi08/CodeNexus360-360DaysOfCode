#include <iostream>


template <typename TYPE>
bool duplicate(TYPE box[], int length)
{
    for (int i=0; i<length; i++)
    {
        for (int j=i+1; j<length; j++)
        {
            if (box[i]==box[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int box[]={4,2,3,1};
    int length=sizeof(box)/sizeof(int);

    int box2[]={18, 66, 38, 83, 73, 80, 27, 93, 94, 13,
                28, 59, 2,  22, 3,  87, 88, 25, 44, 43,
                51, 34, 96, 10, 48, 5,  91, 70, 17, 29,
                14, 21, 58, 68, 33, 90, 84, 53, 41, 55,
                79, 89, 11, 100, 1, 72, 31, 40, 15, 4,
                61, 62, 19, 69, 12, 49, 98, 82, 32, 74,
                76, 63, 52, 7,  35, 85, 57, 77, 60, 36,
                71, 45, 39, 24, 6,  56, 42, 67, 65, 8,
                50, 23, 92, 54, 95, 75, 37, 64, 20, 86,
                30, 47, 26, 97, 9,  46, 16, 81, 99, 101};
    int box2_length=sizeof(box2)/sizeof(int);

    if (duplicate(box2,box2_length))
    {
        std::cout<<"Duplicate exist";
    }
    else
    {
        std::cout<<"unique array";
    }


    return 0;
}
