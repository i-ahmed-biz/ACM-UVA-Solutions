#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isConsonent(char ch)
{
    if(ch == 'a' || ch=='e' || ch == 'i'||ch=='o' || ch == 'u')
        return 0;

    return 1;
}

int main()
{
    int N;
    int L;
    int i,j;
    char singularArr[21][21];
    char pluralArr[21][21];
    char foodArray[101][25];
    int lastChar;
    int pluralFlag;

    scanf("%d%d",&L,&N);

    for(i = 0;i<L;i++)
    {
        scanf("%s%s",singularArr[i],pluralArr[i]);
    }

    for(i = 0;i<N;i++)
    {
        scanf("%s",foodArray[i]);
    }
    for(i= 0;i<N;i++)
    {
        pluralFlag = 0;
        for(j =0;j<L;j++)
        {
            if(strcmp(foodArray[i],singularArr[j])==0)
            {
                printf("%s\n",pluralArr[j]);
                pluralFlag = 1;
                break;
            }
        }
        if(pluralFlag == 1)
        {
            continue;
        }
        lastChar = strlen(foodArray[i]) - 1;
        if(foodArray[i][lastChar] == 'y' && isConsonent(foodArray[i][lastChar - 1]))
        {
            foodArray[i][lastChar] = '\0';
            strcat(foodArray[i],"ies");
        }
        else if(foodArray[i][lastChar]=='o' || foodArray[i][lastChar]=='s' || foodArray[i][lastChar]=='x')
        {
            strcat(foodArray[i],"es");
        }
        else if(foodArray[i][lastChar]=='h' &&(foodArray[i][lastChar-1]=='c' ||foodArray[i][lastChar-1] == 's'))
        {
            strcat(foodArray[i],"es");
        }
        else
        {
            strcat(foodArray[i],"s");
        }

        printf("%s\n",foodArray[i]);

    }

    return 0;
}
