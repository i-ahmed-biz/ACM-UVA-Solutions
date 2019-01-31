#include <iostream>

using namespace std;


int main()
{
    int tc;
    int n;
    int x;
    int max;
    int min;

    cin>>tc;

    while(tc--) {
        cin>>n;
        max = 0;
        min = 99;
        while(n--) {
            cin>>x;
            if(x > max) {
                max = x;
            }
            if(x < min) {
                min = x;
            }
        }
        cout<<(max - min) * 2<<endl;
    }

    return 0;
}
