#include<bits/stdc++.h>
using namespace std;

double f(double x) {
	return 12 * x - 26 - x * x;
}

double naive() {
	double mx = 0.0;
	for (double i = 4; i <= 9; i += 1e-7) {
		mx = max(mx, f(i));
	}
	return mx;
}

double maxPoint(double left, double right) {
	while ((right - left) > 1e-8) {
		double m1 = left + (right - left) / 3;
		double m2 = right - (right - left) / 3;
		double f1 = f(m1);
		double f2 = f(m2);

		if (f1 < f2)
			left = m1;
		else
			right = m2;
	}
	return f(left);
}

double iterative(double left, double right) {
	for (int i = 0; i < 43; i++) {
		double m1 = left + (right - left) / 3;
		double m2 = right - (right - left) / 3;
		double f1 = f(m1);
		double f2 = f(m2);

		if (f1 < f2)
			left = m1;
		else
			right = m2;
	}
	return f(left);
}

int main() {
	cout << naive() << "\n";
	cout << maxPoint(4, 9) << "\n";
	cout << iterative(4, 9) << "\n";

	return 0;
}