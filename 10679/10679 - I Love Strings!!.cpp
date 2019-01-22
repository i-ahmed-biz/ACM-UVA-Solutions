#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void kmpPreCalculation(char pattern[],int pi[])
{
    int i;
    int j;
    int M;

    M = strlen(pattern);

    pi[0] = 0;
    j = 0;
    i = 1;

    while(i < M)
    {
        if(pattern[i] == pattern[j])
        {
            j++;
            pi[i] = j;
            i++;
        }
        else if(j>0)
        {
            j = pi[j-1];
        }
        else
        {
            pi[i] = 0;
            i++;
        }
    }
}

int kmpMatch(char text[],char pattern[],int pi[])
{
    int N;
    int M;
    int i;
    int j;

    N = strlen(text);
    M = strlen(pattern);

    j = 0;

    for (i = 0; i < N;i++)
    {
        if(text[i] == pattern[j])
        {
            j++;
        }
        else if(j > 0 && text[i] != pattern[j])
        {
            j = pi[j-1];
        }
        else
        {
            j = 0;
        }
        if(j == M)
        {
            return 1;
        }

    }

    return -1;
}

int main()
{
    int T;
    int q;
    char text[100001];
    char pattern[1001];
    int pi[1000];

    scanf("%d",&T);

    while(T--)
    {
        scanf("%s",text);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s", pattern);
            kmpPreCalculation(pattern,pi);
            if(kmpMatch(text,pattern,pi) == 1)
            {
                printf("y\n");
            }
            else
            {
                printf("n\n");
            }
        }
    }

    return 0;
}
