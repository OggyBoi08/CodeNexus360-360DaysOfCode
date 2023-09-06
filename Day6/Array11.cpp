#include <iostream>


int rain_collected(int box[], int length)
{
    int cur_peak=INT_MIN;
    int add_till=0;
    int result=0;
    for (int i=0; i<length; i++)
    {
        if (box[i]>cur_peak)
        {
            cur_peak=box[i];
            for (int j=i+1; j<length; j++)
            {
                if (box[j]>=cur_peak)
                {
                    add_till=j;
                    break;
                }
            }
            if (add_till==i)
            {
                cur_peak=INT_MIN;
            }
        }
        if (i<add_till)
        {
            result+=cur_peak-box[i];
            //std::cout<<add_till<<" "<<i<<" "<<result<<std::endl;
        }

        //std::cout<<std::endl<<cur_peak;
        /*
        else
        {
            cur_peak=box[i+1];
        }
        */
    }

    return result;
}

int main()
{
    int box[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int box_length=sizeof(box)/sizeof(int);
    int box2[]={4,2,0,3,2,5};
    int box2_length=sizeof(box2)/sizeof(int);

    std::cout<<rain_collected(box2,box2_length);

    return 0;
}
