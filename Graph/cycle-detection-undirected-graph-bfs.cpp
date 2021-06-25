#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(vector<list<int>> &graph, int i, vector<bool> &visited) {
	queue<pair<int, int>> q; // {current, parent}
	q.push({i, -1});
	visited[i] = true;

	while (not q.empty()) {
		int curr = q.front().first;
		int par = q.front().second;
		q.pop();
		for (int neighbour : graph[curr]) {
			if (not visited[neighbour]) {
				q.push({neighbour, curr});
				visited[neighbour] = true;
			}
			else if (par != neighbour) { // node is visited
				return true; // cycle present
			}
		}
	}
	return false;
}

bool isCycle(vector<list<int>> &graph) {
	int n = graph.size();
	vector<bool> visited(n, false);
	for (int i = 1; i < n; i++) {
		if (not visited[i]) {
			if (checkForCycle(graph, i, visited)) {
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