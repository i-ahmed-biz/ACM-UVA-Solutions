
#include <iostream>
#include <tuple>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
int rep[100];
int find(int x) {
    if (x == rep[x]) {
        return x;
    }
    return rep[x] = find(rep[x]);
}
void unionFn(int x, int y) {
    int a = find(x);
    int b = find(y);
    rep[a] = b;
}

bool myLess(pair<int, pair<int, int>> &a, pair<int, pair<int, int>>&b) {
    return a.first < b.first;
}

int main()
{
    int T, M, N;
    int u, v, w;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i <= N; i++) {
            rep[i] = i;
        }
        cin >> M;

        vector<pair<int, pair<int, int>>> edges(M);
        vector<int> usedEdgesIdx(M + 1);


        for (int i = 0; i < M; i++) {
            cin >> u >> v >> w;
            edges[i] = make_pair(w, pair<int, int>(u, v));
        }
        sort(edges.begin(), edges.end(), myLess);
        int cost = 0;
        int usedEdges = 0;
        int i = 0;
        while (usedEdges < N - 1 && i < M) {
            pair<int, pair<int, int>> currEdge = edges[i];

            if (find(currEdge.second.first) != find(currEdge.second.second)) {
                unionFn(currEdge.second.first, currEdge.second.second);
                cost += currEdge.first;
                usedEdgesIdx[usedEdges] = i;
                usedEdges++;
            }
            i++;
        }
        cout << cost <<" ";
        int firstCost = cost;
        int edgeCount = usedEdges;
        int secondMin = INT_MAX;
        for (int j = 0; j < edgeCount; j++) {
            cost = 0;
            usedEdges = 0;
            for (i = 0; i <= N; i++) {
                rep[i] = i;
            }
            i = 0;
            while (usedEdges < N - 1 && i < M) {
                pair<int, pair<int, int>> currEdge = edges[i];
                if (usedEdgesIdx[j] != i)
                if(find(currEdge.second.first) != find(currEdge.second.second)) {
                    unionFn(currEdge.second.first, currEdge.second.second);
                    cost += currEdge.first;
                    usedEdges++;
                }
                i++;
            }
            if (usedEdges == N - 1) {
                secondMin = min(secondMin, cost);
            }

        }

        cout << secondMin << endl;
    }

    return 0;
}

