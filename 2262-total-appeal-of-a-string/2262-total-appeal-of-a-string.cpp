class Solution {
public:
    long long appealSum(string s) {
        // a: 1
        // ab, b: 2, 1
        // abb, bb, b:  2, 1, 1
        // abbc, bbc, bc, c:  3, 2, 2, 1
        
        const int n = s.size();
        int prev[26] = {};
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans += (i + 1 - prev[s[i] - 'a']) * (n - (i + 1)) + (i + 1 - prev[s[i] - 'a']);
            prev[s[i] - 'a'] = i + 1;
        }
        
        return ans;
    }
};