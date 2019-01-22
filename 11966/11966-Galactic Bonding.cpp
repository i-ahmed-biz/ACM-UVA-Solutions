#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int nodes[1000];
int childCount[1000];
int noNodes = 0;

int root(int srcNode)
{
    int root = srcNode;
    while(nodes[root] != root)
    {
        root = nodes[root];
    }

    return root;
}

void initNodes(int maxNodes)
{
    for(int i = 0; i < maxNodes; i++) {
        nodes[i] = i;
        childCount[i] = 1;
    }

}
int doUnion(int src, int dest)
{
    int x = root(src);
    int y = root(dest);

    if(x != y) {
        if(childCount[x] < childCount[y]) {
        	childCount[y] = childCount[x] + childCount[y];
            nodes[x] = y;
        }
        else {
        	childCount[x] = childCount[y] + childCount[x];
            nodes[y] = x;
        }
        return -1;
    }

    return 0;
}

float calcDistance(float x1, float y1, float x2, float y2) {
    float xDist = (x2-x1) * (x2-x1);
    float yDist = (y2-y1) * (y2-y1);
    return sqrt(xDist + yDist);
}

int main()
{

    int noDataSets = 0;
    int dataSetsCount = 0;
    int noConstlation = 0;
    float distance;
    float x[1000];
    float y[1000];
    int i;
    int j;
    cin>>noDataSets;

    while(dataSetsCount < noDataSets) {
        cin>>noNodes>>distance;
        initNodes(noNodes);
        noConstlation = noNodes;

        for(i = 0; i < noNodes;i++)
        {
            cin>>x[i]>>y[i];
        }
        for(i = 0; i < noNodes;i++)
        {
            for(j = 0; j < noNodes;j++) {
                if(distance >= calcDistance(x[i], y[i], x[j], y[j])) {
                    noConstlation = noConstlation + doUnion(i, j);
                }
            }
        }

        cout<<"Case "<<(dataSetsCount + 1)<<": "<<noConstlation<<endl;
        dataSetsCount++;
    }

    return 0;
}
