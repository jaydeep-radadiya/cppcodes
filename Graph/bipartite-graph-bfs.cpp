#include<bits/stdc++.h>
using namespace std;

bool bipartiteBFS(vector<list<int>> &graph, int i, vector<int> &color) {
	queue<int> q;
	q.push(i);
	color[i] = 1;

	while (not q.empty()) {
		int curr = q.front();
		q.pop();
		for (int neighbour : graph[curr]) {
			if (color[neighbour] == -1) {
				q.push(neighbour);
				color[neighbour] = 1 - color[curr];
			}
			else if (color[neighbour] == color[curr]) {
				return false;
			}
		}
	}
	return true;
}

bool checkBipartite(vector<list<int>> &graph) {
	int n = graph.size();
	vector<int> color(n, -1); // same as visited array
	for (int i = 1; i < n; i++) { // for all component
		if (color[i] == -1) { // if -1 then not visited
			// any component is not bipartite then graph is not
			if (not bipartiteBFS(graph, i, color)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<list<int>> graph(n + 1);

	while (e--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (checkBipartite(graph))
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";

	return 0;
}