#include <iostream>
#include <vector>



std::vector<std::vector<int>> return_triplet_adding_up_to_zero(int box[], int length)
{
    std::vector<std::vector<int>> result;
    int top=0;
    for (int i=0; i<length-2; i++)
    {
        for (int j=i+1; j<length-1; j++)
        {
            for (int k=j+1; k<length; k++)
            {
                if ((box[i]+box[j]+box[k])==0)
                {
                    //std::cout<<std::endl<<box[i]<<" "<<box[j]<<" "<<box[k];
                    std::vector<int> tmp;
                    tmp.push_back(box[i]);
                    tmp.push_back(box[j]);
                    tmp.push_back(box[k]);
                    result.push_back(tmp);
                }
            }
        }
    }

    return result;

}


int main()
{
    int box[]={0,-1,2,-3,1};
    int box_length=sizeof(box)/sizeof(int);
    int box2[]={-5,-4,-3,-2,-1,0,1,2,3,4,5};
    int box2_length=sizeof(box2)/sizeof(int);

    std::vector<std::vector<int>> box3=return_triplet_adding_up_to_zero(box2, box2_length);

    for (int i=0; i<box3.size(); i++)
    {
        std::cout<<std::endl<<box3[i][0]<<" "<<box3[i][1]<<" "<<box3[i][2];
    }

    return 0;
}
