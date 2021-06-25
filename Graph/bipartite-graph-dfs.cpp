#include<bits/stdc++.h>
using namespace std;

bool bipartiteDFS(vector<list<int>> &graph, int curr, vector<int> &color) {
	if (color[curr] == -1) color[curr] = 1; // when call first time

	for (int neighbour : graph[curr]) {
		if (color[neighbour] == -1) {
			color[neighbour] = 1 - color[curr];
			if (not bipartiteDFS(graph, neighbour, color)) {
				// current component is not bipartite then graph is not
				return false;
			}
		}
		else if (color[neighbour] == color[curr]) {
			return false;
		}
	}
	return true;
}

bool checkBipartite(vector<list<int>> &graph) {
	int n = graph.size();
	vector<int> color(n, -1);
	for (int i = 1; i < n; i++) { // for multiple component
		if (color[i] == -1) {
			if (not bipartiteDFS(graph, i, color)) {
				// single component is not bipartite then graph is not
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