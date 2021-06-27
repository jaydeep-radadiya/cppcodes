#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void add_edge(int u, int v, bool bidir = true) {
	graph[u].push_back(v);
	if (bidir == true) {
		graph[v].push_back(u);
	}
}

// single source shortest path
vector<int> sssp(int src, int dest, int n) {
	vector<bool> visited(n, false);
	vector<int> parent(n, -1); // shortest path from source to all vertex
	vector<int> dist(n, 0);
	queue<int> q;

	q.push(src);
	visited[src] = true;
	while (not q.empty()) {
		int curr = q.front();
		q.pop();
		for (int neighbour : graph[curr]) {
			if (not visited[neighbour]) {
				q.push(neighbour);
				visited[neighbour] = true;
				parent[neighbour] = curr;
				dist[neighbour] = dist[curr] + 1;
			}
		}
	}

	int temp = dest;
	vector<int> result;
	while (temp != -1) {
		result.push_back(temp);
		temp = parent[temp];
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	graph.reserve(7);
	add_edge(0, 1);
	add_edge(1, 2);
	add_edge(0, 3);
	add_edge(2, 3);
	add_edge(3, 4);
	add_edge(4, 5);
	add_edge(4, 6);
	add_edge(5, 6);
	add_edge(0, 6);

	vector<int> sp = sssp(0, 5, 7);
	for (int ele : sp)
		cout << ele << " ";

	return 0;
}