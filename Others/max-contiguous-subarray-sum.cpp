#include<bits/stdc++.h>
using namespace std;

// tc : O(n^3)
int firstMethod(vector<int> &arr) {
	int n = arr.size();
	int mx_sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int temp = 0;
			for (int k = i; k <= j; k++) {
				temp += arr[k];
			}
			mx_sum = max(mx_sum, temp);
		}
	}
	return mx_sum;
}

// tc : O(n^2)
int secondMethod(vector<int> &arr) {
	int n = arr.size();
	int mx_sum = 0;

	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = i; j < n; j++) {
			temp += arr[j];
			mx_sum = max(mx_sum, temp);
		}
	}
	return mx_sum;
}

// tc : O(n)
int thirdMethod(vector<int> &arr) {
	int n = arr.size();
	int mx_sum = 0;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		temp = max(arr[i], temp + arr[i]);
		mx_sum = max(mx_sum, temp);
	}
	return mx_sum;
}

int main() {
	vector<int> arr { -2, 1, -3, 4, -1, 2, 1, -5, 4};

	cout << firstMethod(arr) << "\n";
	cout << secondMethod(arr) << "\n";
	cout << thirdMethod(arr) << "\n";

	return 0;
}