#include<bits/stdc++.h>
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int ternarySearch(vector<int> &arr, int val) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;

		if (arr[mid1] == val) return mid1;
		if (arr[mid2] == val) return mid2;
		if (val < arr[mid1]) right = mid1 - 1;
		else if (val > arr[mid2]) left = mid2 + 1;
		else {
			left = mid1 + 1;
			right = right - 1;
		}
	}
	return -1;
}

int main() {
	fastIO();

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int val;
	cin >> val;
	cout << ternarySearch(arr, val);

	return 0;
}