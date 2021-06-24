#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;

	// declare adjacency matrix
	int arr[n + 1][n + 1];

	// take edges as input
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	return 0;
}