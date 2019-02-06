#include <iostream>

using namespace std;

int main()
{
    string hajjName, hajjFullName;
    int caseNo = 1;

    while(1) {
        cin>>hajjName;
        if(hajjName == "*") {
            break;
        }
        else if(hajjName == "Hajj") {
            hajjFullName = "Hajj-e-Akbar";
        }
        else if(hajjName == "Umrah") {
            hajjFullName = "Hajj-e-Asghar";
        }
        cout<<"Case "<<caseNo<<": " <<hajjFullName<<endl;
        caseNo++;
    }

    return 0;
}
