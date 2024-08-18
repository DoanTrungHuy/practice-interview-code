class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        const int n = s.size();
        int ans = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        
        for (int l = 0, r = 0; r < n; ++r) {
            cnt0 += s[r] == '0';
            cnt1 += s[r] == '1';
            while (cnt0 > k && cnt1 > k) {
                cnt0 -= s[l] == '0';
                cnt1 -= s[l] == '1';
                l++;
            }
            ans += r - l + 1;
        }
        
        return ans;
    }
};