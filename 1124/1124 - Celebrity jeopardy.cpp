#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    char inputChar;
    bool isStartQuote = true;

    while((inputChar = getchar()) != EOF) {
       cout<<inputChar;
    }

    return 0;
}
