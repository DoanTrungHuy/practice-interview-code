class Solution {
public:
    long long appealSum(string s) {
        // a : 1
        // ab, b : 2, 1
        // abb, bb, b:  2, 1, 1
        // abbc, bbc, bc, c:  3, 2, 2, 1
        
        const int n = s.size();
        int last[26] = {};
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i + 1;
            for (int c = 0; c < 26; ++c) {
                ans += last[c];
            }
        }
        
        return ans;
    }
};