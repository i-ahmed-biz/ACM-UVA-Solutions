#include <iostream>
#include <cstdlib>

using namespace std;
int compare(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    if(*x < *y) {
        return -1;
    }
    else if(*x > *y) {
        return 1;
    }

    return 0;
}

int main()
{
    int t;
    int i;
    int salary[3];

    cin>>t;
    i = 1;

    while(t--) {
        cin>>salary[0]>>salary[1]>>salary[2];
        qsort(salary, 3, sizeof(int), compare);
        cout<<"Case "<<i<<": "<<salary[1]<<endl;
        i++;
    }

    return 0;
}
