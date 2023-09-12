#include <iostream>

typedef struct interval
{
    int x;
    int y;

} INTERVAL;

void print_array(INTERVAL box[], int length)
{
    std::cout<<"{";
    for (int i=0; i<length; i++)
    {
        std::cout<<"{"<<box[i].x<<","<<box[i].y<<"}";
        if (i!=length-1)
        {
            std::cout<<",";
        }
    }
    std::cout<<"}"<<std::endl;
}

void insertion_sort(INTERVAL box[], int length)
{
    int j;
    for (int i=0; i<length; i++)
    {
        j=i;
        while (box[j-1].x>box[j].x && j>0)
        {
            INTERVAL tmp=box[j];
            box[j]=box[j-1];
            box[j-1]=tmp;
            j--;
        }
    }
}


void merge_overlapping_intervals(INTERVAL box[], int length)
{
    insertion_sort(box,length);
    INTERVAL tmp[length];
    int tmp_top=0;
    int j=0;
    std::cout<<"{";
    for (int i=0; i<length; i++)
    {
        j=i+1;
        while (box[i].y>=box[j].x && j<length)
        {
            j++;
        }

        std::cout<<"{"<<box[i].x<<","<<std::max(box[j-1].y,box[i].y)<<"}";
        tmp_top++;
        i=j-1;


    }
    std::cout<<"}"<<std::endl;
}


int main()
{
    INTERVAL box[]={{1,3},{2,4},{6,8},{9,10}};
    int box_length=sizeof(box)/sizeof(INTERVAL);

    INTERVAL box2[]={{6,8},{1,9},{2,4},{4,7}};
    int box2_length=sizeof(box2)/sizeof(INTERVAL);

    INTERVAL box3[]={{1,3},{2,8},{5,27}};
    int box3_length=sizeof(box3)/sizeof(INTERVAL);

    merge_overlapping_intervals(box,box_length);
    merge_overlapping_intervals(box2,box2_length);
    merge_overlapping_intervals(box3,box3_length);

    return 0;
}
