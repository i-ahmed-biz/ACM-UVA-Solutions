#include <iostream>

using namespace std;

int main() {
    int tc;
    string s;

    cin>>tc;

    while (tc--) {
        cin>>s;

        int len = s.length();

        if (s == "0" || s == "4" || s == "78") {
            cout<<"+"<<endl;
        }

        else if (s.c_str()[len - 1] == '5' && s.c_str()[len - 2] == '3') {
            cout<<"-"<<endl;
        }
        else if (s.c_str()[0] == '9' && s.c_str()[len - 1] == '4') {
            cout<<"*"<<endl;
        }
        else if (s.c_str()[0] == '1' && s.c_str()[1] == '9' && s.c_str()[2] == '0') {
            cout<<"?"<<endl;
        }
        else {
            cout<<"+"<<endl;
        }
    }

    return 0;
}
