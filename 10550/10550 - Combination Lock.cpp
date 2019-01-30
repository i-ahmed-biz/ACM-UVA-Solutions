#include <iostream>

using namespace std;

int getPositionDifference(int dest, int src) {
    return (dest - src + 40) % 40;
}

int main()
{
    int initialMark;
    int combNumbers[3];
    int degreeDiff;
    int totalDegreeDiff;

    while(1) {
       totalDegreeDiff = 0;
       cin>>initialMark>>combNumbers[0]>>combNumbers[1]>>combNumbers[2];
       if(initialMark == 0 && combNumbers[0] == 0 && combNumbers[1] == 0 && combNumbers[2] == 0) {
           break;
       }

       totalDegreeDiff = totalDegreeDiff + getPositionDifference(initialMark, combNumbers[0]);
       totalDegreeDiff = totalDegreeDiff + getPositionDifference(combNumbers[1], combNumbers[0]);
       totalDegreeDiff = totalDegreeDiff + getPositionDifference(combNumbers[1], combNumbers[2]);
       totalDegreeDiff = (totalDegreeDiff * 9) + 1080;
       cout<<totalDegreeDiff<<endl;
    }

    return 0;
}
