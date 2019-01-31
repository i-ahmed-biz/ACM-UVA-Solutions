#include <iostream>

using namespace std;


int main()
{
    int n;
    int m;
    int tc;

    cin>>tc;
    while(tc--) {
        cin>>n>>m;
        cout<<(n/3) * (m/3)<<endl;
    }

    return 0;
}
