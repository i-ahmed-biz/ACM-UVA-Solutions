#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;
set<int>ap;
int currentTime;

void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<int>& desc, vector<int>& low, int u, int parent) {
    visited[u] = true;
    low[u] = currentTime;
    desc[u] = currentTime++;
    bool isArtq = false;
    int children = 0;
    for (unsigned int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v == parent) {
            continue;
        }
        if (!visited[v]) {
            dfs(graph, visited, desc, low, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > desc[u] && parent != -1) {
                isArtq = true;
            }
            children++;
        }
        else {
            low[u] = min(low[u], desc[v]);
        }
    }

    if (parent == -1 && children > 1) {
        ap.insert(u);
    }
    else if (isArtq) {
        ap.insert(u);
    }
}
int main()
{

    while (1) {
        string str;
        int n;
        getline(cin, str);
        stringstream ss(str);
        ss >> n;
        if (n == 0) {
            break;
        }
        int u, v;
        unordered_map<int, vector<int>>graph;
        while (1) {
            getline(cin, str);
            if (str == "0") {
                break;
            }
            ss = stringstream(str);
            ss >> u;
            if (u == 0) {
                break;
            }


            if (graph.count(u) < 0) {
                graph[u] = {};
            }
            while(ss >> v) {
                if (v == 0) {
                    break;
                }
                if (graph.count(v) < 0) {
                    graph[v] = {};
                }
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        ap.clear();
        for (unordered_map<int, vector<int>>::iterator it = graph.begin(); it != graph.end(); it++) {
            vector<int> desc(n + 1);
            vector<int> low(n + 1);
            vector<bool> visited(n + 1, false);

            currentTime = 0;
            dfs(graph, visited, desc, low, it->first, -1);
        }

        cout << ap.size() << endl;
    }
}

