#include <iostream>

using namespace std;

int main()
{
    string words[3] = {"one", "two", "three"};
    string text;
    int n;
    int i;
    int j;
    int matchCounter;


    cin>>n;

    while(n--) {
        cin>>text;
    	for(i = 0; i < 3; i++) {
    	    matchCounter = 0;

    	    for(j = 0; j < text.length()  && text.length() == words[i].length();j++) {
    	        if(words[i].c_str()[j] == text.c_str()[j]) {
    	            matchCounter++;
    	        }
    	    }
    	    if(matchCounter >= text.length() - 1) {
    	       cout<<(i + 1)<<endl;
    	    }
    	}

    }

    return 0;
}
