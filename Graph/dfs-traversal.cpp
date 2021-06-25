#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

class Graph {
public:
	int v;
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

	void print() {
		for (int i = 1; i < this->v; i++) {
			cout << i << " --> ";
			for (int ele : adj[i]) {
				cout << ele << ", ";
			}
			cout << "\n";
		}
	}

	void dfsHelper(int src, bool *visited) {
		visited[src] = true;
		cout << src << " ";
		for (int neighbour : adj[src]) {
			if (not visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}

	void dfs() {
		bool *visited = new bool[this->v]();
		for (int i = 1; i < this->v; i++) {
			if (not visited[i]) {
				dfsHelper(i, visited);
			}
		}
	}
};

int main() {
	fastIO();

	int n, e;
	cin >> n >> e;
	Graph g(n + 1);

	while (e--) {
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}

	g.dfs();

	return 0;
}