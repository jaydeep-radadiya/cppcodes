#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(vector<list<int>> &graph, int curr, int par, vector<bool> &visited) {
	visited[curr] = true;
	for (int neighbour : graph[curr]) {
		if (not visited[neighbour]) {
			if (checkForCycle(graph, neighbour, curr, visited)) {
				// remember this
				return true;
			}
		}
		else if (neighbour != par) { // already visited
			return true;
		}
	}
	return false;
}

bool isCycle(vector<list<int>> &graph) {
	int n = graph.size();
	vector<bool> visited(n, false);
	for (int i = 1; i < n; i++) {
		if (not visited[i]) {
			if (checkForCycle(graph, i, -1, visited)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<list<int>> graph(n + 1);

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << isCycle(graph);

	return 0;
}