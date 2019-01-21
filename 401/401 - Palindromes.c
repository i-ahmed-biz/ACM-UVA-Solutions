#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findIndex(char input)
{
    char original[40]="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    int n;
    int i;
    n = strlen(original);
    for(i =0 ;i <n;i++)
    {
        if(original[i] == input)
            return i;
    }
    return i;
}
int main()
{
    char reverse[40]= "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    char str[30];
    char *firstStr;
    char *endStr;
    int palindrome;
    int mirror;

    while(scanf("%s",str)== 1)
    {
        palindrome = 1;
        mirror = 1;
        endStr = str + strlen(str) - 1;
        firstStr = str;
        while(firstStr <= endStr)
        {
            if(palindrome == 1 && *firstStr != *endStr)
            {
               palindrome = 0;
            }
            if(mirror == 1 && *firstStr != reverse[findIndex(*endStr)])
            {
               mirror = 0;
            }
            if(palindrome == 0 && mirror == 0) {
               break;
            }


            firstStr++;
            endStr--;
        }

        if(mirror == 0 && palindrome == 0)
        {
            printf("%s -- is not a palindrome.\n",str);
        }
        else if (mirror == 0 && palindrome == 1)
        {
            printf("%s -- is a regular palindrome.\n",str);
        }
        else if (mirror == 1 && palindrome == 0)
        {
            printf("%s -- is a mirrored string.\n",str);
        }
        else if (mirror == 1 && palindrome == 1)
        {
            printf("%s -- is a mirrored palindrome.\n",str);
        }
        printf("\n");
    }
    return 0;
}
