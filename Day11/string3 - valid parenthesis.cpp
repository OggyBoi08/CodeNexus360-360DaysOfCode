#include <iostream>
#include <string>

char open[]={'(','[','{'};
char close[]={')',']','}'};

bool is_present(char box[], char x)
{
    for (int i=0; i<3; i++)
    {
        if (box[i]==x)
        {
            return true;
        }
    }

    return false;
}

bool valid_parenthesis(std::string x)
{
    int stc[6];
    int stc_top=0;
    for (char i : x)
    {
        if (stc_top==0)
        {
            if (is_present(close,i))
            {
                return false;
            }
            else
            {
                stc[stc_top]=i;
                stc_top++;
            }

            continue;

        }
        if (is_present(open,i))
        {
            stc[stc_top]=i;
            stc_top++;
            continue;
        }
        if (is_present(close,i))
        {
            if (stc[stc_top-1]+1==(int)i || stc[stc_top-1]+2==(int)i)
            {
                stc_top--;
            }
            else
            {
                return false;
            }
        }
    }

    if (stc_top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string x="([}])";

    std::cout<<valid_parenthesis(x);

    return 0;
}
