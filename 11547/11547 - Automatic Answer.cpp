#include <iostream>

using namespace std;


int main()
{
    int t;
    int x;
    long int result;

    cin>>t;

    while(t--) {
        cin>>x;
        result = (((x * 315) + 36962) / 10) % 10;
        result = result < 0 ? -result: result;
        cout<<result<<endl;
    }

    return 0;
}
