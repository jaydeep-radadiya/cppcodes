#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	int v; // number of vertices
	list<int> *adj;
	Graph(int n) {
		this->v = n;
		this->adj = new list<int>[this->v];
	}

	void add_edge(int u, int v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void dfsHelper(int src, unordered_map<int, bool> &visited) {
		visited[src] = true;
		// cout << src << " ";
		for (auto neighbour : this->adj[src]) {
			if (not visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}

	void dfs(int src) {
		unordered_map<int, bool> visited;
		dfsHelper(src, visited);
	}

	int connectedComponent() {
		unordered_map<int, bool> visited;
		int res = 0;
		for (int i = 0; i < v; i++) {
			if (not visited[i]) {
				dfsHelper(i, visited);
				res++;
			}
		}
		return res;
	}
};

int main() {
	Graph g(6);
	g.add_edge(0, 1);
	g.add_edge(2, 1);
	g.add_edge(3, 2);
	g.add_edge(4, 5);
	cout << g.connectedComponent();

	return 0;
}