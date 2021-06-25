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
		bool *visited = new bool[this->v]();
		for (int i = 1; i < this->v; i++) {
			if (not visited[i]) {
				bfsHelper(i, visited);
			}
		}
		delete [] visited;
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

	g.bfs();

	return 0;
}