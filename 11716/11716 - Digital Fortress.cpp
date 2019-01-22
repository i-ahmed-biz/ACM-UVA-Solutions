#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T,len,sqrtLen,row,colm,index;
    char text[10002];
    scanf("%d",&T);
    fgetc(stdin);

    while(T--)
    {
        gets(text);
        len = strlen(text);
        sqrtLen = (int)sqrt(len);
        if(sqrtLen * sqrtLen != len)
        {
            printf("INVALID\n");
        }
        else
        {
            for(colm = 0; colm <sqrtLen;colm++)
            {
                for(row = 0;row<sqrtLen;row++)
                {
                    index = row * sqrtLen + colm;
                    printf("%c",text[index]);
                }
            }
            printf("\n");

        }
    }

    return 0;
}
