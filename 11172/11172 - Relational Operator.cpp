#include <iostream>

using namespace std;


int main()
{
    int a;
    int b;
    int tc;
    char result;

    cin>>tc;
    while(tc--) {
        cin>>a>>b;
        result = a > b ? '>': a < b ? '<': '=';
        cout<<result<<endl;
    }

    return 0;
}
