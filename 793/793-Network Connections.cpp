#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
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
void doUnion(int src, int dest)
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
    }

}
int main()
{

    int noDataSets = 0;
    int dataSetsCount = 0;
    string inputedLine;
    int src;
    int dest;
    int successful;
    int unSuccessful;
    char command = 0;

    cin>>noDataSets;
    std::getline(cin, inputedLine);
    std::getline(cin, inputedLine);

    while(dataSetsCount < noDataSets) {
        std::getline(cin, inputedLine);
        sscanf(inputedLine.c_str(), "%d", &noNodes);
        initNodes(noNodes);
        successful = 0;
        unSuccessful = 0;

        while(1)
        {
            std::getline(cin, inputedLine);

            if(inputedLine == "")
            {
                break;
            }

            sscanf(inputedLine.c_str(),"%c %d %d", &command, &src, &dest);

            if(command == 'c') {
               doUnion(src - 1, dest - 1);
            }
            else if(root(src - 1) == root(dest - 1)){
                successful++;
            }
            else {
                unSuccessful++;
            }

        }

        cout<<successful<<","<<unSuccessful<<endl;

        if(dataSetsCount < noDataSets - 1) {
            cout<<endl;
        }
        dataSetsCount++;
    }

    return 0;
}

