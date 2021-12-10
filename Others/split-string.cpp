#include<bits/stdc++.h>
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<string> split(string s, char ch) {
	istringstream var(s);
	vector<string> arr;
	string temp;
	while (getline(var, temp, ch)) {
		arr.push_back(temp);
	}
	return arr;
}

#define ll long long
#define ld long double
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
#define mid(l,r) (l+(r-l)/2)
#define PI 3.141592653589793

int main() {
	fastIO();

	vector<string> arr = split("my name is jaydeep", 'a');
	for (string s : arr)
		cout << s << "\n";

	return 0;
}