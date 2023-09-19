#include <iostream>

int find_smallest_length(std::string box[], int length)
{
    int result=INT_MAX;
    for (int i=0; i<length; i++)
    {
        if (box[i].length()<result)
        {
            result=box[i].length();
        }
    }

    return result;
}


std::string common_prefix(std::string box[], int length)
{
    int n=0;
    int m;
    int run=find_smallest_length(box,length);
    //std::cout<<run;
    std::string result="";

    while (n<run)
    {
        m=0;
        while (m<length)
        {
            if (box[m][n]!=box[0][n])
            {
                break;
            }
            m++;
        }

        if (m==length)
        {
            result+=box[0][n];
        }
        n++;
    }

    return result;
}

int main()
{
    std::string box[]={"Agrim","Agrpu","Agrsus"};
    std::string box2[]={"Agrim","Agrpu","Agrsus","Argsus"};

    std::cout<<common_prefix(box,3);
    std::cout<<std::endl<<common_prefix(box2,4);

    return 0;
}
