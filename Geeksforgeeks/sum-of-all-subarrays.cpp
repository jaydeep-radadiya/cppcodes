#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll firstMethod(vector<int> &arr, int n) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int total = 0;
		for (int j = i; j < n; j++) {
			total += arr[j];
			sum += total;
		}
	}
	return sum;
}

ll secondMethod(vector<int> &arr, int n) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i] * ((n - i) * (i + 1));
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << firstMethod(arr, n) << "\n";
	cout << secondMethod(arr, n) << "\n";

	return 0;
}