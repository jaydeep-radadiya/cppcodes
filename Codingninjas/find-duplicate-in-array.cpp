/*
1. sort array and compare adjacents
2. using hashing (set ot map)
3. modifying array (negation of values)
4. slow and fast pointer
*/

int findDuplicate(vector<int> &arr, int n) {
    unordered_set<int> ss;
    for (auto ele : arr) {
        int bs = ss.size();
        ss.insert(ele);
        int as = ss.size();
        if (bs == as) {
            return ele;
        }
    }
}