#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

int nodes[26];
int childCount[26];
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

void initNodes()
{
    for (int i = 0; i < noNodes; i++)
    {
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
    char src;
    char dest;
    int answer;

    cin>>noDataSets;
    std::getline(cin, inputedLine);
    std::getline(cin, inputedLine);

    while(dataSetsCount < noDataSets) {
        std::getline(cin, inputedLine);
        noNodes = inputedLine.c_str()[0] - 'A' + 1;
        initNodes();
        answer = 0;
        while(1)
        {
            std::getline(cin, inputedLine);
            if(inputedLine == "")
            {
                break;
            }
            src = inputedLine.c_str()[0] - 'A';
            dest = inputedLine.c_str()[1] - 'A';
            doUnion(src, dest);
        }

        for(int i = 0; i < noNodes; i++) {
            if(root(i) == i)
            {
                answer++;
            }
        }

        cout<<answer<<endl;

        if(dataSetsCount < noDataSets - 1) {
            cout<<endl;
        }

        dataSetsCount++;
    }

    return 0;
}

