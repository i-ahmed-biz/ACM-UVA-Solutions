#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>>graph;
vector<pair<int, int>>ab;
vector<bool>visited;
vector<int> desc;
vector<int> low;
int counter;
void dfsAb(int u, int p) {
	visited[u] = true;
	desc[u] = low[u] = counter++;

	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (v == p) {
			continue;
		}
		if (!visited[v]) {
			dfsAb(v, u);
			if (desc[u] < low[v]) {
				if (u < v) {
					ab.push_back(pair<int, int>(u, v));
				}
				else {
					ab.push_back(pair<int, int>(v, u));
				}
			}
			low[u] = min(low[u], low[v]);
		}
		else {
			low[u] = min(low[u], desc[v]);
		}


	}
}

int main() {
	int n;
	while (1) {
		string str;
		getline(cin, str);
		if (str == "") {
			break;
		}
		stringstream ss(str);
		ss >> n;
		if (n == 0) {
		    getline(cin, str);
			cout << "0 critical links" << endl << endl;
			continue;
		}
		visited.clear();
		visited.resize(n, false);
		desc.clear();
		desc.resize(n);
		low.clear();
		low.resize(n);
		graph.clear();
		counter = 0;
		ab.clear();

		for (int i = 0; i < n; i++) {

			getline(cin, str);
			ss = stringstream(str);
			int u, v, e;
			char ch;
			ss >> u;
			ss >> ch >> e >> ch;
			for (int j = 0; j < e; j++) {
				ss >> v;
				if (graph.count(u) == 0)
				{
					graph[u] = {};
				}
				if (graph.count(v) == 0) {
					graph[v] = {};
				}
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfsAb(i, -1);
			}
		}
		cout << ab.size() << " critical links" << endl;
		sort(ab.begin(), ab.end());
		for (int i = 0; i < ab.size(); i++) {
			cout << ab[i].first << " - " << ab[i].second << endl;
		}
		cout << endl;
		getline(cin, str);
		if (cin.eof()) {
			break;
		}
	}
	return 0;
}
