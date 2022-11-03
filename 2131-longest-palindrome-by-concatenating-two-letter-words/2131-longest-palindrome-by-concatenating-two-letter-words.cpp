class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> cnt(26, vector<int>(26, 0));
        int ans = 0;
        for (string word : words) {
            int a = word[0] - 'a';
            int b = word[1] - 'a';
            if (cnt[b][a]) {
                cnt[b][a]--;
                ans += 4;
            } else {
                cnt[a][b]++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i][i]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};