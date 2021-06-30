#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// never make mistake in max() & min()
double f(double T, vi &d, vi &s) {
	double mn = 1e18;
	double mx = 0.0;
	for (int i = 0; i < d.size(); i++) {
		double dist = s[i] * T + d[i];
		mx = max(mx, dist);
		mn = min(mn, dist);
	}
	return mx - mn;
}

double race(vi &d, vi &s, int k) {
	double left = 0;
	double right = k;

	for (int i = 0; i < 200; i++) {
		double m1 = left + (right - left) / 3.0;
		double m2 = right - (right - left) / 3.0;
		double val1 = f(m1, d, s);
		double val2 = f(m2, d, s);

		if (val1 > val2)
			left = m1;
		else
			right = m2;
	}
	return f(left, d, s);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> s(n), d(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> d[i];
	}

	cout << fixed << setprecision(6) << race(d, s, k);

	return 0;
}