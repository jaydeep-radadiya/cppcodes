#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr) {
	int n = arr.size();
	int idx_mjr = 0; // idx of major ele
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[idx_mjr])
			cnt++;
		else
			cnt--;

		if (cnt == 0) {
			idx_mjr = i;
			cnt = 1;
		}
	}

	if (count(arr.begin(), arr.end(), arr[idx_mjr]) > n / 2)
		return arr[idx_mjr];
	else
		return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << majorityElement(arr) << "\n";

	return 0;
}