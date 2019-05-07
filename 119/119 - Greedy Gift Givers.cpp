
#include <iostream>
#include <map>

using namespace std;


int main()
{

    int noFriends;
    int i;
    int j;
    int totalGift;
    int noFriendsGifted;
    int giftAmountPerPerson;
    string friendsList[10];
    string giftedFriend;
    string currentFriend;
    map <string, int> remainingMoney;

    cin>>noFriends;

    while(1){
        remainingMoney.clear();

        for(i = 0; i < noFriends; i++) {
            cin>>friendsList[i];
            remainingMoney[friendsList[i]] = 0;
        }

        for(i = 0; i < noFriends; i++) {
            cin>>currentFriend>>totalGift>>noFriendsGifted;
            if(noFriendsGifted == 0) {
                continue;
            }
            giftAmountPerPerson = totalGift / noFriendsGifted;
            remainingMoney[currentFriend] = remainingMoney[currentFriend] - (giftAmountPerPerson) * noFriendsGifted;

            for(j = 0; j < noFriendsGifted; j++) {
                cin>>giftedFriend;
                remainingMoney[giftedFriend] = remainingMoney[giftedFriend] + giftAmountPerPerson;
            }
        }

        for(j = 0; j < noFriends; j++) {
            cout<<friendsList[j]<<" "<<remainingMoney[friendsList[j]]<<endl;
        }

        if(cin>>noFriends) {
            cout<<endl;
        }
        else {
            break;
        }
    }

    return 0;
}
