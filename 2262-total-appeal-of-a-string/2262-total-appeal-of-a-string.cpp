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
        int total_substr = 0;
        
        for (int i = 0; i < n; ++i) {
            total_substr += i + 1 - last[s[i] - 'a'];
            last[s[i] - 'a'] = i + 1;
            ans += total_substr;
        }
        
        return ans;
    }
};