#include <iostream>
#include <queue>
using namespace std;

struct CarInfo {
    int length;
    string side;
};

int riverCrossOnOneSide(deque<CarInfo> *queue, long long ferryLength) {
    int carLengthInFerrey = 0;
    int riverCrossCounter = 0;
    while(!queue->empty()) {
        CarInfo popedCar = queue->front();
        carLengthInFerrey = carLengthInFerrey + popedCar.length;
        if(carLengthInFerrey > ferryLength) {
            riverCrossCounter++;
            return riverCrossCounter;
        }
        queue->pop_front();
    }
    riverCrossCounter++;
    return riverCrossCounter;
}

int main() {
    int noTestCases;
    
    deque<CarInfo> leftSideQueue;
    deque<CarInfo> rightSideQueue;
    long long ferryLength = 0;
    int noWaitingCars = 0;
    CarInfo carInfo;
    int riverCrossCounter;
    
    cin>>noTestCases;
    while(noTestCases) {
        cin>>ferryLength;
        ferryLength = ferryLength * 100;
        
        leftSideQueue.clear();
        rightSideQueue.clear();
        riverCrossCounter = 0;
        
        cin>>noWaitingCars;
        
        while(noWaitingCars) {
            cin>>carInfo.length;
            cin>>carInfo.side;
            if(carInfo.side == "left") {
                leftSideQueue.push_back(carInfo);
            }
            else {
                rightSideQueue.push_back(carInfo);
            }
            noWaitingCars--;
        }
        
        while(!leftSideQueue.empty() || !rightSideQueue.empty()) {
            riverCrossCounter = riverCrossCounter + riverCrossOnOneSide(&leftSideQueue, ferryLength);
            if(!leftSideQueue.empty()|| !rightSideQueue.empty()) {
                riverCrossCounter = riverCrossCounter + riverCrossOnOneSide(&rightSideQueue, ferryLength);
            }
        }
        
        cout<<riverCrossCounter<<endl;
        
        noTestCases--;
    }
    
    return 0;
}
