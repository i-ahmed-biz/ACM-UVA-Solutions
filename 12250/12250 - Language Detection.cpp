#include <iostream>
#include <cstdlib>

using namespace std;

string getLanguage(string text) {
    if(text == "HELLO") {
        return "ENGLISH";
    }
    else if(text == "HOLA"){
        return "SPANISH";
    }
    else if(text == "HALLO"){
        return "GERMAN";
    }
    else if(text == "BONJOUR"){
        return "FRENCH";
    }
    else if(text == "CIAO"){
        return "ITALIAN";
    }
    else if(text == "ZDRAVSTVUJTE"){
        return "RUSSIAN";
    }

    return "UNKNOWN";

}

int main()
{
    string text;
    int i = 1;

    while(1) {
        cin>>text;
        if(text == "#") {
            break;
        }

        cout<<"Case "<<i<<": "<<getLanguage(text)<<endl;
        i++;
    }

    return 0;
}
