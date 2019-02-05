#include <iostream>

using namespace std;

int main()
{
    int n;
    int x;
    int i = 1;
    int j;
    int eventCounter;
    int treatCounter;

    while(1) {
        cin>>n;

        if(n == 0) {
            break;
        }

        eventCounter = 0;
        treatCounter = 0;

        for(j = 0; j < n; j++) {
            cin>>x;

            if(x == 0) {
               treatCounter++;
            }
            else {
               eventCounter++;
            }
        }

        cout<<"Case "<<i<<": "<<(eventCounter - treatCounter)<<endl;
        i++;
    }

    return 0;
}
