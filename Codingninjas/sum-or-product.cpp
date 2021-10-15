long long sumOrProduct(long long n, long long q) {
    long long mod = 1e9 + 7;

    if (q == 1) {
        long long ans = (n * (n + 1) / 2) % mod;
        return ans;
    }
    else {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }
}