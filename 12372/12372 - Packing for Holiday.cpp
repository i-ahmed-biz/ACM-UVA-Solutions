#include <iostream>

using namespace std;

int main()
{
    int t, caseNo = 1;
    int l, w, h;
    string resultStr;

    cin>>t;

    while(t--) {
       cin>>l>>w>>h;
       if(l > 20 || w > 20 || h > 20) {
         resultStr = "bad";
       }
       else {
         resultStr = "good";
       }

       cout<<"Case "<<caseNo<<": "<<resultStr<<endl;
       caseNo++;
    }

    return 0;
}
