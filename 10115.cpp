#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void replaceOccurence(char findStr[], char replaceStr[], char text[])
{
    int findLen;
    int replaceLen;
    int textLen;
    int diff;
    int i;

    findLen = strlen(findStr);
    replaceLen = strlen(replaceStr);
    textLen = strlen(text);
    diff = replaceLen - findLen;

    if(diff >= 0)
    {
        for(i = 0;i < diff+textLen;i++)
        {
            text[textLen + diff - i] = text[textLen - i];
        }
    }
    else
    {
        for(i = replaceLen;i <= textLen;i++)
        {
            text[i] = text[i - diff];
        }
    }
    for(i = 0;i<replaceLen;i++)
    {
        text[i] = replaceStr[i];
    }
}
void replaceString(char findStr[], char replaceStr[], char text[])
{
    int txtLen,dist;
    int pos = 0;
    char* returnStrPtr;

    txtLen = strlen(text);

    while(pos < txtLen)
    {
        returnStrPtr = strstr(&text[pos],findStr);
        if (returnStrPtr == NULL)
        {
            return;
        }
        dist = returnStrPtr - text;
        replaceOccurence(findStr,replaceStr,&text[dist]);
        txtLen = strlen(text);
    }
}
int main()
{
    char findStr[10][85];
    char replaceStr[10][85];
    char text[260];
    int noRules;
    int ruleCounter;
    FILE* input,*output;

    input = stdin;
    output = stdout;

    while(1)
    {
        scanf("%d",&noRules);
        getc(input);
        if(noRules <= 0)
        {
            break;
        }
        for(ruleCounter = 0; ruleCounter < noRules; ruleCounter++)
        {
            gets(findStr[ruleCounter]);
            gets(replaceStr[ruleCounter]);
        }

        gets(text);

        for(ruleCounter = 0; ruleCounter < noRules; ruleCounter++)
        {
            replaceString(findStr[ruleCounter],replaceStr[ruleCounter],text);
        }

        printf("%s\n",text);
    }

    fclose(input);
    fclose(output);

    return 0;
}
