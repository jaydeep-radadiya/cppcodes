#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793

double f(double b, double c, double x) {
	return (x * x + b * x + c) / sin(x);
}

double findMin(double b, double c) {
	double left = 0.0;
	double right = (PI / 2);

	for (int i = 0; i < 100 && left < right; i++) {
		double mid1 = left + (right - left) / 3;
		double mid2 = right - (right - left) / 3;
		double val1 = f(b, c, mid1);
		double val2 = f(b, c, mid2);

		if (val1 < val2)
			right = mid2;
		else
			left = mid1;
	}
	return f(b, c, left);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		double b, c;
		cin >> b >> c;
		cout << fixed << setprecision(10) << findMin(b, c) << "\n";
	}

	return 0;
}