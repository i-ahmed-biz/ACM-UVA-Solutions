#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
bool isVawel(char ch)
{
    char vowel[]="aeiou";
    int i;
    for(i = 0;i <5;i++)
    {
        if(vowel[i] == ch)
            return true;
    }

    return false;
}
bool isConsonent(char ch)
{
    if(isVawel(ch) == false)
        return true;
    return false;
}
int main()
{
    char first[25],second[25];
    int T,len,i;
    gets(first);
    sscanf(first,"%d",&T);
    while(T--)
    {
        gets(first);
        gets(second);

        len = strlen(first);
        if( len!= strlen(second))
        {
            printf("No\n");
        }
        else
        {
            for(i = 0; i < len;i++)
            {
               if(isVawel(first[i]) != isVawel(second[i]))
               {
                   break;
               }
               else if(isConsonent(first[i]) == true && first[i]!= second[i])
               {
                   break;
               }

            }
            if(i == len)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}
