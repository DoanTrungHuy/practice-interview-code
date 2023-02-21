class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // O(n*k)
        unordered_set<string> us;
        int n = s.size();
        for (int i = 0; i < n - k + 1; ++i) {
            us.insert(s.substr(i, k));
        }
        return us.size() == pow(2, k);
    }
};