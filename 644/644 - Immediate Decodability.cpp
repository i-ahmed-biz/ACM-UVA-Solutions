#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare( string a, string b )
{
    return a.size() < b.size();
}


int main()
{
    string value;
    std::vector<string> codeList;
    int i;
    int j;
    int setCounter = 0;
    bool answer;
    while(cin>>value)
    {
        if(value == "9")
        {
            sort(codeList.begin(),codeList.end(),compare);
            answer = false;
            setCounter ++;

            for(i = 0 ; i < codeList.size()-1 && !answer; i++)
            {
                for(j = i + 1; j< codeList.size()&&!answer; j++)
                {
                    string a,b;
                    a = codeList[i];
                    b = codeList[j];

                    if(b.compare(0,a.size(),a)== 0)
                    {
                    	answer = true;
                        break;
                    }
                }
            }

            if(answer)
            {
               cout<<"Set "<<setCounter<<" is not immediately decodable\n";
            }
            else{
               cout<<"Set "<<setCounter<<" is immediately decodable\n";
            }

            codeList.clear();
        }
        else
        {
        	codeList.push_back(value);
        }
    }
    return 0;
}
