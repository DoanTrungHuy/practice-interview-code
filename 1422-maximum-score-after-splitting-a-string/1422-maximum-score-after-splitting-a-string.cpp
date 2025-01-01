class Solution {
public:
    int maxScore(string s) {
        const int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - (i + 1); ++j) {
                string left = s.substr(j, i + 1), right = s.substr(j + i + 1);
                int total = 0;
                for (char c : left) {
                    total += c == '0';
                }
                for (char c : right) {
                    total += c == '1';
                }
                ans = max(ans, total);
            }
        }

        return ans;
    }
};