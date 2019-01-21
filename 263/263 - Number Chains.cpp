#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

int compare(const void* a, const void* b) {
   char* arg1 = (char*) a;
   char* arg2 = (char*) b;

   if( *arg1 < *arg2 ) {
        return 1;
   }
   else if( *arg1 == *arg2 ) {
    return 0;
   }
   else {
        return -1;
   }
 }
 void strReverse(char *str)
 {
     int n;
     char* lastChar;
     char tmpChar;

     n = strlen(str);
     lastChar = str + n - 1;

     while(str <= lastChar)
     {
         tmpChar = *str;
         *str = *lastChar;
         *lastChar = tmpChar;

         str++;
         lastChar--;
     }
 }
int main()
{
    char descendingStr[20];
    char ascendingStr[20];
    char diffStr[20];
    long long descendingInt,ascendingInt,diffInt;
    long long cycle;
    std::map<long long,long long> diffMap;

    scanf("%s", descendingStr);
    while(strcmp(descendingStr,"0") != 0) {
        printf("Original number was %s\n", descendingStr);
        qsort(descendingStr, strlen(descendingStr), sizeof(char), compare);

        cycle = 0;
        diffMap.clear();
        do {
                strcpy(ascendingStr, descendingStr);
                strReverse(ascendingStr);

                descendingInt = atoi(descendingStr);
                ascendingInt = atoi(ascendingStr);
                diffInt = descendingInt - ascendingInt;

                printf("%lli - %lli", descendingInt, ascendingInt);
                printf(" = %lli\n", diffInt);
                sprintf(diffStr,"%lli", diffInt);
                cycle++;

                if(diffMap[diffInt] == 1)
                {
                    printf("Chain length %lli\n\n",cycle);
                    break;
                }

                diffMap[diffInt] = 1;
                qsort(diffStr, strlen(diffStr), sizeof(char), compare);
                strcpy(descendingStr, diffStr);
        } while(1);

        scanf("%s", descendingStr);

    }
}
