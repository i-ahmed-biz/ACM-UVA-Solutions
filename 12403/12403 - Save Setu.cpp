#include <iostream>

using namespace std;

int main()
{
    int t;
    int totalAmount = 0, amount;
    string command;

    cin>>t;

    while(t--) {
        cin>>command;
        if(command == "report") {
            cout<<totalAmount<<endl;
        }
        else if(command == "donate") {
            cin>>amount;
            totalAmount = totalAmount + amount;
        }
    }

    return 0;
}
