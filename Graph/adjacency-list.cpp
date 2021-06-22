#include<bits/stdc++.h>
using namespace std;

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
		for (int i = 0; i < this->v; i++) {
			cout << i << " --> ";
			for (auto ele : adj[i]) {
				cout << ele << ", ";
			}
			cout << "\n";
		}
	}
};

int main() {
	Graph g(4);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(0, 3);
	g.add_edge(1, 3);
	g.add_edge(2, 3);
	g.print();

	return 0;
}