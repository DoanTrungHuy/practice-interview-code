class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        map<char, int> mm;
        int ans = 0;
        
        for (int left = 0, right = 0; right < n; ++right) {
            mm[s[right]]++;
            while (left < n) {
                int max_v = 0;
                for (auto [k, v] : mm) {
                    max_v = max(max_v, v);
                }
                int num_replace = right - left + 1 - max_v;
                if (num_replace > k) {
                    mm[s[left]]--;
                    left++;
                }
                else {
                    ans = max(ans, right - left + 1);
                    break;
                }
            }
        }
        
        return ans;
    }
};