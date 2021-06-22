#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	int v; // number of vertices
	list<int> *adj; // array of linkedlist -> adjacency list
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

	void dfsHelper(int src, unordered_set<int> &visited) {
		visited.insert(src); // mark current node as visited
		// cout << src << " "; // comment for noofcc
		for (int neighbour : adj[src]) {
			if (visited.count(neighbour) == 0) {
				dfsHelper(neighbour, visited);
			}
		}
	}

	void dfs() {
		unordered_set<int> visited;
		for (int i = 0; i < this->v; i++) {
			if (visited.count(i) == 0) {
				dfsHelper(i, visited);
			}
		}
		cout << "\n";
	}

	void bfsHelper(int src, bool *visited) {
		queue<int> q;
		q.push(src);
		visited[src] = true;
		while (not q.empty()) {
			int curr = q.front();
			cout << curr << " ";
			q.pop();
			for (int neighbour : adj[curr]) {
				if (not visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void bfs() {
		bool *visited = new bool[this->v](); // default as false
		for (int i = 0; i < this->v; i++) {
			if (visited[i] == false) {
				bfsHelper(i, visited);
			}
		}
		delete [] visited;
		cout << "\n";
	}

	int noofcc() {
		int cnt = 0;
		unordered_set<int> visited;
		for (int i = 0; i < this->v; i++) {
			if (visited.count(i) == 0) {
				dfsHelper(i, visited);
				cnt++;
			}
		}
		return cnt;
	}
};

int main() {
	int n, e;
	cin >> n >> e;
	Graph g(n);
	while (e--) {
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}
	cout << "dfs traversal : " << "\n";
	g.dfs();
	cout << "bfs traversal : " << "\n";
	g.bfs();
	cout << "connected component : " << "\n";
	cout << g.noofcc();

	return 0;
}