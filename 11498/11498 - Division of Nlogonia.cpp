#include <iostream>

using namespace std;


int main()
{
    int k;
    int m;
    int n;
    int x;
    int y;


    while(1) {
        cin>>k;
        if(k == 0) {
            break;
        }
        cin>>m>>n;

        while(k--) {
            cin>>x>>y;
            if(x == m || y == n) {
                cout<<"divisa"<<endl;
            }
            else if(x > m && y > n) {
                cout<<"NE"<<endl;
            }
            else if(x < m && y > n) {
                cout<<"NO"<<endl;
            }
            else if(x < m && y < n) {
                cout<<"SO"<<endl;
            }
            else if(x > m && y < n) {
                cout<<"SE"<<endl;
            }
        }
    }

    return 0;
}
