#include <iostream>

using namespace std;

int compare(const void *x, const void *y) {
    int *p = (int*) x;
    int *q = (int*) y;
    int res;
    res = *p - *q;
    
    return res;
}

int bsearch(int x[], int length, int item) {
    int high, low, mid;
    low = 0;
    high = length - 1;
    mid = low + high / 2;
    while(x[mid] != item && low <= high) {
        if(x[mid] < item) {
            low = mid + 1;
        }
        else if(x[mid] > item) {
            high = mid -  1;
        }
        
        mid = (low + high) / 2;
    }
    
    if(x[mid] == item) {
        return mid;
    }
    
    return -1;
}

int checkFirstOccurance(int x[], int index, int item) {
    for(int i = index - 1; i>=0; i--) {
        if(x[i]!= item) {
            return i + 1;
        }
    }
    
    return 0;
}

int main() {
    int N, Q;
    int x[10000];
    int query;
    int caseCounter = 0;
    int index;
    
    
    while(true) {
        cin>>N>>Q;
        
        caseCounter++;
        
        if(N == 0 && Q == 0) {
            break;
        }
        
        for(int i = 0; i < N;i++) {
            cin>>x[i];
        }
        
        qsort(x, N, sizeof(int), compare);
        
        cout<<"CASE# "<<caseCounter<<":"<<endl;
        
        for(int i = 0; i < Q;i++) {
            cin>>query;
            index = bsearch(x,N, query);
            
            if(index!= -1) {
                cout<<query<<" found at "<<(checkFirstOccurance(x, index, query) + 1)<<endl;
            }
            else {
                cout<<query<<" not found"<<endl;
            }
        }
    }
    
    return 0;
}
