#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;

	vector<pair<int, int>> *adj = new vector<pair<int, int>>[n + 1];

	for (int i = 0; i < e; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}

	return 0;
}