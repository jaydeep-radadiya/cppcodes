#include<bits/stdc++.h>
using namespace std;

// T denotes any general types
template<typename T>
class Graph {
public:
	unordered_map<T, unordered_map<T, int>> adj; // weighted graph
	Graph() {
	}

	void add_edge(T u, T v, int wt, bool bidir = true) {
		adj[u][v] = wt; // you have add edge from u - v
		if (bidir) {
			adj[v][u] = wt;
		}
	}

	void print() {
		for (auto row : adj) {
			cout << row.first << " --> ";
			for (auto neighbour : row.second) {
				cout << "(" << neighbour.first << "," << neighbour.second << ")" << " -> ";
			}
			cout << "\n";
		}
	}
};

int main() {
	Graph<string> g;
	g.add_edge("delhi", "mumbai", 350);
	g.add_edge("pune", "thane", 150);
	g.add_edge("delhi", "surat", 320);
	g.add_edge("goa", "chennai", 250);
	g.add_edge("delhi", "goa", 150);
	g.add_edge("pune", "chennai", 180);
	g.add_edge("thane", "delhi", 80);
	g.add_edge("surat", "mumbai", 150);
	g.print();

	return 0;
}