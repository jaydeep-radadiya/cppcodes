char flip(char expected) {
    if (expected == '0')
        return '1';
    else if (expected == '1')
        return '0';
}

int startFrom(string str, char expected) {
    int n = str.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != expected)
            cnt++;
        expected = flip(expected);
    }
    return cnt;
}

int makeBeautiful(string str) {
    return min(startFrom(str, '0'), startFrom(str, '1'));
}