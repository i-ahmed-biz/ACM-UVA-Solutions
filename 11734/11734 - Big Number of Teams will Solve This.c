#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removespace(char str[])
{
    int n,i;
    char output[100];
    int outputLen;
    n = strlen(str);
    outputLen = 0;
    for(i = 0; i < n; i++)
    {
        if(str[i]== ' ') continue;
        output[outputLen] = str[i];
        outputLen++;
    }
    output[outputLen] = '\0';
    strcpy(str,output);

    return str;
}

int main()
{
    int T,i;
    char judge[100],str[100];

    scanf("%d",&T);
    fgetc(stdin);

    for(i = 0; i < T;i++)
    {
        gets(str);
        gets(judge);
        if(strcmp(str,judge) == 0)
        {
            printf("Case %d: Yes\n",i+1);
        }
        else if(strcmp(removespace(str),removespace(judge)) == 0)
        {
            printf("Case %d: Output Format Error\n",i+1);
        }
        else
        {
           printf("Case %d: Wrong Answer\n",i+1);

        }
    }
    return 0;
}
