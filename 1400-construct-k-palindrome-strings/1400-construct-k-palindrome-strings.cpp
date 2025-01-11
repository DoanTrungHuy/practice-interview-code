class Solution {
public:
    bool canConstruct(string s, int k) {
        const int n = s.size();

        if (k > n) {
            return false;
        }

        int cnt[26];

        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }

        int cnt_odd = 0;

        for (int i = 0; i < 26; ++i) {
            cnt_odd += cnt[i] & 1;
        }

        return cnt_odd <= k;
    }
};