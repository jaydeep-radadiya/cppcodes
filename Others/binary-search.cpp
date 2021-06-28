#include<bits/stdc++.h>
using namespace std;

// for expanding file
// g++ binary-search.cpp -E > testing.cpp

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int binarySearch(int *arr, int n, int val) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == val)
			return mid;
		else if (arr[mid] > val)
			right = mid - 1;
		else if (arr[mid] < val)
			left = mid + 1;
	}
	return -1;
}

int binarySearchOnSortedRotated(int *arr, int n, int val) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == val)
			return mid;
		else if (arr[left] <= arr[mid]) {
			if (val >= arr[left] and val <= arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else if (arr[mid] <= arr[right]) {
			if (val >= arr[mid] and val <= arr[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}

int intsqrt(int n) {
	int left = 1;
	int right = n - 1;
	int res = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (mid * mid == n)
			return mid;
		else if (mid * mid > n)
			right = mid - 1;
		else if (mid * mid < n) {
			res = mid;
			left = mid + 1;
		}
	}
	return res;
}

int main() {
	fastIO();

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int val;
	cin >> val;
	// cout<<binarySearch(arr,n,val);
	cout << binarySearchOnSortedRotated(arr, n, val);

	// int n = 105;
	// cout<<intsqrt(n);

	return 0;
}