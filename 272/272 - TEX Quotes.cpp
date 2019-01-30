
#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    char inputChar;
    bool isStartQuote = true;

    while((inputChar = getchar()) != EOF){
       if(inputChar == '"' && isStartQuote) {
           cout<<"``";
           isStartQuote = !isStartQuote;
       }
       else if (inputChar == '"' && !isStartQuote) {
           cout<<"''";
           isStartQuote = !isStartQuote;
       }
       else {
           cout<<inputChar;
       }
    }

    return 0;
}
