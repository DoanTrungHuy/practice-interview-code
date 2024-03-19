class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[256];
        memset(cnt, 0, sizeof cnt);
        int max_freq = 0;
        
        for (char c : tasks) {
            cnt[c]++;
            max_freq = max(max_freq, cnt[c]);
        }
        
        int ans = (max_freq - 1) * (n + 1);
        
        for (char c : tasks) {
            if (cnt[c] == max_freq) {
                ans++;
                cnt[c] = -1;
            }
        }
        
        return max(ans, (int)tasks.size());
    }
};